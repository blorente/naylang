//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <iostream>

int main() {
  std::string command;
  while (command != "quit") {
      std::cout << ">>> ";
      getline(std::cin, command);
      std::cout << command << std::endl;
  }
  return 0;
}
