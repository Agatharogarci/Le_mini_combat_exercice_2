//
// Created by Agatha on 27.09.2026.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mini_combat.h"
#include<print>


int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

// Orc's stats-------------------------------
    int Orc_Pv = 60;
    int Orc_Att = 14;
    int Orc_Def = 4;
//Troll's stats------------------------------
    int Troll_Pv = 80;
    int Troll_Att = 11;
    int Troll_Def = 6;

    int tours = 1;


    for (int i = 0; i < 10; i++)
    {
        std::println("Jet : {}", lancer_de(6));
    }



// Tour 1 -------------------------------------

    do
    {
        //How many rounds have we donne
        std::println(" ------------------");
        std::println("Tour {}!", tours);
        std::println(" ------------------");
        tours++;
        if (tours >= 100)
        {
            std::println("Tour {}! Match null!", tours);
            break;
        }
        //Orc's damage is calculated
        int orc_degats = executer_attaque(Orc_Att, Troll_Def);
        Troll_Pv -= orc_degats;

        // Troll's PV cannot be below 0
        if (Troll_Pv < 0)
        {
            Troll_Pv = 0;
        }
        if (orc_degats == 0)
        {
        }


        else
        {
            std::println("L'orc attaque le troll, il lui a cause {} de degats! Troll: {} pv", orc_degats, Troll_Pv);
        }

        //We exit the loop if Troll's pv are 0
        if (Troll_Pv <= 0)
        {
            std::println("Le troll est mort! L'orc a gagne en {} tours", tours);
            break;
        }
        //Troll's damage is calculated
        int troll_degats = executer_attaque(Troll_Att, Orc_Def);
        Orc_Pv -= troll_degats;


        // Orc's PV cannot be below 0
        if (Orc_Pv < 0)
        {
            Orc_Pv = 0;
        }
        if (troll_degats == 0)
        {
        }
        else
        {
            std::println("Le troll attaque l'orc, il lui a cause {}  de degats! Orc : {} pv", troll_degats, Orc_Pv);
        }
        //We exit the loop if Orc's pv are 0
        if (Orc_Pv <= 0)
        {
            std::println("L'orc est mort! Le troll a gagne en {} tours", tours);
            break;
        }
    }while (Troll_Pv > 0 && Orc_Pv > 0);

















    return 0;
}