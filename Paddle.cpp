#include "Paddle.h"
#include "BouncingBall.h"

Paddle::Paddle(sf::Vector2f pos,
           float top,
           float bottom,
           float len,
           float width,
           float incr,
           PaddleType typ) :
    _position(pos),
    _top(top),
    _bottom(bottom),
    _length(len),
    _width(width),
    _increment(incr),
    _type(typ)
{
    //ctor
}

void Paddle::up()
{
    if(_position.y - _increment > _top )
    {
        _position.y -= _increment;
    }
    else
    {
        _position.y = _top;
    }
}

void Paddle::down()
{
    if(_position.y + _increment < _bottom - _length )
    {
        _position.y += _increment;
    }
    else
    {
        _position.y = _bottom - _length;
    }
}


void Paddle::paint(sf::RenderWindow& window)
{
    sf::RectangleShape rect(sf::Vector2f(_width,length()));  // assume width with 10 pixel?
    rect.setPosition(position());
    rect.setFillColor(sf::Color::Blue);
    window.draw(rect);
}


bool Paddle::hasCollision(const BouncingBall& ball,sf::Vector2f& point) const
{
    bool isCollision = false;
    if(_type == PaddleType::Left)
    {
        float xPos = ball.center().x - ball.radius();
        float yPos = ball.center().y;
        if(xPos < position().x + _width)
        {
            if (yPos > position().y && yPos < position().y + _length)
            {
                isCollision = true;
            }
        }
    }
    if(_type == PaddleType::Right)
    {
        float xPos = ball.center().x + ball.radius();
        float yPos = ball.center().y;
        if(xPos > position().x)
        {
            if (yPos > position().y && yPos < position().y + _length)
            {
                isCollision = true;
            }
        }
    }
    return isCollision;
}
