#include "game.h"
#include <SDL2/SDL.h>
#include <iostream>

void render_text(SDL_Renderer* renderer, const std::string& message) {
    std::cout << message << std::endl;
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to init SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Connect Four",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool quit = false;
    SDL_Event e;
    Game game;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                quit = true;

            if (e.type == SDL_MOUSEBUTTONDOWN && game.status() == ONGOING) {
                int x = e.button.x;
                int col = x / CELL_SIZE;
                game.play(col);
            }

            if (e.type == SDL_KEYDOWN && game.status() != ONGOING) {
                if (e.key.keysym.sym == SDLK_r) {
                    game = Game(); // Replay
                }
            }
        }

        game.draw(renderer);

        if (game.status() == PLAYER_1_WINS) {
            render_text(renderer, "Player 1 Wins! Press 'R' to replay.");
        } else if (game.status() == PLAYER_2_WINS) {
            render_text(renderer, "Player 2 Wins! Press 'R' to replay.");
        } else if (game.status() == DRAW) {
            render_text(renderer, "It's a Draw! Press 'R' to replay.");
        }

        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
