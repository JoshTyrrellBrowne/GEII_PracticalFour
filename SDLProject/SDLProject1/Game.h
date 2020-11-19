#pragma once

#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <SDL_image.h>
#include "Defines.h"
#include "AnimatedSprite.h"
#include "Player.h"

class Game {
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running();
private:
	bool isRunning;
	SDL_Window* m_SDLwindow;
	SDL_Renderer* m_SDLrenderer;

	gpp::Events input;
	// Setup Players Default Animated Sprite
	AnimatedSprite* player_animated_sprite;
	Player* player;
	SDL_Texture* player_texture;

	int m_count;
};