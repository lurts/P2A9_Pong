#ifndef STRANGEBALL_H
#define STRANGEBALL_H

#include "BouncingBall.h"

// StrangeBall hat bei jeder Court Kollision eine chance in eine unerwartete Richtung zu fliegen
class StrangeBall : public BouncingBall {
public:
    StrangeBall(sf::Vector2f start, sf::Vector2f mvec, float radius)
        : BouncingBall(start, mvec, radius) {}

    void bounce(const Court& court, const sf::Vector2f& point);
};

#endif STRANGEBALL_H