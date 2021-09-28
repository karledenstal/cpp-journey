#include <iostream>
#include <cmath>
#include "classes/player.hpp"

using namespace std;

int main()
{
  string name;
  cout << "Welcome!\nPlease enter your name: ";
  cin >> name;

  Player player(name);

  char deposit;
  double deposit_amount;
  cout << "Do you want to deposit some money to your balance? (y/n) ";
  cin >> deposit;

  if (deposit == 'y')
  {
    cout << "How much do you want to deposit? ";
    cin >> deposit_amount;
    player.deposit(deposit_amount);
    cout << endl
         << "Current balance: $" << player.get_balance() << "\n\n";
  }

  char play;
  cout << "Want to play guess the number? (y/n) ";
  cin >> play;

  while (play != 'n')
  {
    double bet;
    int tries = 0;
    char confirm;
    double balance = player.get_balance();

    cout << "How much do you want to bet? ";
    cin >> bet;

    while (bet > balance) {
      cout << "That's more than your balance!\n";
      cout << "How much do you want to bet? ";
      cin >> bet;
    }

    cout << "Are you sure you wanna bet $" << bet << "? (y/n) ";
    cin >> confirm;
    player.make_bet(bet);
    cout << "Current balance is: $" << player.get_balance() << "\n\n";

    cout << "Ok! Let's play!!\n\n";

    int random_number = rand() % 100 + 1;
    int guess;

    cout << "I'm thinking of a number between 0 - 100.\nWhat's your guess? ";
    cin >> guess;

    while (guess < 0 || guess > 100) {
      cout << "You can't guess more than 100 or less than 0\n";
      cout << "Type another guess: ";
      cin >> guess;
    }

    while (tries <= 2)
    {
      if (guess == random_number)
      {
        cout << "You win!!\n\n";
        cout << "$" << bet * 1.25 << " will be added to your balance!" << endl;
        player.add_win_sum(bet * 1.25);
        cout << "Would you like to play again? (y/n) ";
        cin >> play;
        tries = 3;
      } else {
        cout << "No, that's wrong!!\n\n";
        cout << "Make another guess ";
        cin >> guess;
        cout << "\n\n";
        tries++;
      }
    }

    if (tries == 3 && guess != random_number) {
      cout << "Sorry, all out of guesses!!\n";
      cout << "The correct number was " << random_number << "\n\n";
      cout << "Would you like to play again? (y/n) ";
      cin >> play;
    }
  }

  if (play == 'n') {
    char cash_out;

    cout << "All done?\n";
    cout << "Want to cash out? (y/n) ";
    cin >> cash_out;

    if (cash_out == 'y') {
      cout << "Here ya go, $" << player.get_balance() << " just for you!\n\n";
      player.withdraw_all();
      cout << "Thanks for playing!!" << endl;
    } else {
      cout << "Thanks for playing!!" << endl;
    }
  }

  return 0;
}
