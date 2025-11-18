#include "game.h"
#include <iostream>
#include <chrono>
#include <thread>

Game::Game()
    : m_running(false)
{
}

Game::~Game()
{
    if (m_running) {
        shutdown();
    }
}

bool Game::init() {
    // Prepare the game so the loop can run
    std::cout << "Game::init() called" << std::endl;
    m_running = true;
    return true;
}

void Game::run()
{
    using clock = std::chrono::steady_clock;

    auto lastTime = clock::now();
    int frameCount = 0;

    while (m_running) {
        // --- Time step calculation ---
        auto now = clock::now();
        std::chrono::duration<float> dt = now - lastTime;
        lastTime = now;

        float deltaTime = dt.count(); // seconds since last frame

        // // --- Core game loop steps ---
        // handleInput();
        // update(deltaTime);
        // render();

        // --- Temporary stop condition so we don't loop forever yet ---
        frameCount++;
        if (frameCount > 300) { // ~5 seconds at 60 FPS
            std::cout << "Reached 300 frames, exiting.\n";
            m_running = false;
        }

        // --- Simulate ~60 FPS target ---
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    shutdown();
}

void Game::shutdown() {
    std::cout << "Game::shutdown() called." << std::endl;
    m_running = false;

}