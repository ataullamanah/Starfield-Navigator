#include "Asteroid.hpp"
#include <random>

Asteroid::Asteroid(sf::Vector2f position) {
    shape.setRadius(20.0f);
    shape.setPointCount(8);
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Red);
    
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<float> speedDist(50, 150);
    velocity = sf::Vector2f(0, speedDist(gen));
}

void Asteroid::update(float deltaTime) {
    shape.move(velocity * deltaTime);
}

void Asteroid::render(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Asteroid::getBounds() const {
    return shape.getGlobalBounds();
}
