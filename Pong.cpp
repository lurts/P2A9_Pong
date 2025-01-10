#include "Pong.h"
#include "Court.h"
#include "Paddle.h"
#include "BouncingBall.h"

#include <SFML/Graphics.hpp>

Pong::Pong()
{

}

Pong::~Pong()
{
    delete _ball;
    delete _court;
    delete _paddle;
}

void Pong::paint(sf::RenderWindow& window)
{
    //window.clear();
    // paint Court:
    _court->paint(window);

    // paint Paddle:
    _paddle->paint(window);

    // paint ball:
    _ball->paint(window);
}

void Pong::update()
{
    _ball->update();

    // Check for collision with court:
    sf::Vector2f vec(0,0);
    bool isPaddleCollision = _paddle->hasCollision(*_ball, vec);
    if(isPaddleCollision)
    {
        _ball->bounce(*_paddle,vec);
    }

    else
    {
        Court::Edge collision = _court->hasCollision(*_ball, vec);
        if(collision != Court::Edge::None)
        {
            _ball->bounce(*_court,vec);
        }
        if (collision == Court::Edge::Right)
        {
            done = true;
        }

    }
}

void Pong::set(Paddle* p)
{
    if(p->type() == Paddle::PaddleType::Right)
    {
        _paddle=p;
    }
}

