// Brian Milian
// CPSC 120-12
// 2022-11-22
// brianmilian@csu.fullerton.edu
// @brian-250
//
// Lab 10-03
// Partners: @engenies
//
// creates a file that outputs a colored canvas of red, green, blue, and yellow
//

#include "states.h"

#include <fstream>
#include <iostream>
#include <string>

std::vector<std::vector<std::string>> ReadCSV(const std::string& csv_filename,
                                              int columns) {
  std::vector<std::vector<std::string>> table;
  std::ifstream file(csv_filename);

  // read each row
  while (file.good()) {
    std::vector<std::string> row;
    // read each column
    for (int i = 0; i < columns; ++i) {
      std::string cell;
      file.ignore(1, '"');  // leading quote
      std::getline(file, cell, '"');
      if (i < (columns - 1)) {
        file.ignore(1, ',');  // comma
      }
      row.push_back(cell);
    }
    if (file.good()) {
      table.push_back(row);
    }
  }

  return table;
}

State::State(const std::string& name, int population, double land_area) {
  // TODO: complete the definition of this constructor.
  // Since this is a constructor, it should use a member initialization list
  // to initialize data members.
  // When you are done, delete this comment.
  name_ = name;
  population_ = population;
  land_area_ = land_area;
}

State::State() {
  // TODO: complete the definition of this constructor.
  // Since this is a constructor, it should use a member initialization list
  // to initialize data members.
  // When you are done, delete this comment.
  name_ = "";
  population_ = 0;
  land_area_ = 0.0;
}

const std::string& State::Name() const {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: This is a simple accessor function. The function definition only
  // needs to be a single statement.
  return name_; // TODO: replace this return statement with one that actually works
}

int State::Population() const {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: This is a simple accessor function. The function definition only
  // needs to be a single statement.
  return population_; // TODO: replace this return statement with one that actually works
}

double State::LandArea() const {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: This is a simple accessor function. The function definition only
  // needs to be a single statement.
  return land_area_; // TODO: replace this return statement with one that actually works
}

double State::PopulationDensity() const {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: Population density is the population divided by the land area.
  return double(population_)/land_area_; // TODO: replace this return statement with one that actually works
}

std::vector<State> ReadStates(const std::string& csv_filename) {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: this function should:
  //  - create an empty vector of States
  std::vector<std::string> states;
  int columns;
  //  - call ReadCSV to create a 2D vector of strings
  std::vector<std::vector<std::string>> table{ReadCSV(csv_filename, columns)};
  //  - loop through each row of the CSV
    std::ifstream file(csv_filename);
    if (!file.is_open()) {
      std::cout << "Could not open the file " << csv_filename << ". Exiting.\n";
    }
  //    - skip the first row that contains a header
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
  //    - for all other rows:
  //      - get the name (as a string) from column 0
  //      - get the population (as a string) from column 2
  //        convert the string to an int with std::stoi
  //      - get the land area (as a string) from column 47
  //        convert the string to a double with std::stod
  //      - create a State object with the name, population, land area
  //      - add the State to your vector with push_back
    std::string name;
    std::string population;
    std::string land_area;
    while (file.good()) {
      file.ignore(1, '"');
      std::getline(file, name, '"');
      name +=


    }

  return std::vector<State>(); // TODO: replace this return statement with one that actually works
}
