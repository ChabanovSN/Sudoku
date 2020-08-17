#ifndef GENERATOR_H
#define GENERATOR_H
#include<iostream>
using namespace std;
class Generator{
    int easyMin = 22;
    int easyMax = 27;

    int mediumMin = 32;
    int mediumMax = 35;

    int hardMin =36;
    int hardMax = 49;

public:
    Generator(){
        srand(time(0));
    }
    int ** getBroud(int option){
        int row = 0;
        int col = 0;
        int randomNumber = 0;
        int byZero= 0;
        int ** grid = new int *[9];

        for(int i = 0; i<9;i++)
            grid[i]=new int[9];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                grid[i][j] =0;


        switch (option) {
        case 1:
            byZero = easyMin + (rand() % (easyMax - easyMin + 1));
            break;
        case 2 :
            byZero = mediumMin + (rand() % (mediumMax - mediumMin + 1));
            break;
        default:
            byZero= hardMin + (rand() % (hardMax - hardMin + 1));
        }

        randomNumber = rand()% 9+1;

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; ) {
                if ( noConflict(grid, i, j, randomNumber)) {
                    grid[i][j] = randomNumber;
                    j++;
                }
                randomNumber = (randomNumber)% 9+1;
            }

        }

        for (int i = 0; i < byZero;) {

            row =  rand()%9;
            col = rand()%9;
            if(grid[row][col] !=0){
                grid[row][col] = 0;
                i++;
            }
        }


        return  grid;
    }

    bool noConflict(int ** array, int row, int col, int num) {
        for (int i = 0; i < 9; i++) {
            if(array[row][col])continue;
            if (array[row][i] == num)return false;
            if (array[i][col] == num)return false;

        }

        int gridRow = row - (row % 3);
        int gridColumn = col - (col % 3);
        for (int p = gridRow; p < gridRow + 3; p++) {
            for (int q = gridColumn; q < gridColumn + 3; q++) {
                if(array[row][col])continue;
                if (array[p][q] == num)return false;

            }
        }
        return true;
    }
};

#endif // GENERATOR_H
