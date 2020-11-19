#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
	IMG_Quit();
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	SDL_Init(SDL_INIT_VIDEO);
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialised" << std::endl;

		m_SDLwindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (m_SDLwindow)
		{
			std::cout << "Window created" << std::endl;
		}

		m_SDLrenderer = SDL_CreateRenderer(m_SDLwindow, -1, 0);
		if (m_SDLrenderer)
		{
			SDL_SetRenderDrawColor(m_SDLrenderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	} // end SDL initialise

	// Load a sprite to display
	if ((IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG))
	{
		std::cerr << "Failed to initialise SDL_image" << std::endl;
		isRunning = false; // dont run if error
	}

	player_texture = IMG_LoadTexture(m_SDLrenderer, PLAYER_SPRITES);
	if (!player_texture) {
		std::cerr << "Failed to initialise texture" << std::endl;
		std::cout << IMG_GetError();
	}
	
	SDL_Rect textureRect;
	textureRect.x = 0;
	textureRect.y = 0;
	textureRect.w = 7206;
	textureRect.h = 6792;
	player_animated_sprite = new AnimatedSprite(*player_texture, textureRect, m_SDLrenderer);
	player = new Player(*player_animated_sprite);

}

void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			// Died Event
			if (event.key.keysym.sym == SDLK_d) {
				DEBUG_MSG("gpp::Events::Event::DIED_EVENT");
				input.setCurrent(gpp::Events::Event::DIED_EVENT);
			}
			// Revieved Event
			else if (event.key.keysym.sym == SDLK_r) {
				DEBUG_MSG("gpp::Events::Event::REVIVED_EVENT");
				input.setCurrent(gpp::Events::Event::REVIVED_EVENT);
			}
			// Running attack
			else if (event.key.keysym.sym == SDLK_z
				&&
				event.key.keysym.sym == SDLK_RIGHT)
			{
				DEBUG_MSG("gpp::Events::Event::ATTACK_START");
				input.setCurrent(gpp::Events::Event::ATTACK_START_EVENT);
			}
			// Attack
			else if (event.key.keysym.sym == SDLK_z)
			{
				DEBUG_MSG("gpp::Events::Event::ATTACK_START_EVENT");
				input.setCurrent(gpp::Events::Event::ATTACK_START_EVENT);
			}
			// Throw attack
			else if (event.key.keysym.sym == SDLK_x
				&&
				event.key.keysym.sym == SDLK_RIGHT)
			{
				DEBUG_MSG("gpp::Events::Event::THROW_START_EVENT");
				input.setCurrent(gpp::Events::Event::THROW_START_EVENT);
			}
			// Throw Attack
			else if (event.key.keysym.sym == SDLK_x)
			{
				DEBUG_MSG("gpp::Events::Event::THROW_START_EVENT");
				input.setCurrent(gpp::Events::Event::THROW_START_EVENT);
			}
			// Run Right
			else if (event.key.keysym.sym == SDLK_RIGHT)
			{
				DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
				input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
			}
			// Climb Up
			else if (event.key.keysym.sym == SDLK_UP)
			{
				DEBUG_MSG("gpp::Events::Event::MOVE_UP_START_EVENT");
				input.setCurrent(gpp::Events::Event::MOVE_UP_START_EVENT);
			}
			// Climb Down
			else if (event.key.keysym.sym == SDLK_DOWN)
			{
				DEBUG_MSG("gpp::Events::Event::MOVE_DOWN_START_EVENT");
				input.setCurrent(gpp::Events::Event::MOVE_DOWN_START_EVENT);
			}
			// Hit Bottom of Ladder Event
			else if (event.key.keysym.sym == SDLK_c)
			{
				DEBUG_MSG("gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT");
				input.setCurrent(gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT);
			}
			// Hit Top of Ladder Event
			else if (event.key.keysym.sym == SDLK_t)
			{
				DEBUG_MSG("gpp::Events::Event::HIT_LADDER_TOP_EVENT");
				input.setCurrent(gpp::Events::Event::HIT_LADDER_TOP_EVENT);
			}
			// Jump Run
			if (event.key.keysym.sym == SDLK_SPACE
				&&
				event.key.keysym.sym == SDLK_RIGHT)
			{
				DEBUG_MSG("gpp::Events::Event::JUMP_UP_EVENT");
				input.setCurrent(gpp::Events::Event::JUMP_UP_EVENT);
			}
			// Jump Event
			else if (event.key.keysym.sym == SDLK_SPACE)
			{
				DEBUG_MSG("gpp::Events::Event::JUMP_UP_EVENT");
				input.setCurrent(gpp::Events::Event::JUMP_UP_EVENT);
			}
			// Running Slide
			else if (event.key.keysym.sym == SDLK_DOWN
				&&
				event.key.keysym.sym == SDLK_RIGHT)
			{
				DEBUG_MSG("gpp::Events::Event::SLIDE_EVENT");
				input.setCurrent(gpp::Events::Event::SLIDE_EVENT);
			}
			// Hit Ground Event
			else if (event.key.keysym.sym == SDLK_h)
			{
				DEBUG_MSG("gpp::Events::Event::HIT_GROUND_EVENT");
				input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
			}
			// Jump Attack Event
			else if (event.key.keysym.sym == SDLK_h)
			{
				DEBUG_MSG("gpp::Events::Event::HIT_GROUND_EVENT");
				input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
			}
			// Jump Throw Attack Event
			else if (event.key.keysym.sym == SDLK_h)
			{
				DEBUG_MSG("gpp::Events::Event::HIT_GROUND_EVENT");
				input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
			}
			break;

			// Deal with KeyReleased
			case SDL_KEYUP:
				// Run and Stop Attack
				if (event.key.keysym.sym == SDLK_z
					&&
					event.key.keysym.sym == SDLK_RIGHT)
				{
					DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
					input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
				}
				// Stop Attack
				else if (event.key.keysym.sym == SDLK_z)
				{
					DEBUG_MSG("gpp::Events::Event::ATTACK_STOP_EVENT");
					input.setCurrent(gpp::Events::Event::ATTACK_STOP_EVENT);
				}
				// Run and Stop Throw Attack
				else if (event.key.keysym.sym == SDLK_x
					&&
					event.key.keysym.sym == SDLK_RIGHT)
				{
					DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
					input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
				}
				// Stop Throw Attack
				else if (event.key.keysym.sym == SDLK_x)
				{
					DEBUG_MSG("gpp::Events::Event::THROW_STOP_EVENT");
					input.setCurrent(gpp::Events::Event::THROW_STOP_EVENT);
				}
				// Stop Running Right
				else if (event.key.keysym.sym == SDLK_RIGHT)
				{
					DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_STOP_EVENT");
					input.setCurrent(gpp::Events::Event::RUN_RIGHT_STOP_EVENT);
				}
				// Stop Slide
				else if (event.key.keysym.sym == SDLK_DOWN
					&&
					event.key.keysym.sym == SDLK_RIGHT)
				{
					DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
					input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
				}
				// Stop Moving Up
				else if (event.key.keysym.sym == SDLK_UP)
				{
					DEBUG_MSG("gpp::Events::Event::MOVE_UP_STOP_EVENT");
					input.setCurrent(gpp::Events::Event::MOVE_UP_STOP_EVENT);
				}
				// Stop Moving Down
				else if (event.key.keysym.sym == SDLK_DOWN)
				{
					DEBUG_MSG("gpp::Events::Event::MOVE_DOWN_STOP_EVENT");
					input.setCurrent(gpp::Events::Event::MOVE_DOWN_STOP_EVENT);
				}	
			break;
		default:
			DEBUG_MSG("gpp::Events::Event::NONE");
			input.setCurrent(gpp::Events::Event::NONE);
			break;
		}
		// Handle input to Player
		player->handleInput(input);
	}
}

void Game::update()
{
	// Update the Player
	player->update();
}

void Game::render()
{
	SDL_RenderClear(m_SDLrenderer);
	// this is where we add stuff to renderer
	SDL_Rect textureRect;
	textureRect.x = 0;
	textureRect.y = 0;
	textureRect.w = 7206;
	textureRect.h = 6792;

	SDL_RenderCopy(m_SDLrenderer, player_texture, &player->getAnimatedSprite().getFrame(player->getAnimatedSprite().getCurrentFrame()), NULL);
	SDL_RenderPresent(m_SDLrenderer);
}

void Game::clean()
{
	SDL_DestroyWindow(m_SDLwindow);
	SDL_DestroyRenderer(m_SDLrenderer);
	IMG_Quit();
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}

bool Game::running()
{
	return isRunning;
}
