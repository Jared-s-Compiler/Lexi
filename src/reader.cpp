#include "../include/reader.hpp"

#include <fstream>
#include <iostream>
#include <vector>

sourceFile::sourceFile(std::string _path) {
  this->m_Path = _path;
  this->readContents();
}

sourceFile::sourceFile(){}

std::string sourceFile::getPath() {
  /*
   * Get the current path the source file is pointing to
   *
   * @return std::string
   */

  return this->m_Path;
}

std::vector<std::string> sourceFile::content() {
  /*
   * Get the content of source file
   *
   * @return std::vector<std::string>
   */

  return this->m_Content;
}

size_t sourceFile::size() const {
  /*
   * Get the size of the file
   *
   * @return size_t
   */

  return this->m_Content.size();
}

std::vector<std::string>::iterator sourceFile::begin() {
  /*
   * Obtain an iterator to the beginning of the file
   *
   * @return std::vector<std::string>::iterator
   */

  return this->m_Content.begin();
}

std::vector<std::string>::iterator sourceFile::end() {
  /*
   * Obtain an iterator to the end of the file
   *
   * @return std::vector<std::string>::iterator
   */

  return this->m_Content.end();
}

void sourceFile::readContents() {
  /*
   * Read in the contents of the file
   * and assign it to m_Content
   *
   * @return void
   */

  std::ifstream file(this->m_Path);
  std::vector<std::string> contents;

  if (!file.is_open()) {
    throw std::ios_base::failure("cannot open file!");
  }

  for (std::string line; std::getline(file, line);) {
    contents.push_back(line);
  }

  this->m_Content = contents;

  file.close();
}

std::ostream& operator<<(std::ostream& out, const sourceFile& rhs) {
  /*
   * Overloaded ostream operator to print the contents of the file
   *
   * @return std::ostream&
  */

  for (std::string line : rhs.m_Content) {
    out << line << std::endl;
  }
  return out;
}
