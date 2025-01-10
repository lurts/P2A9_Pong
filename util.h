#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#ifdef _WIN32
/* --Schrift für Windows-System. */
#define FONT "C:/Windows/Fonts/arial.ttf"
//#define FONT "C:/Windows/Fonts/freescpt.ttf"
#elif __linux__
#define FONT "/usr/share/fonts/truetype/freefont/FreeMono.ttf"
#else
#error undefined OS
#endif // LINUX

const sf::Color Mausgrau(200, 200, 200);

void showText(const sf::String& ,const sf::Font& ,sf::RenderWindow&);

#endif // UTIL_H_INCLUDED
