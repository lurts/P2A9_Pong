#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class BouncingBall;

class Paddle
{
public:
    enum class PaddleType { Left, Right };


    Paddle(sf::Vector2f pos,
           float top,
           float bottom,
           float len,
           float width,
           float incr = 10,
           PaddleType typ = PaddleType::Right);
    ~Paddle() = default;
    /* --Auf-/Abwaertsbewegung. */
    void up();
    void down();
    /* --Zeichnen. */
    void paint(sf::RenderWindow& window);
    /* --Pruefen, ob Kollision mit Ball. */
    bool hasCollision(const BouncingBall& ball,sf::Vector2f& point) const;
    sf::Vector2f position() const
    {
        return _position;
    }
    float length() const
    {
        return _length;
    }
    PaddleType type() const
    {
        return _type;
    }

protected:
    /* --Position (obere Kante). */
    sf::Vector2f _position;
    /* --Wertebereich der y-Position. */
    float _top;
    float _bottom;
    /* --Laenge, Bewegungsinkrement/Update. */
    float _length;
    float _width;
    float _increment;


    /* --Seite des Schlaegers. */
    PaddleType _type;


};


#endif // PADDLE_H
