#ifndef CRAZYBALL_H
#define CRAZYBALL_H

#include "BouncingBall.h"

class CrazyBall : public BouncingBall {
public:
    CrazyBall(sf::Vector2f start, sf::Vector2f mvec, float radius)
        : BouncingBall(start, mvec, radius) {}

    void bounce(const Court& court, const sf::Vector2f& point);
};

#endif CRAZYBALL_H