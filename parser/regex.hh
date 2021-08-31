#pragma once

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

}