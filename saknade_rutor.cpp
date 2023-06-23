#include<stdio.h>
#include<iostream>
#include<vector>
#include<array>
using namespace std;

const int GRID_SIZE = 8;

bool can_place(std::vector<std::vector<int>> &grid, int row, int col, int num){
    for(int i = 0; i < GRID_SIZE; i++){ //grid.size() == 8
    if (grid[row][i] == num || grid[i][col] == num)
        return false;
}
    return true;
}

bool solve_grid(std::vector<std::vector<int>> &grid, int row, int col){
    if(row == GRID_SIZE){
        return true;
    }
    if(col == GRID_SIZE){
        return solve_grid(grid, row+1, 0);
    }
    if(grid[row][col] != 0){
        return solve_grid(grid, row, col+1);
    }
    for(int i = 1; i <= GRID_SIZE; i++){
        if(can_place(grid, row, col, i)){
            grid[row][col] = i;
            if(solve_grid(grid, row, col+1)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

void print_grid(std::vector<std::vector<int>> &grid){
    for(int i = 0; i < GRID_SIZE; i++){
        for(int j = 0; j < GRID_SIZE; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

std::vector<std::vector<int>>solvable_grid(std::vector<std::vector<int>> &grid, int row, int col){
    if(row == GRID_SIZE){
        return grid;
    }
    if(col == GRID_SIZE){
        return solvable_grid(grid, row+1, 0);
    }
    if(grid[row][col] != 0){
        return solvable_grid(grid, row, col+1);
    }
    for(int i = 1; i <= GRID_SIZE; i++){
        if(can_place(grid, row, col, i)){
            grid[row][col] = i;
            if(solve_grid(grid, row, col+1)){
                return grid;
            }
            grid[row][col] = 0;
        }
    }
    return grid;
}

int main(){
    std::vector<std::vector<int>>grid = {
        {0,0,-1,8,6,0,0,4},
        {0,-1,0,7,5,1,4,3},
        {5,2,7,0,-1,0,0,8},
        {6,0,0,0,8,5,-1,1},
        {0,5,8,0,4,0,3,-1},
        {4,0,0,-1,0,7,6,0},
        {-1,0,0,0,1,6,5,2},
        {8,1,4,2,0,-1,0,0}
    };
    if (solve_grid(grid, 0, 0)) {
        cout << "Solution:" << endl;
        grid = solvable_grid(grid, 0, 0);
        print_grid(grid);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}