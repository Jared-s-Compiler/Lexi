#pragma once

#include <iostream>
#include <regex>
#include <tuple>
#include <vector>

class lexeme {
  /*
   * A class to represent a token produced by our lexer
   */

 public:
  lexeme(std::tuple<size_t, size_t, size_t>, std::string, std::string);
  friend std::ostream& operator<<(std::ostream&, const lexeme&);
  const std::string get_substring();
  std::string get_tag();

  friend bool operator==(const lexeme&, const lexeme&);

  friend bool operator!=(const lexeme&, const lexeme&);
  friend bool operator<(const lexeme&, const lexeme&);

 private:
	// Where the lexeme is in the source file
  std::tuple<size_t, size_t, size_t> slice;
  std::string identifier;
  std::string substring;
};
