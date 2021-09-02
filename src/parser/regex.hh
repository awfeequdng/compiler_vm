#pragma once

#include "regex_def.hh"
#include "errors.hh"
#include "strutil.hh"

#include <fmt/format.h>
#include <vector>
#include <string>

namespace CompilerVm
{
    enum class RegexToken {
        REGEX_EOT,          // 正则表达式末尾
    	REGEX_DOT,          // . 通配符
    	REGEX_CARET,        // ^ 开头匹配符
    	REGEX_DOLLAR,       // $ 末尾匹配符
    	REGEX_LBRACKET,     // 字符集类结尾括号 [
    	REGEX_RBRACKET,     // 字符集类开始括号 ]
    	REGEX_LCURLY,       // {
    	REGEX_RCURLY,       // }
    	REGEX_LPAREN,       // (
    	REGEX_RPAREN,       // (
    	REGEX_STAR,         // *
    	REGEX_DASH,         // -
    	REGEX_EOI,          // 输入流结束
    	REGEX_LITERAL,      // 字符常量
    	REGEX_OPTIONAL,     // ?
    	REGEX_OR,           // |
    	REGEX_PLUS          // +
    };
	class Regex {
	public:
		Regex() {}
		Regex(const RegexDef& def): _regexDef{def} {}

		void setRegexDef(const RegexDef& def) {
			_regexDef = def;
		}

		void addRegex(std::string expr) {
			_regexes.emplace_back(expr);
		}

		size_t regexSize() const {
			return _regexes.size();
		}

		// 正则表达式中有定义的内容，此时将定义展开
		void expandRegex(Result& r) {
			if (_regexDef.size() == 0) {
				r.succeed();
				return;
			}
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
				}
				regexTmp.emplace_back(expr);
			}
			_regexes.swap(regexTmp);
		}

		const std::vector<std::string>& getRegex() const {
			return _regexes;
		}
	private:
		RegexDef _regexDef;
		std::vector<std::string> _regexes;
	};
}