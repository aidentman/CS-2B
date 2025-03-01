#ifndef ELF_H
#define ELF_H
#include <iostream>
#include <string>
#include "Creature.h"

namespace cs_creature {
    class Elf : public Creature{
        private:
            static constexpr double MAGICAL_ATTACK_PROBABILITY = 0.5;
            static constexpr double MAGICAL_ATTACK_MULTIPLIER = 2.0;

        public:
            Elf();
            Elf(int newStrength, int newHitpoints);
            string getSpecies() const;
            int getDamage() const;
    };
}
#endif //ELF_H
