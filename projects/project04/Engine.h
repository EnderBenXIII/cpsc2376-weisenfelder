#pragma once
#include <SDL2/SDL.h>
#include <string>

class Engine {
public:
    Engine();
    ~Engine();

    void init();
    void clear();
    void flip();
    void drawCircle(int x, int y, int radius, SDL_Color color);
    void drawRectangle(int x, int y, int width, int height, SDL_Color color);
    void drawText(const std::string& text, int x, int y, SDL_Color color);
    void playSound();
    SDL_Renderer* getRenderer() const;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
};
