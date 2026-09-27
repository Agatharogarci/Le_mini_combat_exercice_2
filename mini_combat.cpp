//
// Created by Agatha on 27.09.2026.
//

#include <cstdlib>

int lancer_de(int faces)
{
    return std::rand() % faces + 1;
}


int calculer_degats(int attaque, int defense)
{
   int degats =  attaque + lancer_de(6) - defense;

    if (degats < 0)
    {
        degats = 0;
    }
    return degats;
}