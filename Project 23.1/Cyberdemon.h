#ifndef CYBERDEMON_H
#define CYBERDEMON_H
#include <iostream>
#include <string>
#include "Demon.h"

namespace cs_creature {
    class Cyberdemon : public Demon{
    public:
        Cyberdemon();
        Cyberdemon(int newStrength, int newHitpoints);
        string getSpecies() const override;
    };
}



#endif //CYBERDEMON_H
