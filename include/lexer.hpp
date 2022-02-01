#pragma once

#include "lexeme.hpp"
#include "lexer_rules.hpp"
#include "reader.hpp"

#include <map>
#include <regex>
#include <string>
#include <tuple>
#include <vector>

class lexer {
  public:
   using Span = std::tuple<int, int>;  // how long does the match span for
   using FilePositions =
       std::vector<std::tuple<int, int, int>>;  // where in the file are the
                                                // tokens

   lexer(lexerRules, sourceFile);

   Span span(std::string, std::regex, int*);

   void processFile();
   void processLine(int, std::string);

   std::vector<lexeme> getTokens();
   std::vector<lexeme> sortLexemes();

  private:
   lexerRules rules;
   sourceFile ingestedFile;
   std::vector<lexeme> tokens;
};

