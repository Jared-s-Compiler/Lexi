#pragma once

#include <string>
#include <vector>

class sourceFile {
 public:
  sourceFile();
  sourceFile(std::string);

  friend std::ostream& operator<<(std::ostream&, const sourceFile&);

  std::string getPath();
  size_t size() const;
  std::vector<std::string> content();
  std::vector<std::string>::iterator begin();
  std::vector<std::string>::iterator end();

  void readContents();
  void print_contents();

 private:
  std::string m_Path;
  std::vector<std::string> m_Content;
  std::vector<std::string>::iterator m_Begin;
  std::vector<std::string>::iterator m_End;
};
