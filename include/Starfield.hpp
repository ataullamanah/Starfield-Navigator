#ifndef STARFIELD_HPP
#define STARFIELD_HPP

#include <SFML/Graphics.hpp>

class Starfield {
public:
    Starfield();
    void update(float deltaTime);
    void render(sf::RenderWindow& window);

private:
    std::vector<sf::CircleShape> stars;
    std::vector<sf::Vector2f> velocities;
};

#endif
