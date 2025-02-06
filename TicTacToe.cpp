#include<iostream>
using namespace std;
char board[3][3] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'}
};

char current_marker;
int current_player;

void drawBoard() {
  cout<<"\n";
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      cout<<board[i][j]<<" ";
      if(j<2) cout<<"| ";
    }
    cout<<"\n";
    if(i<2) cout<<"--|---|--\n";
  }
  cout<<"\n";
}

bool placeMarker(int slot) {
  int row = (slot-1)/3;
  int col = (slot-1)%3;
  if(board[row][col] != 'X' && board[row][col] != 'O') {
    board[row][col] = current_marker;
    return true;
  }
  else {
    return false;
  }
}

int checkWinner() {
  for(int i=0;i<3;i++) {
    if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) return current_player;
    if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) return current_player;
  }

  if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) return current_player;
  if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) return current_player;

  return 0;
}

void switchPlayer() {
  current_player = (current_player==1) ? 2 : 1;
  current_marker = (current_marker=='X') ? 'O' : 'X';
}

void game() {
  cout<<"Player 1, choose your marker (X and O): ";
  char marker_p1;
  cin>>marker_p1;

  current_player = 1;
  current_marker = marker_p1;

  drawBoard();

  int winner = 0;
  for(int i=0;i<9;i++) {
    cout<<"Player "<<current_player<<"'s turn. Enter your slot (1-9): ";
    int slot;
    cin>>slot;

    if(slot<1 || slot>9) {
      cout<<"Invalid slot! Please choose a number between 1 and 9.\n";
      i--;
      continue;
    }

    if(!placeMarker(slot)) {
      cout<<"Slot already occupied! Try again.\n";
      i--;
      continue;
    }

    drawBoard();
    winner = checkWinner();
    if(winner != 0) break;

    switchPlayer();
  }

  if(winner==0) {
    cout<<"It's a tie!\n";
  }
  else {
    cout<<"Player "<<winner<<" wins!\n";
  }
}

int main() {
  cout<<"Welcome to Tic Tac Toe!\n";
  game();
  return 0;
}