#ifndef SUPERPONG_H
#define SUPERPONG_H

#include "Pong.h"

class SuperPong : public Pong {
public:
	SuperPong() {}

	void set2(Paddle* p1) {
		_paddle2 = p1;
	};

	void update();
	void paint(sf::RenderWindow& window);

private:
	Paddle* _paddle2 = nullptr;
};

#endif SUPERPONG_H