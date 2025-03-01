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
}