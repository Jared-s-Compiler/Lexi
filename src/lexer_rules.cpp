#include "../include/lexer_rules.hpp"
#include <map>
#include <regex>
#include <string>

lexerRules::lexerRules(std::map<std::string, std::regex> token) {
  /*
   * Default constructor for lexerRules
   */

  this->rules = token;
  this->reservedWords = {"and",     "bool",   "do",    "do end", "else",
                         "end",     "end if", "false", "float",  "for",
                         "for end", "input",  "int",   "not",    "or",
                         "output",  "then",   "true",  "while",  "while end"};
}

lexerRules::lexerRules() {
  this->reservedWords = {"and",     "bool",   "do",    "do end", "else",
                         "end",     "end if", "false", "float",  "for",
                         "for end", "input",  "int",   "not",    "or",
                         "output",  "then",   "true",  "while",  "while end"};
}

lexerRules::lexerRules(const lexerRules& rhs) {
  /*
   * Copy constructor for lexerRules
   */

  this->rules = rhs.rules;
}

lexerRules& lexerRules::operator=(const lexerRules& rhs) {
  /*
   * Copy constructor for lexerRules
   */

  if (this != &rhs) {
    this->rules = rhs.rules;
  }

  return *this;
}

std::map<std::string, std::regex> lexerRules::getRules() {
  /*
   * Obtain the rules map
   *
   * @return std::map<std::string, std::regex>
   */
  return this->rules;
}
std::vector<std::string> lexerRules::getReservedWords() {
  return this->reservedWords;
}

lexerRules::lexerRulesIterator lexerRules::begin() {
  return std::begin(this->rules);
}

lexerRules::lexerRulesIterator lexerRules::end() {
  return std::end(this->rules);
}

std::regex lexerRules::operator[](std::string _rule) {
  return this->rules[_rule];
}
