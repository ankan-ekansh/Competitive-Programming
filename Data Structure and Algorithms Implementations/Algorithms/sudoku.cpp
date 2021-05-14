#include<iostream>
using namespace std;
int board[9][9];
void printBoard(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
bool isValid(int board[9][9], int row, int col, int choice){
    if(board[row][col] != 0){
        return false;
    }
    for(int i=0;i<9;i++){
        if(board[i][col] == choice){
            return false;
        }
    }
    for(int j=0;j<9;j++){
        if(board[row][j] == choice){
            return false;
        }
    }
    int rowstart = row - row % 3;
    int colstart = col - col % 3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[rowstart + i][colstart + j] == choice){
                return false;
            }
        }
    }
    return true;
}
bool solve(int board[9][9], int row, int col){
    if(row >= 9){
        return true;
    }
    if(col >= 9){
        return solve(board, row+1, 0);
    }
    // printBoard();
    // bool flag = false;
    // for(int i=0;i<9;i++){
    //     for(int j=0;j<9;j++){
    //         if(board[i][j] == 0){
    //             flag = true;
    //         }
    //     }
    // }
    // if(!flag){
    //     return true;
    // }
    for(int i=1;i<=9;i++){
        if(isValid(board, row, col, i)){
            board[row][col] = i;
            if(solve(board, row, col+1)){
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}
int main(){

    solve(board, 0, 0);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}