#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <string>
using namespace std;

namespace cs_creature{
    class Creature {
    private:
        int strength;                 // how much damage this Creature inflicts
        int hitpoints;                // how much damage this Creature can sustain

        static const int DEFAULT_STRENGTH = 10;
        static const int DEFAULT_HITPOINTS = 10;

    public:
        Creature();                   // initialize to human, 10 strength, 10 hitpoints
        Creature(int newStrength, int newHitpoints);
        int getDamage() const;
        string getSpecies() const;
        int getStrength() const;
        int getHitpoints() const;
        void setStrength(int newStrength);
        void setHitpoints(int newHitpoints);
    };
}

#endif //CREATURE_H