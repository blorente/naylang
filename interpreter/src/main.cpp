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
