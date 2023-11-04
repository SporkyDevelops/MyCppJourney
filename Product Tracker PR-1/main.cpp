#include <fstream>
#include <iostream>
#include <sstream>

void productSearch() {

  std::ifstream file;

  int line_number;

  int current_line = 0;

  std::string line;

  std::cout << std::endl;
  std::cout << "Input product number" << std::endl;
  std::cin >> line_number;
  // checks if your input num (product num) is higher or = to 1
  if (line_number <= 0) {
    std::cout << "Product number must be >= 1" << std::endl;
    productSearch();
  }

  file.open("productStock.txt");
  // If file isnt able to be opened
  if (file.fail()) {
    std::cout << "File failed to open." << std::endl;
    return 1;
  }
  // adds lines till it reachs your target (product num)
  while (!file.eof()) {
    current_line++;
    getline(file, line);
    if (current_line == line_number)
      break;
  }
  // If lines are less than what you input (product num)
  if (current_line < line_number) {
    std::cout << "Line not found!" << std::endl;
    std::cout << "File contains " << current_line;
    std::cout << " lines total." << std::endl;
  } else
    std::cout << "Product Info (Name/Cost/Instock): " << line << std::endl;
  // closes the file (productStock)
  file.close();

  // asks to exit and grabs your input
  std::cout << "Do you wish to exit? Y/N" << std::endl;
  std::string exit;
  std::cin >> exit;

  // controls exiting or reruning the program and void func
  if (exit == "N" || exit == "n")
    productSearch();
  else if (exit == "Y" || exit == "y")
    return 1;
  else if (exit != "Y" || exit != "N" || exit != "y" || exit != "n")
    std::cout << "Invalid command.... exiting now...";
  return 1;
}

void productUpdate() {
  std::ofstream fileOut;

  std::string newEntry;
  std::string string_input;

  std::cout << "Format of input -Name/Price(usd)/InStock(Yes/No)" << std::endl;

  fileOut.open("productStock.txt", std::ios::app);

  if (fileOut.fail()) {
    std::cout << "File failed to open";
    return 1;
  }

  std::cin >> string_input;

  fileOut << string_input << std::endl;

  fileOut.close();

  std::cout << "Do you wish to exit? Y/N" << std::endl;
  std::string exitUpdate;
  std::cin >> exitUpdate;

  if (exitUpdate == "N" || exitUpdate == "n")
    productUpdate();
  else if (exitUpdate == "Y" || exitUpdate == "y")
    return 1;
  else if (exitUpdate != "Y" || exitUpdate != "y" || exitUpdate != "N" ||
           exitUpdate != "n") {
    std::cout << "Invalid command.... exiting now...";
    return 1;
  }
}

int main() {

  // declares int for selection
  int selection;

  // takes input for your selection
  std::cout << "Enter 1 to Search database and 2 to update a  product"
            << std::endl;
  std::cin >> selection;

  // when selecting 1
  if (selection == 1) {
    std::cout << "Switching to Product Searcher" << std::endl;
    // calls void ps();
    productSearch();
  }
  // when selecting 2
  else if (selection == 2) {
    std::cout << "Switching to Product Updater" << std::endl;
    // calls void pu();
    productUpdate();
  }
  // when not selecting 1 or 2
  else {
    std::cout << "Invalid selection" << std::endl;
    return 0;
  }
}
