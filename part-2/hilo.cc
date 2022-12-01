// Brian Milian
// CPSC 120-12
// 2022-11-29
// brianmilian@csu.fullerton.edu
// @brian-250
//
// Lab 11-02
// Partners: @engenies
//
// this file includes one constructor, some getter methods, and methods for the
// GameState class
//

#include "hilo.h"

#include "rng.h"

GameState::GameState(int secret) : secret_(secret), guesses_left_(4){};
// secret_ = secret;
// guesses_left_ = 4;

int GameState::Secret() const { return secret_; }

int GameState::GuessesLeft() const { return guesses_left_; }

bool GameState::GuessCorrect(int guess) const { return (guess == secret_); }

bool GameState::GuessTooBig(int guess) const { return (guess > secret_); }

bool GameState::GuessTooSmall(int guess) const { return (guess < secret_); }

void GameState::CountGuess() { guesses_left_--; }

bool GameState::GameOver() const { return (guesses_left_ == 0); }

int RandomSecretNumber() {
  // Hint: first seed the random number generator
  // then generate a random number between 1 and 10
  RandomNumberGenerator rng = RandomNumberGenerator(1.0, 10.0);
  int random_number = int(rng.next());
  // finally return that random number
  return random_number;
}