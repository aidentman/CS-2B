#ifndef DEMON_H
#define DEMON_H
#include <iostream>
#include <string>
#include "Demon.h"
#include "Creature.h"
using namespace std;

namespace cs_creature {
    class Demon : public Creature {
        private:
            static constexpr double DEMONIC_ATTACK_PROBABILITY = 0.25;
            static const int DEMONIC_BONUS_DAMAGE = 50;

        public:
            Demon();
            Demon(int newStrength, int newHitpoints);
            string getSpecies() const override;
            int getDamage() const override;
    };
}

#endif //DEMON_H
