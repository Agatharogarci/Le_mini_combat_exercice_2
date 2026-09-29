//
// Created by Agatha on 27.09.2026.
//

#include <cstdlib>
#include <iostream>
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

int options_joueur()
{
    int choix = 0;
    do {
        std::println("Que voulez vous faire? [1. Attaque | 2. Potion | 3. Fuir]");
        std::cin >> choix;
        if (choix < 1 || choix > 3)
        {
            std::println("Choix invalide, recommence!");
        }
    }while (choix < 1 || choix > 3);
    return choix;
}