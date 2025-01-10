#include "CrazyBall.h"

void CrazyBall::bounce(const Court& court, const sf::Vector2f& point) {
    //Ball accelerates with every bounce
    BouncingBall::bounce(court, point);

    _move.x *= 1.1f;
    _move.y *= 1.1f;
}