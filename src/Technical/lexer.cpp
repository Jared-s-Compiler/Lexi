#include "../../include/Technical/lexer.hpp"
#include "../../include/Technical/reader.hpp"

#include "../../include/Domain/lexeme.hpp"
#include "../../include/Domain/lexer_rules.hpp"

#include <ctype.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <map>
#include <regex>
#include <set>
#include <string>
#include <tuple>

lexer::lexer(lexerRules lexRules, sourceFile inputFile) {
  this->rules = lexRules;
  this->ingestedFile = inputFile;
}

void lexer::processLine(int lineno, std::string line) {
  if (std::all_of(std::begin(line), std::end(line), isspace) || line.empty()) {
    return;
  }

  std::vector<std::string> reserved = this->rules.getReservedWords();

  for (const auto& [identifier, _regex] : this->rules) {
    // bool can_break_immediate = false;
    for (auto it = std::sregex_iterator(line.begin(), line.end(), _regex);
         it != std::sregex_iterator(); it++) {

      std::smatch sm = *it;

      size_t start = sm.position(0);
      size_t end = start + sm.length(1);

      std::string match_string = sm.str(1);

      std::tuple<int, int, int> coordinates =
          std::make_tuple(lineno, start, end);

      bool _found_reserved = std::binary_search(
          std::begin(reserved), std::end(reserved), match_string);

      lexeme element = lexeme(coordinates, match_string,
                              _found_reserved ? "KEYWORD" : identifier);

      if (std::find(std::begin(this->tokens), std::end(this->tokens),
                    element) == std::end(this->tokens) &&
          start != end) {
        this->tokens.push_back(element);
      }

      if (end <= line.size() && identifier == "COMMENT") {
        // Comment leftovers, remove if this is the case
        line.erase(start, end);
      }
    }
  }
}

void lexer::processFile() {
  int i = 0;
  for (std::string line : this->ingestedFile) {
    this->processLine(i++, line);
  }
  std::sort(std::begin(this->tokens), std::end(this->tokens));
}

std::vector<lexeme> lexer::getTokens() {
  return this->tokens;
}

