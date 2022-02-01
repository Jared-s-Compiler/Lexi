#include "../../include/Domain/lexeme.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <regex>
#include <string>
#include <tuple>
#include <vector>

static int first = 0;

lexeme::lexeme(std::tuple<size_t, size_t, size_t> coordinates,
               std::string sub,
               std::string id) {
  const auto [z, x, y] = coordinates;
  this->slice = std::make_tuple(z, x, y);
  this->substring = sub;
  this->identifier = id;
}

const std::string lexeme::get_substring() {
  return this->substring;
}

std::string lexeme::get_tag() {
  return this->identifier;
}

std::ostream& operator<<(std::ostream& out, const lexeme& lex) {
  const auto [line, start, end] = lex.slice;
  out << std::left << std::setw(0);

  if (first == 0) {
    out << "\nTOKENS"
        << std::string(3, '\t')
        << "LEXEMES"
        << std::string(2, '\t')
        << "LINE_NUM" << std::endl;
    out << std::string(6, '#') << "\t\t\t" << std::string(7, '#') << "\t\t"
        << std::string(8, '#') << std::endl << std::endl;
    first++;
  }

  if (lex.identifier == "COMMENT" || lex.identifier == "KEYWORD" ||
      lex.identifier == "NUMBER") {
    out << lex.identifier << "\t";
  } else {
    out << lex.identifier;
  }

  out << std::right << "\t\t" << lex.substring << "\t\t";
  out << "(" << line << ", " << start << ", " << end << ")";

  return out;
}

bool operator==(const lexeme& lhs, const lexeme& rhs) {
  return (lhs.slice == rhs.slice && lhs.substring == rhs.substring &&
          lhs.identifier == rhs.identifier);
}

bool operator!=(const lexeme& lhs, const lexeme& rhs) {
  return !(lhs == rhs);
}

bool operator<(const lexeme& lhs, const lexeme& rhs) {
  return lhs.slice < rhs.slice;
}

