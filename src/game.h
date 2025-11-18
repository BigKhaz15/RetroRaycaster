#pragma once

// Game is responsible for:
// - initializing the game
// - running the main loop
// - shutting everything down cleanly
class Game {
public:
    Game();             // constructor
    ~Game();            // destructor

    // Set up the game. Returns false if something fails during init.
    bool init();

    // Main game loop. This will keep running until the game decides to stop.
    void run();

    // Clean up resources. Safe to call multiple times.
    void shutdown();

private:
    bool m_running;     // true while the main loop should keep running

    // These will be filled in later, but we declare them now so the structure is clear.
    void handleInput();     // read user input (keyboard, etc.)
    void update(float dt);  // advance game state by dt seconds
    void render();          // draw the current frame
};
