#include <iostream>
#include <string>
#include "Human.h"
#include "Creature.h"
using namespace std;

namespace cs_creature {
    Human::Human(){
    }






    Human::Human(int newStrength, int newHitpoints)
    : Creature(newStrength, newHitpoints){
    }






    string Human::getSpecies() const{
        return "human";
    }






    int Human::getDamage() const{
        int damage = Creature::getDamage();
        cout << "The human attacks for " << damage << " points!" << endl;
        return damage;
    }
}