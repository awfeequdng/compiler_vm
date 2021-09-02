#pragma once
#include "regex.hh"
#include <string>

namespace CompilerVm
{
    class Lexer {
    public:
        Lexer() {
            initRegexMap();
        }

        bool matchRegexToken(RegexToken& t) const {
            return _curRegToken == t;
        }

        int lexeme() const {
            return _lexeme;
        }

        std::string expr() const {
            return _expr;
        }

        RegexToken next() {

        }
    protected:
        void initRegexMap() {
            for (int i = 0; i < ASCII_COUNT; i++) {
                _regTokenMap[i] = RegexToken::REGEX_LITERAL;
            }
            _regTokenMap['.'] = RegexToken::REGEX_DOT;
            _regTokenMap['^'] = RegexToken::REGEX_CARET;
            _regTokenMap['$'] = RegexToken::REGEX_DOLLAR;
            _regTokenMap['('] = RegexToken::REGEX_LPAREN;
            _regTokenMap[')'] = RegexToken::REGEX_RPAREN;
            _regTokenMap['['] = RegexToken::REGEX_LBRACKET;
            _regTokenMap[']'] = RegexToken::REGEX_RBRACKET;
            _regTokenMap['{'] = RegexToken::REGEX_LCURLY;
            _regTokenMap['}'] = RegexToken::REGEX_RCURLY;
            _regTokenMap['*'] = RegexToken::REGEX_STAR;
            _regTokenMap['-'] = RegexToken::REGEX_DASH;
            _regTokenMap['?'] = RegexToken::REGEX_OPTIONAL;
            _regTokenMap['|'] = RegexToken::REGEX_OR;
            _regTokenMap['+'] = RegexToken::REGEX_PLUS;
        }

    private:
        static const int ASCII_COUNT = 128;
        RegexToken _regTokenMap[ASCII_COUNT];
        RegexToken _curRegToken = RegexToken::REGEX_EOT;
        bool _inQuote = false;  // 在双引号中
        bool _esc = false;      // 遇见转义符 '\'
        std::string _expr;      // 当前表达式
        int _index = 0;         // 当前索引字母在表达式中的下标
        int _lexeme;
    };
} // namespace CompilerVm
