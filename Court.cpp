#include "Court.h"
#include "BouncingBall.h"

#include "SFML/Graphics.hpp"


Court::Court(Area field) : _field(field)
{

}


Court::Edge Court::hasCollision(const BouncingBall& ball,sf::Vector2f& point) const
{
    Court::Edge edge = Court::Edge::None;
    sf::Vector2f ballCenter = ball.center();

    if (ballCenter.y - ball.radius() <= _field.top)
        edge = Court::Edge::Top;
    if (ballCenter.y + ball.radius() >= _field.top + _field.height)
        edge = Court::Edge::Bottom;

    if (ballCenter.x + ball.radius() >= _field.left + _field.width)
        edge = Court::Edge::Right;
    if (ballCenter.x - ball.radius() <  _field.left)
        edge = Court::Edge::Left;

    point = ballCenter;
    return edge;
}

void Court::paint(sf::RenderWindow& window)
{
    sf::RectangleShape rect(sf::Vector2f(area().width, area().height));
    rect.setPosition(sf::Vector2f(_field.left,_field.top));
    rect.setFillColor(sf::Color::Green);
    window.draw(rect);
}
