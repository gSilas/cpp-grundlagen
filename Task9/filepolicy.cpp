#include <iostream>
#include "filepolicy.hpp"

void FilePolicy::write(const std::string& msg){
  mStream << msg;
  mStream.flush();
}
