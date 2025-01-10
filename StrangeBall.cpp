#include "StrangeBall.h"
#include <ctime>

static int randAngle = 90;

void StrangeBall::bounce(const Court& court, const sf::Vector2f& point) {
    //Direction randomizes a bit on every bounce

    _move.x *= -1;
    _move.y *= -1;

    //initialize transformation thing
    sf::Transform VecRotate;

    //Get random angle to rotate movement vector by
    srand(std::time(nullptr));
    float angle = static_cast<float>(std::rand() % randAngle * 2) - randAngle;

    //set the rotation angle
    VecRotate.rotate(angle);

    //apply the transformation
    _move = VecRotate.transformPoint(_move);

}