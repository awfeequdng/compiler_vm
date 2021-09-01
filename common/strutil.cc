#include "strutil.hh"
#include <sstream>

using namespace std;

namespace CompilerVm
{
    vector<string> StrUtil::split(string str, char delimiter) {
        stringstream ss(str);
        vector<string> result;
        string token;
        while (getline(ss, token, delimiter)) {
            if (token != "") {
                result.emplace_back(token);
            }
        }
        return result;
    }

    string StrUtil::trim(string str) {
        if (str.empty()) return str;

        string whitespace = "\t ";
        for (auto c: whitespace) {
            str.erase(0, str.find_first_not_of(c));
            str.erase(str.find_last_not_of(c) + 1);
        }
        return str;
    }
} // namespace CompilerVm
