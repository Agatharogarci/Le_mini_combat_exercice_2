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

        //Orc's damage is calculated
        int degats_orc = 0;
        int jet_orc = lancer_de(10);

        switch (jet_orc)
        {
            case 1:
                degats_orc = 0;
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
                degats_orc = calculer_degats(Orc_Att, Orc_Def);
                Troll_Pv -= degats_orc;
                break;
            case 10:
                std::println("Coup critique!Degats doubles");
                degats_orc = calculer_degats(Orc_Att, Orc_Def) * 2;
                Troll_Pv -= degats_orc;
                break;
            default:
                break;
        }
        // Troll's PV cannot be below 0
        if (Troll_Pv < 0)
        {
            Troll_Pv = 0;
        }

        if (jet_orc == 1) {
            std::println("Dommage! L'orc a manque son coup!");
        }
        else
        {
            std::println("L'orc attaque le troll, il lui a cause {} de degats! Troll: {} pv", degats_orc, Troll_Pv);
        }

        //We exit the loop if Troll's pv are 0
        if (Troll_Pv <= 0)
        {
            std::println("Le troll est mort! L'orc a gagne");
            break;
        }
        //Troll's damage is calculated
        int degats_troll  = 0;
        int jet_troll = lancer_de(10);

        switch (jet_troll)
        {
            case 1:
                std::println("Dommage! Le troll a manque son coup!");
                degats_troll = 0;
                continue;
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                std::println("Coup normal");
                degats_troll = calculer_degats(Troll_Att, Troll_Def);
                Orc_Pv -= degats_troll;
                break;
            case 10:
                std::println("Coup critique! Degats doubles");
                degats_troll = calculer_degats(Troll_Att, Troll_Def) * 2;
                Orc_Pv -= degats_troll;
                break;
            default:
                break;
        }

        // Orc's PV cannot be below 0
        if (Orc_Pv < 0)
        {
            Orc_Pv = 0;
        }
        std::println("Le troll attaque l'orc, il lui a cause {} de degats! Orc : {} pv", degats_troll, Orc_Pv);
        //We exit the loop if Orc's pv are 0
        if (Orc_Pv <= 0)
        {
            std::println("L'orc est mort! Le troll a gagne");
            break;
        }
    }while (Troll_Pv > 0 && Orc_Pv > 0);

















    return 0;
}