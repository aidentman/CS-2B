#include "Balrog.h"
#include "Demon.h"

namespace cs_creature {
    Balrog::Balrog(){
    }






    Balrog::Balrog(int newStrength, int newHitpoints)
    : Demon(newStrength, newHitpoints){
    }






    string Balrog::getSpecies() const{
        return "balrog";
    }






    int Balrog::getDamage() const{
        int damage = Demon::getDamage();
        int damage2 = (rand() % Creature::getStrength()) + 1;
        cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
        damage += damage2;
        return damage;
    }
}