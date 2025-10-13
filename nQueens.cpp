#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
void print(vector<vector<char>> board){
    int n=board.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
    cout<<"________\n";
}
bool isSafe(vector<vector<char>> board, int row, int col){
    //horizontal
    int n=board.size();
    for(int j=0; j<n; j++){
        if(board[row][j]=='Q'){
            return false;
        }
    }
    //vertical
    for(int j=0; j<row; j++){
        if(board[j][col]=='Q'){
            return false;
        }
    }
    //diagonal left
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    //diagonal right
    for(int i=row, j=col; i>=0 && j<n; i--, j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}
void nQueens(vector<vector<char>> board, int row){
    int n=board.size();
    if(row==n){
        print(board);
        return;
    }
    for(int i=0; i<n; i++){
        if(isSafe(board, row, i)==true){
            board[row][i]='Q';
            nQueens(board, row+1);
            board[row][i]='-';
        }
    }
}
int main(){
    vector<vector<char>> board;
    int n=4;
    for(int i=0; i<n; i++){
        vector<char> newRow;
        for(int j=0; j<n; j++){
            newRow.push_back('-');
        }
        board.push_back(newRow);
    }
    nQueens(board, 0);
//    print(board);

    return 0;
}