#include "Game.hpp"
#include <random>
#include <sstream>

Game::Game() : window(sf::VideoMode(800, 600), "Starfield Navigator"), score(0), isGameOver(false), isPaused(false) {
    window.setFramerateLimit(60);
    starfield = Starfield();
    if (!font.loadFromFile("arial.ttf")) {
        // Note: Ensure arial.ttf is available or handle font loading error
    }
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    gameOverText.setFont(font);
    gameOverText.setCharacterSize(48);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setString("Game Over!");
    gameOverText.setPosition(300, 250);
}

void Game::run() {
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        processEvents();
        if (!isGameOver && !isPaused) {
            update(deltaTime);
        }
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                isPaused = !isPaused;
            }
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
    }
}

void Game::update(float deltaTime) {
    player.handleInput();
    player.update(deltaTime);
    starfield.update(deltaTime);
    
    spawnAsteroids();
    spawnResources();
    
    for (auto& asteroid : asteroids) {
        asteroid.update(deltaTime);
    }
    
    checkCollisions();
    
    std::stringstream ss;
    ss << "Score: " << score;
    scoreText.setString(ss.str());
}

void Game::render() {
    window.clear();
    starfield.render(window);
    player.render(window);
    for (const auto& asteroid : asteroids) {
        asteroid.render(window);
    }
    for (const auto& resource : resources) {
        resource.render(window);
    }
    window.draw(scoreText);
    if (isGameOver) {
        window.draw(gameOverText);
    }
    window.display();
}

void Game::spawnAsteroids() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<float> dist(0, 800);
    static std::uniform_real_distribution<float> speedDist(50, 150);
    
    if (rand() % 100 < 2) { // 2% chance per frame to spawn
        Asteroid asteroid(sf::Vector2f(dist(gen), 0));
        asteroid.update(0); // Initialize with random velocity
        asteroids.push_back(asteroid);
    }
}

void Game::spawnResources() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<float> dist(0, 800);
    
    if (rand() % 100 < 1) { // 1% chance per frame to spawn
        resources.emplace_back(sf::Vector2f(dist(gen), 0));
    }
}

void Game::checkCollisions() {
    sf::FloatRect playerBounds = player.getBounds();
    
    for (auto it = asteroids.begin(); it != asteroids.end();) {
        if (playerBounds.intersects(it->getBounds())) {
            isGameOver = true;
            return;
        }
        if (it->getBounds().top > 600) {
            it = asteroids.erase(it);
        } else {
            ++it;
        }
    }
    
    for (auto it = resources.begin(); it != resources.end();) {
        if (playerBounds.intersects(it->getBounds())) {
            score += 10;
            it = resources.erase(it);
        } else {
            ++it;
        }
    }
}
