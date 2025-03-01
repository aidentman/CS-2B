#include <iostream>
#include <string>
#include "Creature.h"
using namespace std;

namespace cs_creature {
    Creature::Creature(){
        strength = DEFAULT_STRENGTH;
        hitpoints = DEFAULT_HITPOINTS;
    }// initialize to human, 10 strength, 10 hitpoints






    Creature::Creature(int newStrength, int newHitpoints){
        strength = newStrength;
        hitpoints = newHitpoints;
    }






    int Creature::getDamage() const{
        int damage;
        // All Creatures inflict damage which is a random number up to their strength
        damage = (rand() % strength) + 1;
        cout << "The " << getSpecies() << " attacks for ";
        cout << damage << " points!" << endl;
        return damage;
    }






    int Creature::getStrength() const {
        return strength;
    }






    int Creature::getHitpoints() const {
        return hitpoints;
    }






    void Creature::setStrength(int newStrength){
        strength = newStrength;
    }






    void Creature::setHitpoints(int newHitpoints){
        hitpoints = newHitpoints;
    }
}