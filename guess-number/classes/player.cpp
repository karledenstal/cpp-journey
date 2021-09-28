#include "player.hpp"

using namespace std;

Player::Player(string set_name) {
  name = set_name;
}

string Player::get_name() {
  return name;
}

void Player::deposit(double num) {
  balance = num;
}

double Player::get_balance() {
  return balance;
}

void Player::make_bet(double bet) {
  balance -= bet;
}

void Player::add_win_sum(double sum) {
  balance += sum;
}

void Player::withdraw_all() {
  balance = 0;
}