#ifndef STRANGEBALL_H
#define STRANGEBALL_H

#include "BouncingBall.h"

class StrangeBall : public BouncingBall {
public:
    StrangeBall(sf::Vector2f start, sf::Vector2f mvec, float radius)
        : BouncingBall(start, mvec, radius) {}

    void bounce(const Court& court, const sf::Vector2f& point);
};

#endif STRANGEBALL_H