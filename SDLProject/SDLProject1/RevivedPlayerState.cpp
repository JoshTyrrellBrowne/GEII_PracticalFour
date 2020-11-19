#include "Events.h"

#include "RevivedPlayerState.h"

#include "DiedPlayerState.h"
#include "IdlePlayerState.h"

PlayerState* RevivedPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::DIED_EVENT)
	{
		DEBUG_MSG("RevivedPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void RevivedPlayerState::update(Player& player) {
	// Switch from RevivedPlayerState to IdlePlayerState
	DEBUG_MSG("RevivedPlayerState -> IdlePlayerState");
	if (m_time - SDL_GetTicks() > 500) {
		m_time = SDL_GetTicks();
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new IdlePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp;
	}
}
void RevivedPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering RevivedPlayerState");

	// How long in State Clock
	m_time = SDL_GetTicks();

	// Clear existing frames
	player.getAnimatedSprite().clearFrames();

	// Set animation control members
	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(false);

	// Add animation frames
	SDL_Rect tempRectOne;
	tempRectOne.x = 2454;
	tempRectOne.y = 1494;
	tempRectOne.w = 482;
	tempRectOne.h = 498;
	player.getAnimatedSprite().addFrame(tempRectOne);// sf::IntRect(2454, 1494, 482, 498));
	SDL_Rect tempRectTwo;
	tempRectTwo.x = 3418;
	tempRectTwo.y = 996;
	tempRectTwo.w = 482;
	tempRectTwo.h = 498;
	player.getAnimatedSprite().addFrame(tempRectTwo);// sf::IntRect(3418, 996, 482, 498));
	SDL_Rect tempRectThree;
	tempRectThree.x = 2936;
	tempRectThree.y = 996;
	tempRectThree.w = 482;
	tempRectThree.h = 498;
	player.getAnimatedSprite().addFrame(tempRectThree);// sf::IntRect(2936, 996, 482, 498));
	SDL_Rect tempRectFour;
	tempRectFour.x = 2454;
	tempRectFour.y = 996;
	tempRectFour.w = 482;
	tempRectFour.h = 498;
	player.getAnimatedSprite().addFrame(tempRectFour);// sf::IntRect(2454, 996, 482, 498));
	SDL_Rect tempRectFive;
	tempRectFive.x = 3418;
	tempRectFive.y = 498;
	tempRectFive.w = 482;
	tempRectFive.h = 498;
	player.getAnimatedSprite().addFrame(tempRectFive);// sf::IntRect(3418, 498, 482, 498));
	SDL_Rect tempRectSix;
	tempRectSix.x = 2936;
	tempRectSix.y = 498;
	tempRectSix.w = 482;
	tempRectSix.h = 498;
	player.getAnimatedSprite().addFrame(tempRectSix);// sf::IntRect(2936, 498, 482, 498));
	SDL_Rect tempRectSeven;
	tempRectSeven.x = 2454;
	tempRectSeven.y = 498;
	tempRectSeven.w = 482;
	tempRectSeven.h = 498;
	player.getAnimatedSprite().addFrame(tempRectSeven);// sf::IntRect(2454, 498, 482, 498));
	SDL_Rect tempRectEight;
	tempRectEight.x = 3418;
	tempRectEight.y = 0;
	tempRectEight.w = 482;
	tempRectEight.h = 498;
	player.getAnimatedSprite().addFrame(tempRectEight);// sf::IntRect(3418, 0, 482, 498));
	SDL_Rect tempRectNine;
	tempRectNine.x = 2936;
	tempRectNine.y = 0;
	tempRectNine.w = 482;
	tempRectNine.h = 498;
	player.getAnimatedSprite().addFrame(tempRectNine);// sf::IntRect(2936, 0, 482, 498));
	SDL_Rect tempRectTen;
	tempRectTen.x = 2454;
	tempRectTen.y = 0;
	tempRectTen.w = 482;
	tempRectTen.h = 498;
	player.getAnimatedSprite().addFrame(tempRectTen);// sf::IntRect(2454, 0, 482, 498));
	
	// Set the animation time
	player.getAnimatedSprite().setTime(30);
}
void RevivedPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting RevivedPlayerState");
	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(true);
}