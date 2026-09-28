//
// Created by Agatha on 27.09.2026.
//

#include <cstdlib>
#include <print>

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

int executer_attaque(int attaque, int defense)
{
    int degats = calculer_degats(attaque, defense);
    int jet = lancer_de(10);

    switch (jet)
    {
        case 1:
            std::println("Coup manque! Dommage...");
            degats = 0;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            std::println("Coup normal");
            break;
        case 10:
            std::println("Coup critique! Degats doubles");
            degats *= 2;
            break;
        default:
            break;

    }
    return degats;
}