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

} // namespace CompilerVm
