#pragma once
#include <map>
#include <regex>
#include <string>

class lexerRules {
 public:
	using lexerRulesIterator = std::map<std::string, std::regex>::iterator;
	lexerRules();
  lexerRules(std::map<std::string, std::regex>);
  lexerRules(const lexerRules& other);
  lexerRules& operator=(const lexerRules& other);

  std::map<std::string, std::regex> getRules();

	lexerRulesIterator begin();
	lexerRulesIterator end();

	std::regex operator[](std::string);
	std::vector<std::string> getReservedWords();

 private:
  std::map<std::string, std::regex> rules;
	std::vector<std::string> reservedWords;
};

