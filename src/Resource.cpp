#include "Resource.hpp"

Resource::Resource(sf::Vector2f position) {
    shape.setRadius(10.0f);
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Green);
}

void Resource::render(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Resource::getBounds() const {
    return shape.getGlobalBounds();
}
