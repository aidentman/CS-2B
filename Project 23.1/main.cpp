#include <iostream>
#include "Creature.h"
#include "Human.h"
#include "Elf.h"
#include "Demon.h"
#include "Cyberdemon.h"
#include "Balrog.h"
using namespace std;
using namespace cs_creature;

const int NUM_CREATURES = 4;
const int ELF_DEFAULT_STRENGTH = 24;
const int BALROG_DEFAULT_STRENGTH = 10;
const int HUMAN_DEFAULT_STRENGTH = 100;
const int CYBERDEMON_DEFAULT_STRENGTH = 50;
const int DEFAULT_HITPOINTS = 50;

void battle(Creature& Creature1, Creature& Creature2);






int main()
{
//    srand(static_cast<unsigned>(time(nullptr)));

    Elf e(ELF_DEFAULT_STRENGTH, DEFAULT_HITPOINTS);
    Balrog b(BALROG_DEFAULT_STRENGTH, DEFAULT_HITPOINTS);
    Human h(HUMAN_DEFAULT_STRENGTH, DEFAULT_HITPOINTS);
    Cyberdemon c(CYBERDEMON_DEFAULT_STRENGTH, DEFAULT_HITPOINTS);
    Creature* creatures[] = {&b, &e, &c, &h};

    for (int i = 0; i < NUM_CREATURES; i++) {
        for (int j = i + 1; j < NUM_CREATURES; j++) {
            battle(*creatures[i], *creatures[j]);
        }
    }
}






void battle(Creature& Creature1, Creature& Creature2) {
    int Creature1StartHitpoints = Creature1.getHitpoints();
    int Creature2StartHitpoints = Creature2.getHitpoints();

    cout << "*****  Battle between the " << Creature1.getSpecies();
    cout << " and the " << Creature2.getSpecies() << "!!  ******";
    cout << endl << endl;

    while (Creature1.getHitpoints() > 0 && Creature2.getHitpoints() > 0) {
        Creature2.setHitpoints(Creature2.getHitpoints() - Creature1.getDamage());
        Creature1.setHitpoints(Creature1.getHitpoints() - Creature2.getDamage());

        cout << "The " << Creature1.getSpecies() << " has ";
        cout << Creature1.getHitpoints() << " hitpoints." << endl;
        cout << "The " << Creature2.getSpecies() << " has ";
        cout << Creature2.getHitpoints() << " hitpoints." << endl << endl;
    }

    if (Creature1.getHitpoints() > 0) {
        cout << "The " << Creature1.getSpecies() << " wins!";
    } else if (Creature2.getHitpoints() > 0) {
        cout << "The " << Creature2.getSpecies() << " wins!";
    } else {
        cout << "The battle results in a tie!";
    }
    cout << endl << endl << endl;

    Creature1.setHitpoints(Creature1StartHitpoints);
    Creature2.setHitpoints(Creature2StartHitpoints);
}