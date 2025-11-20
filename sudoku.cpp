#include<iostream>
#include<vector>
using namespace std;
void printSudoku(int sudoku[9][9]){
    for(int i=0; i<9; i++){
        int border=7, j=0, k=0;
        if(i==3 || i==6){
            cout<<"";
            while(border!=0){
                if(border==1){
                    cout<<"|-";
                    border=7;
                } else{
                    cout<<"-";
                    border--;
                }
                if(k==19) break;
                k++;
            }
            cout<<endl;
        }
        while(j<9){
            cout<<sudoku[i][j]<<" ";
            if(j==2 || j==5){
                cout<<"| ";
            }
            j++;
        }
        cout<<endl;
    }
    cout<<"------------------------------------\n";
}
bool isSafe(int sudoku[][9], int digit, int row, int cols){
    for(int i=0; i<9; i++){
        if(sudoku[i][cols]==digit) return false;
    }

    for(int j=0; j<9; j++){
        if(sudoku[row][j]==digit) return false;
    }
    int startRow=(row/3)*3;
    int startCols=(cols/3)*3;
    
    for(int i=startRow; i<=startRow+2; i++){
        for(int j=startCols; j<=startCols+2; j++){
            if(sudoku[i][j]==digit) return false;
        }
    }
    return true;
}
void sudokuSolver(int sudoku[][9], int row, int cols){
    if(cols>=9){
        sudokuSolver(sudoku, row+1, 0);
        return;
    }
    if(row==9){
        printSudoku(sudoku);
        return;
    }
    if(sudoku[row][cols]==0){
        for(int i=1; i<=9; i++){
            if(isSafe(sudoku, i, row, cols)==true){
                sudoku[row][cols]=i;
                sudokuSolver(sudoku, row, cols+1);
                sudoku[row][cols]=0;
            }
        }
    } else{
        sudokuSolver(sudoku, row, cols+1);
    }
}
int main(){
    int sudoku[9][9]={{0, 0, 8, 0, 0, 0, 0, 0, 0},
                      {4, 9, 0, 1, 5, 7, 0, 0, 2},
                      {0, 0, 3, 0, 0, 4, 1, 9, 0},
                      {1, 8, 5, 0, 6, 0, 0, 2, 0},
                      {0, 0, 0, 0, 2, 0, 0, 6, 0},
                      {9, 6, 0, 4, 0, 5, 3, 0, 0},
                      {0, 3, 0, 0, 7, 2, 0, 0, 4},
                      {0, 4, 9, 0, 3, 0, 0, 5, 7},
                      {8, 2, 7, 0, 0, 9, 0, 1, 3}};
    // for(int i=0; i<9; i++){
    //     vector<int> row;
    //     for(int j=0; j<9; j++){
    //         row.push_back(0);
    //     }
    //     sudoku.push_back(row);
    // }
   printSudoku(sudoku);
   sudokuSolver(sudoku, 0, 0);
    return 0;
}