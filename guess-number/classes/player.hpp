#include <iostream>

using namespace std;

class Player {

  string name;
  double balance;

  public:
    Player(string name);
    void deposit(double num);
    void withdraw_all();
    void make_bet(double bet);
    void add_win_sum(double sum);
    double get_balance();
    string get_name();
};
