#include "box.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include <tgmath.h>
Box::Box()
{
 
    this->value = 0;
    this->canchange = false;
 
 
 
 
}
 
Box::Box(int _value)
{
 
    this->value = _value;
    this->canchange = false;
 
 
}
 
bool Box::CanChange(Box grid[9][9], int ligne, int colonne) {
    if (grid[ligne][colonne].canchange == true) {
        return true;
    }
    else {
        return false;
    }
 
 
}
 
void Box::Difficulty(Box grid[9][9]) {
    int _Difficulty;
    std::cout << "Veuillez choisir votre difficulte \n Pour la difficulte facile tapez 1 \n Pour la difficulte normal tapez 2 \n Pour la difficulte difficile tapez 3 : ";
    std::cin >> _Difficulty;
    while (_Difficulty > 3 || _Difficulty < 1) {
        std::cout << "Veuillez choisir une des difficulte propose ! :  ";
        std::cin >> _Difficulty;
    }
    if (_Difficulty == 1) {
        for (int a = 0; a < 20; a++) {
            int ligne = rand() % 9;
            int colonne = rand() % 9;
            if (grid[ligne][colonne].value == 0) {
                a = a - 1;
 
            }
            else
            {
 
                grid[ligne][colonne].value = 0;
                grid[ligne][colonne].canchange = true;
            }
 
        }
 
    }
    else if (_Difficulty == 2) {
        for (int b = 0; b < 30; b++) {
 
            int ligne = rand() % 9;
            int colonne = rand() % 9;
            if (grid[ligne][colonne].value == 0) {
                b = b - 1;
 
            }
            else
            {
                grid[ligne][colonne].value = 0;
                grid[ligne][colonne].canchange = true;
            }
 
 
        }
 
    }
    else if (_Difficulty == 3) {
        for (int c = 0; c < 45; c++) {
            int ligne = rand() % 9;
            int colonne = rand() % 9;
            if (grid[ligne][colonne].value == 0) {
                c = c - 1;
 
            }
            else
            {
                grid[ligne][colonne].value = 0;
                grid[ligne][colonne].canchange = true;
            }
 
        }
 
    }
 
 
}
 
bool Box::PossibleColonne(Box grid[9][9], int gridtest, int colonne) {
 
    for (int ligne = 0; ligne < 9; ligne++) {
 
        if (grid[ligne][colonne].value == gridtest) {
 
            return false;
        }
    }
    return true;
 
}
 
bool Box::PossibleLigne(Box grid[9][9], int gridtest, int ligne) {
 
 
    for (int colonne = 0; colonne < 9; colonne++) {
 
 
        if (grid[ligne][colonne].value == gridtest) {
            return false;
        }
    }
    return true;
 
}
 
bool Box::PossibleCarre(Box grid[9][9], int gridtest, int ligne, int colonne) {
 
    for (int sligne = ligne - (ligne % 3); sligne < ligne - (ligne % 3) + 3; sligne++)
        for (int scolonne = colonne - (colonne % 3); scolonne < colonne - (colonne % 3) + 3; scolonne++)
 
            if (grid[sligne][scolonne].value == gridtest)
 
                return false;
    return true;
}
 
Box::~Box()
{
}
