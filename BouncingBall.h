#ifndef BOUNCINGBALL_H
#define BOUNCINGBALL_H

#include <SFML/Graphics.hpp>

class Court;
class Paddle;

class BouncingBall
{
public:
    BouncingBall(sf::Vector2f start, sf::Vector2f mvec, float radius =10);
    ~BouncingBall() = default;
    /* --Aktualisiere die Position. */
    void update();
    /* --Liefert den Radius zurueck. */
    float radius() const
    {
        return _radius;
    }/* --Liefert den Mittelpunkt zur�ck. */
    sf::Vector2f center() const
    {
        return _position;
    }/* --Liefert den Bewegungsvektor zur�ck. */
    sf::Vector2f move() const
    {
        return _move;
    }/* --Abprallen von Objekten. */
    virtual void bounce(const Court& court,const sf::Vector2f& point);
    virtual void bounce(const Paddle& paddle,const sf::Vector2f& point);
    /* --Zeichnen. */
    void paint(sf::RenderWindow& window);

    /* Reseten: */
    void reset()
    {
        _position = _initPosition;
    }


protected:
    /* --Radius. */
    float _radius;
    /* --Ortsvektor. */
    sf::Vector2f _position;
    const sf::Vector2f _initPosition;
    /* --Bewegungsvektor. */
    sf::Vector2f _move;
};


#endif // BOUNCINGBALL_H
