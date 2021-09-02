#include "regex.hh"

using namespace CompilerVm;

void Regex::expandRegex(Result& r) {
	if (_regexDef.size() == 0) {
		r.succeed();
		return;
	}
    bool subFlag = false;
	std::vector<std::string> regexTmp;
	for (std::string expr: _regexes) {
		auto spos = expr.find('{');
		while (spos != expr.npos) {
			auto epos = expr.find('}', spos + 1);
			if (epos == expr.npos) {
				r.error("B002", fmt::format("{}, regex: {}, spos: {}, epos: {}",
					Errors::errorMap["B002"], expr, spos, epos));
				return;
			}
			std::string name = expr.substr(spos + 1, epos - spos - 1);
			name = StrUtil::trim(name);
			std::string token = _regexDef.getRegexDef(name, r);
			if (r.isFailed()) {
				return;
			}
			expr = expr.replace(spos, epos - spos + 1, token);
			spos = expr.find(spos, '{');
            subFlag = true;
		}
		regexTmp.emplace_back(expr);
	}
	_regexes.swap(regexTmp);
    if (subFlag) {
        // recursive substitution
        expandRegex(r);
    }
}