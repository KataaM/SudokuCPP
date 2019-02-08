#include "Box.h"
#include <iostream>
#include <list>
#include <ctime>
 
 
void CreateSudoku(Box grid[9][9], Box box, int gridwin[9][9]) {
    srand(time(NULL));
    for (int ligne = 0; ligne < 9; ligne++)
        for (int colonne = 0; colonne < 9; colonne++)
        {
            auto GenerateBox = new Box(0);
            grid[ligne][colonne] = *GenerateBox;
        }
 
    for (int ligne = 0; ligne < 9; ligne++)
        for (int colonne = 0; colonne < 9; colonne++)
        {
            int gridtest = rand() % 9 + 1;
 
            bool testLigne = box.PossibleLigne(grid, gridtest, ligne);
            bool testColonne = box.PossibleColonne(grid, gridtest, colonne);
            bool testCarre = box.PossibleCarre(grid, gridtest, ligne, colonne);
 
            if (testLigne == true && testCarre == true && testColonne == true)
            {
                grid[ligne][colonne].value = gridtest;
            }
            else if (testLigne == false || testCarre == false || testColonne == false)
            {
                int p = 0;
                for (int value = 1; value < 10; value++)
                {
                    gridtest = value;
                    bool testLigne = box.PossibleLigne(grid, gridtest, ligne);
                    bool testColonne = box.PossibleColonne(grid, gridtest, colonne);
                    bool testCarre = box.PossibleCarre(grid, gridtest, ligne, colonne);
 
                    if (testLigne == true && testCarre == true && testColonne == true)
                    {
                        grid[ligne][colonne].value = gridtest;
                    }
                    else if (testLigne == false || testCarre == false || testColonne == false)
                    {
                        p++;
                    }
                }
                if (p == 9)
                {
                    for (int a = 0; a < 9; a++)
                        for (int b = 0; b < 9; b++) {
                            grid[a][b].value = 0;
                        }
                    ligne = 0;
                    colonne = -1;
                }
            }
        }
    for (int a = 0; a < 9; a++)
        for (int b = 0; b < 9; b++) {
            gridwin[a][b] = grid[a][b].value;
        }
    box.Difficulty(grid);
}
 
void Gameplay(Box grid[9][9], Box box) {
    int ligne;
    int colonne;
    int choix;
    int x = 0;
    std::cout << "Veuillez choisir une ligne :  ";
    std::cin >> ligne;
    std::cout << "Veuillez choisir une colonne : ";
    std::cin >> colonne;
 
    while (1 > colonne || 9 < colonne || 1 > ligne || 9 < ligne) {
        std::cout << "Veuillez choisir une ligne : ";
        std::cin >> ligne;
        std::cout << "Veuillez choisir une colonne : ";
        std::cin >> colonne;
    }
 
    bool canchange = box.CanChange(grid, ligne - 1, colonne - 1);
    x++;
    if (x == 1) {
        while (canchange != true) {
            std::cout << "Vous ne pouvez pas choisir cette case ! \n Veuillez choisir une ligne : ";
            std::cin >> ligne;
            std::cout << "Veuillez choisir une colonne : ";
            std::cin >> colonne;
            while (1 > colonne || 9 < colonne || 1 > ligne || 9 < ligne) {
                std::cout << "Veuillez choisir une ligne : ";
                std::cin >> ligne;
                std::cout << "Veuillez choisir une colonne : ";
                std::cin >> colonne;
            }
            canchange = box.CanChange(grid, ligne - 1, colonne - 1);
        }
    }
    std::cout << "Quel chiffre voulez vous inserez ? : ";
    std::cin >> choix;
    while (1 > choix || 9 < choix) {
        std::cout << "Veuillez choisir une ligne : ";
        std::cin >> ligne;
        std::cout << "Veuillez choisir une colonne : ";
        std::cin >> colonne;
    }
    grid[ligne - 1][colonne - 1].value = choix;
}
 
bool Win(Box grid[9][9], int gridwin[9][9]) {
    int winnable = 0;
    for (int a = 0; a < 9; a++)
        for (int b = 0; b < 9; b++) {
            if (grid[a][b].value == gridwin[a][b]) {
                winnable++;
            }
        }
    if (winnable == 81) {
        return true;
    }
    else {
        return false;
    }
}
void Affichage(Box grid[9][9], int gridwin[9][9]) {
    for (int ligne = 0; ligne < 9; ligne++)
    {
        for (int colonne = 0; colonne < 9; colonne++)
        {
            if (grid[ligne][colonne].value == 0) {
                if (colonne == 2)
                    std::cout << "[" << '-' << "]" << " ";
                else if (colonne == 5)
                    std::cout << "[" << '-' << "]" << " ";
                else if (colonne == 8)
                    std::cout << "[" << '-' << "]" << std::endl;
                else
                    std::cout << "[" << '-' << "]";
                if (colonne == 8 && ligne == 2 | ligne == 5 | ligne == 8)
                    std::cout << " " << std::endl;
            }
            else {
                if (colonne == 2)
                    std::cout << "[" << grid[ligne][colonne].value << "]" << " ";
                else if (colonne == 5)
                    std::cout << "[" << grid[ligne][colonne].value << "]" << " ";
                else if (colonne == 8)
                    std::cout << "[" << grid[ligne][colonne].value << "]" << std::endl;
                else
                    std::cout << "[" << grid[ligne][colonne].value << "]";
                if (colonne == 8 && ligne == 2 | ligne == 5 | ligne == 8)
                    std::cout << " " << std::endl;
            }
 
        }
    }
}
 
 
int main()
{
    Box grid[9][9] = {};
    int gridwin[9][9] = {};
    Box box;
    CreateSudoku(grid, box, gridwin);
    Affichage(grid, gridwin);
    bool b = Win(grid, gridwin);
    while (b != true) {
        Gameplay(grid, box);
        Affichage(grid, gridwin);
        b = Win(grid, gridwin);
    }
    std::cout << "Bien jouer vous avez gagnez ! " << std::endl;
    system("PAUSE");
}
