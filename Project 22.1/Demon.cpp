#include <iostream>
#include <string>
#include "Demon.h"
#include "Creature.h"
using namespace std;

namespace cs_creature {
    Demon::Demon(){
    }






    Demon::Demon(int newStrength, int newHitpoints)
    : Creature(newStrength, newHitpoints){
    }






    string Demon::getSpecies() const{
        return "Demon";
    }






    int Demon::getDamage() const{
        int damage = Creature::getDamage();
        cout << " attacks for " << damage << " points!" << endl;
        if (rand() % 100 * 0.01 < DEMONIC_ATTACK_PROBABILITY) {
            damage = damage + DEMONIC_BONUS_DAMAGE;
            cout << "Demonic attack inflicts " << DEMONIC_BONUS_DAMAGE << " additional damage points!" << endl;
        }
        return damage;
    }
}