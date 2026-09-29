//
// Created by Agatha on 27.09.2026.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mini_combat.h"
#include<print>


int main() {
    std::srand(42);

    // Orc's stats-------------------------------
    int Orc_Pv = 60;
    int Orc_Att = 14;
    int Orc_Def = 4;
    //Troll's stats------------------------------
    int Troll_Pv = 80;
    int Troll_Att = 11;
    int Troll_Def = 6;

    int tours = 1;
    int potions_restantes = 2;
    bool fuir = false;

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
        int action = options_joueur();
        int orc_degats = 0;
        //player make a choice
        switch (action) {
            case 1:
                orc_degats = executer_attaque(Orc_Att, Troll_Def);
                Troll_Pv -= orc_degats;
                // Troll's PV cannot be below 0
                if (Troll_Pv < 0)
                {
                    Troll_Pv = 0;
                }
                if (orc_degats > 0)
                {
                    std::println("L'orc attaque le troll, il lui a cause {} de degats! Troll: {} pv", orc_degats, Troll_Pv);
                }
                break;

            case 2:
                if (potions_restantes > 0) {
                    Orc_Pv += 15;
                    potions_restantes--;
                    std::println("Tu utilise une potion! Tu recuperes 15 pv! Il te restent {} potions, Orc: {} pv",potions_restantes, Orc_Pv);
                }
                else if (potions_restantes <= 0)
                {
                    std::println("Tu n'as plus de potions...");

                }
                break;

            case 3:
                std::println("Vous fuyez le combat!");
                fuir = true;
                break;

            default:
                break;
        }

        if (fuir == true)
        {
            break;
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