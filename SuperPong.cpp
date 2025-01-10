#include "SuperPong.h"
#include "Court.h"
#include "Paddle.h"
#include "BouncingBall.h"
#include <SFML/Graphics.hpp>

void SuperPong::update() {
	_ball->update();

	bool rightPaddleCollision	= false;
	bool leftPaddleCollision	= false;

	sf::Vector2f vec(0, 0);

	rightPaddleCollision = _paddle->hasCollision(*_ball, vec);

	// wenn _paddle2 gesetzt dann mehrspieler und wir müssen collisions prüfen
	if (_paddle2 != nullptr) {
		leftPaddleCollision = _paddle2->hasCollision(*_ball, vec);
	}

	if (rightPaddleCollision) {
		_ball->bounce(*_paddle, vec);
	}
	else if (leftPaddleCollision) {
		_ball->bounce(*_paddle2, vec);
	}
	else {
		Court::Edge collision = _court->hasCollision(*_ball, vec);
		if (collision != Court::Edge::None) {
			_ball->bounce(*_court, vec);
		}
		if (collision == Court::Edge::Right) {
			done = true;
		}
		// im zweispielermodus soll kontakt mit der linken seite auch das spiel beenden
		if (collision == Court::Edge::Left && _paddle2 != nullptr) {
			done = true;
		}
	}
}

void SuperPong::paint(sf::RenderWindow& window) {
	Pong::paint(window);
	if (_paddle2 != nullptr) {
		_paddle2->paint(window);
	}
}