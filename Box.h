#pragma once
class Box
{
public:
    Box();
    Box(int _value);
    bool PossibleCarre(Box grid[9][9], int gridtest, int ligne, int colonne);
    bool PossibleLigne(Box grid[9][9], int gridtest, int ligne);
    bool PossibleColonne(Box grid[9][9], int gridtest, int colonne);
    void Difficulty(Box grid[9][9]);
    bool CanChange(Box grid[9][9], int ligne, int colonne);
    ~Box();
 
    int value;
    bool canchange;
};
