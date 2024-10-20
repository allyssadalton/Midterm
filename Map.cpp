#include "Map.h"

Map::Map(){
    array = new char*[10];
    for (int i = 0; i < 10; i++){array[i] = new char[10];}
}

Map::~Map(){
    for (int i = 0; i < 10; i++){delete[] array[i];}
    delete[] array;
}

void Map::CreateMap(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (j == 9){array[i][j] = 'P';}
            else if (j % 3 == 0){array[i][j] = 'S';}
            else if (j % 3 == 1){array[i][j] = 'C';}
            else if (j % 3 == 2){array[i][j] = 'H';}
        }
    }
}

void Map::DisplayMap(){
    for (int i = 0; i < 10; i++){
        cout << "---------------------" << endl;
        for (int j = 0; j < 10; j++){
            if (j == 0){cout << "|";}
            cout  << array[i][j]<< "|";
        }
        cout << endl;
    }
    cout << "---------------------" << endl;
}