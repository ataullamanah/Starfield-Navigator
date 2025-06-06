#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <SFML/Graphics.hpp>

class Asteroid {
public:
    Asteroid(sf::Vector2f position);
    void update(float deltaTime);
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
};

#endif
