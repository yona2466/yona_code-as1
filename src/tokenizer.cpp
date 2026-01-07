    ArithmeticTokenizer tokenizer(expression);
    std::vector<Token> tokens = tokenizer.tokenize();
    
    std::cout << "Expression: " << expression << "\n";
    std::cout << "Tokens:\n";
    
    for (const Token& token : tokens) {
        std::cout << "Type: ";
        switch(token.type) {
            case INTEGER: std::cout << "INTEGER"; break;
            case PLUS: std::cout << "PLUS"; break;
            case MULTIPLY: std::cout << "MULTIPLY"; break;
            case END: std::cout << "END"; break;
            default: std::cout << "INVALID";
        }
        if (!token.value.empty() && token.type != END) {
            std::cout << ", Value: " << token.value;
        }
        std::cout << "\n";
    }
    
    return 0;
}
