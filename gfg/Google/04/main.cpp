/*
Sudoku Rules: No Repetition of number in row or column
*/ 

#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int checkSudokuValid(vector<vector<int>> sudoku) {
    int rowSize = sudoku.size(); 
    int colSize = sudoku[0].size();

    int row[9][10], col[9][10], grid[3][3][10];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(grid, 0, sizeof(grid));

    for(int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < colSize; ++j) {
            int num = sudoku[i][j];
            if (num > 0) {
                if (row[i][num] < 1) {
                    ++row[i][num];
                } else {
                    return 0;
                }

                if (col[j][num] < 1) {
                    ++col[j][num];
                } else {
                    return 0;
                }

                if(grid[i/3][j/3][num] < 1) {
                    ++grid[i/3][j/3][num];
                } else {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
    int t;
    cin>>t;
	while(t > 0){
	    vector<vector<int>> board(9,vector<int>(9,0));
	    for(int i=0;i<board.size();i++){
	        for(int j=0;j<board[i].size();j++)
	        cin>>board[i][j];
	    }
	     
	   cout<<checkSudokuValid(board)<<endl;
	    t--;
	}
    return 0;
}