#include <iostream>
using namespace std;

void initializeBoard(int board[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      board[i][j] = 0;
    }
  }
}

void printBoard(int board[9][9]) {
  cout << "------------" << endl;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << board[i][j];
      if ((j + 1)% 3 == 0) {
        cout << '|';
      }
    }
    cout << endl;
    if ((i + 1)% 3 == 0) {
      cout << "------------" << endl;
    }
  }
}

int main() {
  int board[9][9];
  initializeBoard(board);
  printBoard(board);
  return 0;
}
