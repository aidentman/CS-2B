#include <iostream>
#include "Cyberdemon.h"
#include "Demon.h"
using namespace std;

namespace cs_creature {
    Cyberdemon::Cyberdemon(){
    }






    Cyberdemon::Cyberdemon(int newStrength, int newHitpoints)
    : Demon(newStrength, newHitpoints){
    }






    string Cyberdemon::getSpecies() const{
        return "cyberdemon";
    }






    int Cyberdemon::getDamage() const{
        cout << "The cyberdemon";
        int damage = Demon::getDamage();
        return damage;
    }
}