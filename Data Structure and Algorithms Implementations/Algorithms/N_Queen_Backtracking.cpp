#include<iostream>
using namespace std;
bool board[8][8];
bool r[8];
const int N = 8;
int solutions = 0;
void printBoard(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
bool isSafe(int row, int col, bool board[N][N]){
    for(int i=0;i<col;i++){
        if(board[row][i]){
            return false;
        }
    }
    for(int i=row, j=col;i<N && j>=0; i++, j--){
        if(board[i][j]){
            return false;
        }
    }
    for(int i=row, j=col;i>=0 && j>=0; i--, j--){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}
void solve(bool board[N][N], int col){
    if(col >= N){
        solutions++;
        printBoard();
        return;
    }
    for(int i=0;i<N;i++){
        if(isSafe(i, col, board)){
            board[i][col] = true;
            solve(board, col+1);
            board[i][col] = false;
        }
    }
    // return;
}
int main(){

    // cin >> N;
    solve(board, 0);
    cout << solutions << "\n";
    return 0;
}