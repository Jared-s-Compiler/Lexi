#include <iostream>

#include "../include/Technical/lexer.hpp"
#include "../include/Technical/reader.hpp"

int main() {
  std::cout << "hey mom!" << std::endl;
  sourceFile source = sourceFile("inputs/comment_space.txt");
  std::map<std::string, std::regex> tokenMap = {
      {"COMMENT", std::regex("(\\!.*\\!)")},
      {"IDENTIFIER", std::regex("([a-zA-Z]+(\\d*)?)")},
      {"NUMBER", std::regex("(?:\\b)([-+]?\\d*\\.?\\d+)?(?=\\b)")},
      {"OPERATORS",
       std::regex("(\\+|-|\\*|\\/|=|>|<|>=|<=|&+|\\|+|%|^!$|\\^)")},
      {"SEPARATORS", std::regex("(\\(|\\)|\\{|\\}|\\[|\\]|\"|\'|\\,)")},
      {"TERMINATORS", std::regex("(\\;|\\$)")}};

  lexer lex = lexer(tokenMap, source);
  lex.processFile();
  std::vector<lexeme> tokens = lex.getTokens();
  for(lexeme element : tokens) {
    std::cout << element << std::endl;
  }
  return 0;
}
