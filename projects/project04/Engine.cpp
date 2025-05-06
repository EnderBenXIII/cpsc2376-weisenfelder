#include "Engine.h"
#include <SDL2/SDL_ttf.h>
#include <iostream>

Engine::Engine() : window(nullptr), renderer(nullptr), texture(nullptr) {}

Engine::~Engine() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}

void Engine::init() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    TTF_Init();
    window = SDL_CreateWindow("Connect 4", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Engine::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
    SDL_RenderClear(renderer);
}

void Engine::flip() {
    SDL_RenderPresent(renderer);
}

void Engine::drawCircle(int x, int y, int radius, SDL_Color color) {
    filledCircleColor(renderer, x, y, radius, SDL_MapRGB(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), color.r, color.g, color.b));
}

void Engine::drawRectangle(int x, int y, int width, int height, SDL_Color color) {
    SDL_Rect rect = { x, y, width, height };
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}

void Engine::drawText(const std::string& text, int x, int y, SDL_Color color) {
    TTF_Font* font = TTF_OpenFont("Ubuntu-Bold.ttf", 24);
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    
    int textWidth = surface->w;
    int textHeight = surface->h;
    SDL_Rect textRect = { x, y, textWidth, textHeight };
    
    SDL_RenderCopy(renderer, texture, NULL, &textRect);
    TTF_CloseFont(font);
}

void Engine::playSound() {
    Mix_Chunk* sound = Mix_LoadWAV("move.wav");
    if (sound != nullptr) {
        Mix_PlayChannel(-1, sound, 0);  // Play sound
        Mix_FreeChunk(sound);  
}
