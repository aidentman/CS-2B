#include <iostream>
#include <string>
#include "Elf.h"
#include "Creature.h"
using namespace std;

namespace cs_creature {
    Elf::Elf(){
    }






    Elf::Elf(int newStrength, int newHitpoints)
    : Creature(newStrength, newHitpoints){
    }






    string Elf::getSpecies() const{
        return "elf";
    }






    int Elf::getDamage() const{
        int damage = Creature::getDamage();
        if (rand() % 100 * 0.01 < MAGICAL_ATTACK_PROBABILITY) {
            cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
            damage *= MAGICAL_ATTACK_MULTIPLIER;
        }
        return damage;
    }
}