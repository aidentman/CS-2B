#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include <string>
#include "Creature.h"

namespace cs_creature {
    class Human : public Creature{
        public:
            Human();
            Human(int newStrength, int newHitpoints);
            string getSpecies() const;
            int getDamage() const;
    };
}
#endif //HUMAN_H
