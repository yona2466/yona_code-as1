# Compiler Design Assignment 1

Student: [yonas birhanie]
Student ID: [1508354]
Course: COMP 202
Date: [29/04/2018]

## Question 1: Define Left Recursion

Left recursion happens when a grammar rule can derive a string that starts with the same symbol.

Types:
1. Direct: A → Aα | β
2. Indirect: A → Bα, B → Aβ

Why it's problematic:
1. Causes infinite loops in top-down parsers
2. Cannot build LL(1) parsing tables
3. Must be eliminated before parsing

Example:
Original: E → E + T | T
After elimination: E → T E', E' → + T E' | ε

## Question 2: C++ Tokenizer Program


File: src/tokenizer.cpp

#include <iostream>

#include <string>

#include <vector>

#include <cctype>

enum TokenType { INTEGER, PLUS, MULTIPLY, END, INVALID };


struct Token {
TokenType type;
std::string value;
};

class Tokenizer {
private:
std::string input;
size_t pos = 0;
char current()
{ return pos < input.size() ? input[pos] : '\0'; }

void advance() { if (pos < input.size()) pos++; }
public:

Tokenizer(const std::string& s) : input(s) 
{}
std::vector<Token> tokenize()
{
    std::vector<Token> tokens;
 
    
    while (current() != '\0') {
    
        if (isspace(current())) { advance(); continue; }
        
        if (isdigit(current()))
        {
            std::string num;
            while (isdigit(current())) {
                num += current();
                advance();
            }
            tokens.push_back({INTEGER, num});
        }
        else if (current() == '+') {
            tokens.push_back({PLUS, "+"});
            advance();
        }
        else if (current() == '*') {
            tokens.push_back({MULTIPLY, "*"});
            advance();
        }
        else {
            tokens.push_back({INVALID, std::string(1, current())});
            advance();
        }
    }
    
    tokens.push_back({END, ""});
    return tokens;
}
};

int main() {
Tokenizer t("123 + 45 * 6");
auto tokens = t.tokenize();
for (const auto& tok : tokens) {
    std::cout << "Token: ";
    switch(tok.type)
    {
        case INTEGER: std::cout << "INTEGER"; break;
        case PLUS: std::cout << "PLUS"; break;
        case MULTIPLY: std::cout << "MULTIPLY"; break;
        case END: std::cout << "END"; break;
        default: std::cout << "INVALID";
    }
    if (!tok.value.empty() && tok.type != END)
        std::cout << " (" << tok.value << ")";
    std::cout << "\n";
}
return 0;
}

## Question 3: Parse Tree Construction

Grammar:
S → AB
A → aA | ε
B → bB | b

For string: "aab"

Derivation:
S ⇒ AB
  ⇒ aAB
  ⇒ aaAB  
  ⇒ aaεB
  ⇒ aaB
  ⇒ aab

Parse tree:

        S
       / \
      A   B
     /|   |
    a A   b
     /|
    a A
       \
        ε

Explanation:
1. S expands to AB
2. A produces "aa" then ends with ε
3. B produces single "b"
4. Final string: "aab"

## Summary

This assignment covers:
1. Theory of left recursion in parsing
2. C++ implementation of arithmetic tokenizer
3. Parse tree construction for given grammar


