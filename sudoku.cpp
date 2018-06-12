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
      if ((j + 1) % 3 == 0) {
        cout << '|';
      }
    }
    cout << endl;
    if ((i + 1) % 3 == 0) {
      cout << "------------" << endl;
    }
  }
}

void setNum(int number, int row, int col, int board[9][9]) {
  board[row][col] = number;
  printBoard(board);
}

bool checkBox(int num, int currentRow, int currentColumn, int board[9][9]) {
  int rowSquare;
  int columnSquare;
  int startingRow;
  int startingColumn;
  if ((currentRow >= 0) && (currentRow <= 2)) {
    startingRow = 0;
  }
  if ((currentRow >= 3) && (currentRow <= 5)) {
    startingRow = 3;
  }
  if ((currentRow >= 5) && (currentRow <= 9)) {
    startingRow = 5;
  }
  if ((currentColumn >= 0) && (currentColumn <= 2)) {
    startingColumn = 0;
  }
  if ((currentColumn >= 3) && (currentColumn <= 5)) {
    startingColumn = 3;
  }
  if ((currentColumn >= 5) && (currentColumn <= 9)) {
    startingColumn = 5;
  }
  for (int i = startingRow; i < startingRow + 3; i++) {
    for (int j = startingColumn; i < startingColumn + 3; i++) {
      if ((board[i][j] == num) && (i != currentRow) && (j != currentColumn)) {
        return false;
      }
    }
  }
  return true;
}

bool checkRow(int num, int row, int currentCol, int board[9][9]) {
  for (int i = 0; i < 9; i++) {
    if ((board[row][i] == num) && (i != currentCol)) {
      return false;
    }
  }
  return true;
}

bool checkColumn(int num, int column, int currentRow, int board[9][9]) {
  for (int i = 0; i < 9; i++) {
    if ((board[i][column] == num) && (i != currentRow)) {
      return false;
    }
  }
  return true;
}

int fillBoard(int board[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] == 0) {
        for (int k = 1; k <= 9; k++) {
          if (checkBox(k, i, j, board) && (checkRow(k, i, j, board)) &&
              (checkColumn(k, j, i, board))) {
            board[i][j] = k;
          }
        }
      }
    }
  }
  return 0;
}

int main() {
  int board[9][9];
  initializeBoard(board);
  fillBoard(board);
  fillBoard(board);
  printBoard(board);
  return 0;
}
