#include<iostream>
#include<vector>
using namespace std;
void printGrid(vector<vector<char>> grid, int col){
    int n=grid.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<col; j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}
int ways(int rows, int cols, int n, int m){
    if(rows==n-1 && cols==m-1) return 1;
    if(rows>=n || cols>=m) return 0;
    int value_1=ways(rows, cols+1, n, m);
    int value_2=ways(rows+1, cols, n, m);
    return value_1+value_2;
}
int main(){
    int n=3, m=3;
    vector<vector<char>> grid;
    for(int i=0; i<n; i++){
        vector<char> rows;
        for(int j=0; j<m; j++){
            rows.push_back('-');
        }
        grid.push_back(rows);
    }
    //printGrid(grid, m);
    cout<<ways(0, 0, n, m);
    return 0;
}