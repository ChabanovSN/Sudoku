#ifndef GENERATOR_H
#define GENERATOR_H
#include<iostream>
#include<QtDebug>
using namespace std;
class Generator{

    int max = 8;
    int min = 0;

    int digitMax = 9;
    int digitMin = 1;

    int easyMin = 36;
    int easyMax = 49;

    int mediumMin = 32;
    int mediumMax = 35;

    int hardMin = 22;
    int hardMax = 27;

public:
    int ** getGrid(){
           srand(time(NULL));
        int ** grid = new int *[9];
        for(int i = 0; i<9;i++)
            grid[i]=new int[9];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            grid[i][j]=0;


        string option = "easy"; //hard
        srand(time(0));
        int row = 0;
        int col = 0;

        int randomNumber = 0;
        int noOfCellsToBeGenerated = 36;

//        if ("easy"==option) {
//            noOfCellsToBeGenerated = easyMin + (rand() % (easyMax - easyMin + 1));

//        } else if ("medium"==option) {
//            noOfCellsToBeGenerated = mediumMin + (rand() % (mediumMax - mediumMin + 1));

//        } else {
//            noOfCellsToBeGenerated = hardMin + (rand() % (hardMax - hardMin + 1));

//        }

   qDebug()<<"noOfCellsToBeGenerated2 "<<noOfCellsToBeGenerated;
        for (int i = 1; i <= noOfCellsToBeGenerated; i++) {
            row =   rand()%8+1;
            col =   rand()%8+1;
            randomNumber = rand()%9+1;
            qDebug()<<row<<" "<<col<<" random "<<randomNumber;

            if (grid[row][col] == 0 && noConflict(grid, row, col, randomNumber)) {
                grid[row][col] = randomNumber;
            } else {
                i--;
            }

        }

//                    for (int i = 0; i < 9; i++) {
//                        for (int j = 0; j < 9; j++) {
//                           qDebug()<<grid[i][j]<<"  ";
//                        }
//                        qDebug()<<endl;;
//                    }
        return  grid;
    }

    bool noConflict(int ** array, int row, int col, int num) {

        for (int i = 0; i < 9; i++) {
            if (array[row][i] == num) {
                return false;
            }
            if (array[i][col] == num) {
                return false;
            }
        }

        int gridRow = row - (row % 3);
        int gridColumn = col - (col % 3);
        for (int p = gridRow; p < gridRow + 3; p++) {
            for (int q = gridColumn; q < gridColumn + 3; q++) {
                if (array[p][q] == num) {
                    return false;
                }
            }
        }
        return true;
    }
};

#endif // GENERATOR_H
