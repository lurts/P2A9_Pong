#include "BouncingBall.h"
#include "Court.h"
#include "Paddle.h"
#include <SFML/Graphics.hpp>

BouncingBall::BouncingBall(sf::Vector2f start,
                           sf::Vector2f mvec,
                           float radius) :
    _radius(radius),
    _position(start),
    _initPosition(start),
    _move(mvec)
{

}


void BouncingBall::update()
{
    // move yourself....
    _position += _move;

}


void BouncingBall::paint(sf::RenderWindow& window)
{
    sf::CircleShape _circle;
    _circle.setRadius(radius());
    _circle.setFillColor(sf::Color::Red);

    /* --Den Kreismittelpunkt setzen. */
    _circle.setPosition(sf::Vector2f(center()));

    /* --Zeichne den Kreis. */
    window.draw(_circle);
}

void BouncingBall::bounce(const Court& court,const sf::Vector2f& point)
{
    if(point.x + radius() >= court.area().width)   // Collision to left
    {
      _move.x = -_move.x;
    }
    if(point.x - radius() <= court.area().left)   // Collision to left
    {
      _move.x = -_move.x;
    }
    if(point.y + radius() >= court.area().height)   // Collision to bottom
    {
      _move.y = -_move.y;
    }
    if(point.y - radius() <= court.area().top)   // Collision to left
    {
      _move.y = -_move.y;
    }

}

void BouncingBall::bounce(const Paddle& paddle,const sf::Vector2f& point)
{
    // calculate angle:
    float maxYdeflection = abs(_move.x) * 2;
    //float yMoveDirection = _move.y > 0 ? -1.f : 1.f;

    _move = -_move;

    float diff = (_position.y - (paddle.position().y + paddle.length()/2))/paddle.length();
    _move.y += maxYdeflection * diff;
    _move.y = _move.y > 0 ? _move.y > maxYdeflection ? maxYdeflection : _move.y : _move.y < -maxYdeflection ? -maxYdeflection : _move.y;

}
