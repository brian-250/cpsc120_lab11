// Brian Milian
// CPSC 120-12
// 2022-11-22
// brianmilian@csu.fullerton.edu
// @brian-250
//
// Lab 11-01
// Partners: @engenies
//
// this file includes the constructors, getter methods, and methods for the
// State class
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

// constructor with parameters
State::State(const std::string& name, int population, double land_area) {
  name_ = name;
  population_ = population;
  land_area_ = land_area;
}

// constructor
State::State() {
  name_ = "";
  population_ = 0;
  land_area_ = 0.0;
}

// accessor function or getter method
const std::string& State::Name() const { return name_; }

// accessor function or getter method
int State::Population() const { return population_; }

// accessor function or getter method(do we need setter methods for these getter
// methods?)
double State::LandArea() const { return land_area_; }

//(is this a method?)
double State::PopulationDensity() const {
  return double(population_) / land_area_;
}

std::vector<State> ReadStates(const std::string& csv_filename) {
  // empty vector of States to add State objects
  //(does it matter if I include curly braces{}?)
  std::vector<State> states;
  //(what do I initialize columns to?)
  //(if I don't need to initialize vector 'states', why do I need to initialize
  // 'columns'?) (if I initialize 'columns', does it affect what my vector
  // 'table' will look like?)
  int columns = 48;
  // creating 2D vector 'table' by calling function ReadCSV()
  std::vector<std::vector<std::string>> table{ReadCSV(csv_filename, columns)};

  // string variable name to store the name of a state from table
  std::string name;
  // int variable population to store the population size of a state from table
  int population{0};
  // double variable land_area to store the land_area size of a state from table
  double land_area{0.0};

  // looping through the CSV file to get the name, population size, and
  // land_area size from all states in table
  for (int row = 0; row < table.size(); row++) {
    // vector variable 'this_row' stores a row from table
    std::vector<std::string> this_row = table.at(row);
    // skip row zero
    if (row == 0) {
      continue;
    }
    for (int column = 0; column < this_row.size(); column++) {
      // string varriable 'this cell' stores a cell from table
      std::string this_cell = this_row.at(column);

      // get state name
      if (column == 0) {
        name = this_cell;
        // get population size
      } else if (column == 2) {
        population = std::stoi(this_cell);
        // get land_area size
      } else if (column == 47) {
        land_area = std::stod(this_cell);
      }
    }
    // new object 'new_state'
    State new_state(name, population, land_area);
    // adding new_state to states vector
    states.push_back(new_state);
  }
  // returning vector 'states' that includes state objects
  return states;
}