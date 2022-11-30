// Brian Milian
// CPSC 120-12
// 2022-11-29
// brianmilian@csu.fullerton.edu
// @brian-250
//
// Lab 11-02
// Partners: @engenies
//
// this file includes the constructors, getter methods, and methods for the
// State class
//

#include <random>
#include <chrono>

#include "hilo.h"

#include "rng.h"

GameState::GameState(int secret) {
  // TODO: complete the definition of this constructor.
  // Since this is a constructor, it should use a member initialization list
  // to initialize data members.
  // When you are done, delete this comment.
  secret_ = secret;
}

int GameState::Secret() const {
  // TODO: complete the definition of this constructor.
  // Since this is a constructor, it should use a member initialization list
  // to initialize data members.
  // When you are done, delete this comment.
  return secret_;
}

int GameState::GuessesLeft() const {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: This is a simple accessor function. The function definition only
  // needs to be a single statement.
  return guesses_left_; // TODO: replace this return statement with one that actually works
}

bool GameState::GuessCorrect(int guess) const {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: Use an if statement.
  return (guess == Secret()); // TODO: replace this return statement with one that actually works
}

bool GameState::GuessTooBig(int guess) const {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: Use an if statement.
  return (guess > secret_); // TODO: replace this return statement with one that actually works
}

bool GameState::GuessTooSmall(int guess) const {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: Use an if statement.
  return (guess < secret_); // TODO: replace this return statement with one that actually works
}

void GameState::CountGuess() {
  // TODO: write statements to implement this function, and delete this comment
  guesses_left_--;
}

bool GameState::GameOver() const {
  // TODO: write statements to implement this function, and delete this comment
  return (GuessesLeft() == 0); // TODO: replace this return statement with one that actually works
}

int RandomSecretNumber() {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: first seed the random number generator
  std::mt19937 mt;
  // then generate a random number between 1 and 10
  std::uniform_int_distribution random10{1, 6}
  // finally return that random number
  return random10; // TODO: replace this return statement with one that actually works
}
