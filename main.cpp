#include<iostream>
#include "Utils.h"
#include<vector>
#include<string>

using namespace std;

void show_board(vector<vector<int>> &board);
string symbols(int num);


int main(){

  //Terminal size
  int T_WIDTH, T_HEIGHT;

  //Board definition
  vector<vector<int>> board(10, vector<int>(10, 0));
  
  //Get Terminal size
  dimensions(&T_WIDTH, &T_HEIGHT);

  if (T_HEIGHT < 19 || T_WIDTH < 20){
    cout << "You need a largest terminal" << endl;
    return 0;
  }

  for (int i = 0; i<(T_HEIGHT - 19)/2; i++) cout << "\n"; //Space between top and board
  show_board(board);
  for (int i = 0; i<(T_HEIGHT - 19)/2 - 1; i++) cout << "\n"; //Space between bottom and board

  return 0;
}

string symbols(int num){
  switch (num) {
    
    case 0:
      return "\033[1;30m+\033[0m"; //Blue
      break;

    case 1:
      return "\033[1;34mo\033[0m"; //Green
      break;

    case 2:
      return "\033[1;34m~\033[0m"; //Green
      break;

    case 3:
      return "\033[1;31m#\033[0m"; //Red
      break;

    default:
      return "\033[1;30m+\033[0m"; //Blue
      break;
  }
}

void show_board(vector<vector<int>> &board){
  int num = 0;

  for(int i = 0; i<10; i++){
    for (int j = 0; j<10; j++){
      num = board[i][j];
      cout << " " << symbols(num); 
    }
    cout << "\n\n";
  }
}
