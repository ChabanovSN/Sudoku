#ifndef SOLVINGSUDOKU_H
#define SOLVINGSUDOKU_H
#include<iostream>
#include<QList>
#include<QLineEdit>
#include<QtCore>
#include<QtDebug>

using namespace std;
#define N 9
class SolvingSudoku{

public:
    //int **grid;
    int grid9[N][N] = {
        {9, 0, 0, 4, 0, 6, 0, 1, 0},
        {0, 1, 5, 9, 0, 0, 0, 0, 0},
        {0, 0, 7, 0, 0, 2, 0, 0, 0},
        {0, 0, 1, 5, 0, 0, 6, 0, 0},
        {0, 5, 0, 3, 8, 0, 0, 9, 0},
        {0, 0, 2, 6, 7, 4, 5, 3, 0},
        {1, 8, 0, 0, 0, 0, 0, 4, 3},
        {0, 6, 4, 0, 0, 0, 8, 0, 0},
        {0, 0, 0, 2, 4, 0, 0, 0, 9}
    };

    int grid3[N][N] = {
        {0, 0, 0, 2, 0, 0, 6, 9, 0},
        {0, 0, 0, 0, 5, 7, 0, 1, 0},
        {0, 0, 0, 0, 0, 3, 0, 4, 5},
        {5, 0, 0, 0, 0, 0, 1, 3, 8},
        {0, 0, 4, 8, 0, 5, 9, 0, 0},
        {7, 8, 1, 0, 0, 0, 0, 0, 2},
        {6, 9, 0, 5, 0, 0, 0, 0, 0},
        {0, 2, 0, 1, 3, 0, 0, 0, 0},
        {0, 1, 8, 0, 0, 6, 0, 0, 0}
    };

    int grid1[N][N] = {
        {6, 4, 0, 2, 9, 8, 5, 0, 7},
        {0, 5, 2, 1, 0, 6, 9, 8, 4},
        {7, 9, 8, 0, 4, 5, 0, 6, 2},
        {9, 0, 3, 6, 1, 4, 8, 7, 0},
        {0, 8, 6, 5, 3, 0, 4, 2, 9},
        {5, 7, 4, 0, 8, 2, 6, 0, 3},
        {8, 3, 0, 7, 6, 9, 2, 4, 1},
        {4, 1, 9, 8, 0, 3, 7, 5, 6},
        {2, 0, 7, 4, 5, 1, 3, 0, 8}
    };
    int grid[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    // int ** grid;

    void showGrid(QList<QLineEdit *> lists){
       int counter =0;
       for(auto l : lists)
           if(l->text().toInt()>0)counter++;

        if(counter > 26 && solveSudoku()){
            int l=0;
            for (int row = 0; row < N; row++)
                for (int col = 0; col < N; col++,l++)
                    lists[l]->setText(QString::number(grid[row][col]));


        }
        else{
            for(auto l : lists)
                if(l->text().toInt()!=0)
                    l->setStyleSheet("background-color:rgb(204, 0, 0)");
        }


    }
    void showExm(QList<QLineEdit *> lists){
        int l=0;
        for (int row = 0; row < N; row++)
            for (int col = 0; col < N; col++,l++)
                if(grid1[row][col] !=0)
                lists[l]->setText(QString::number(grid1[row][col]));
    }
    void setGrid(QList<QLineEdit *> lists){
        int l=0;

        for (int row = 0; row < N; row++)
            for (int col = 0; col < N; col++,l++){
                grid[row][col]=lists[l]->text().toInt();

            }
    }
    bool isPresentInCol(int col, int num){ //проверка в колонке
        for (int row = 0; row < N; row++)
            if (grid[row][col] == num)
                return true;
        return false;
    }
    bool isPresentInRow(int row, int num){ //проверка в ряду
        for (int col = 0; col < N; col++)
            if (grid[row][col] == num)
                return true;
        return false;
    }
    bool isPresentInBox(int boxStartRow, int boxStartCol, int num){
        //проверка в   3x3 коробке
        for (int row = 0; row < 3; row++)
            for (int col = 0; col < 3; col++)
                if (grid[row+boxStartRow][col+boxStartCol] == num)
                    return true;
        return false;
    }
    void sudokuGrid(){ //print
        for (int row = 0; row < N; row++){
            for (int col = 0; col < N; col++){
                if(col == 3 || col == 6)
                    cout << " | ";
                cout << grid[row][col] <<" ";
            }
            if(row == 2 || row == 5){
                cout << endl;
                for(int i = 0; i<N; i++)
                    cout << "---";
            }
            cout << endl;
        }
    }
    bool findEmptyPlace(int &row, int &col){
        for (row = 0; row < N; row++)
            for (col = 0; col < N; col++)
                if (grid[row][col] == 0)
                    return true;
        return false;
    }
    bool isValidPlace(int row, int col, int num){
        return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row%3 ,
                                                                                         col - col%3, num);
    }
    bool solveSudoku(){
        int row, col;
        if (!findEmptyPlace(row, col))
            return true; //when all places are filled
        for (int num = 1; num <= 9; num++){ //valid numbers are 1 - 9
            if (isValidPlace(row, col, num)){ //check validation, if yes, put the number in the grid
                grid[row][col] = num;
                if (solveSudoku()) //recursively go for other rooms in the grid
                    return true;
                grid[row][col] = 0; //turn to unassigned space when conditions are not satisfied
            }
        }
        return false;
    }


};

#endif // SOLVINGSUDOKU_H
