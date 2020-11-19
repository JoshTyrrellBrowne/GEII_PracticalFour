#include "Events.h"

#include "SlidePlayerState.h"

#include "RunRightPlayerState.h"
#include "DiedPlayerState.h"
#include "IdlePlayerState.h"

PlayerState* SlidePlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT)
	{
		DEBUG_MSG("SlidePlayerState -> RunRightPlayerState");
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("SlidePlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void SlidePlayerState::update(Player& player) {
	// Switch from SlidePlayerState to IdlePlayerState
	// There is a fixed time at which the slide switched
	// back to IdlePlayerState....as the gameplay programmer
	// you may wish to stop the slide and have an appropriate
	// state and animation at the end of the slide
	// this was added so sliding does not go one indefinitely
	if (m_time - SDL_GetTicks() > 200) {
		m_time = SDL_GetTicks(); // reset
		DEBUG_MSG("SlidePlayerState -> IdlePlayerState");
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new IdlePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp; // Delete previous
	}
}
void SlidePlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering SlidePlayerState");
	m_time = SDL_GetTicks();
	player.getAnimatedSprite().clearFrames();

	SDL_Rect tempRectOne;
	tempRectOne.x = 0;
	tempRectOne.y = 5388;
	tempRectOne.w = 373;
	tempRectOne.h = 351;
	player.getAnimatedSprite().addFrame(tempRectOne);// sf::IntRect(0, 5388, 373, 351));
	SDL_Rect tempRectTwo;
	tempRectTwo.x = 373;
	tempRectTwo.y = 5388;
	tempRectTwo.w = 373;
	tempRectTwo.h = 351;
	player.getAnimatedSprite().addFrame(tempRectTwo);// sf::IntRect(373, 5388, 373, 351));
	SDL_Rect tempRectThree;
	tempRectThree.x = 746;
	tempRectThree.y = 5388;
	tempRectThree.w = 373;
	tempRectThree.h = 351;
	player.getAnimatedSprite().addFrame(tempRectThree);// sf::IntRect(746, 5388, 373, 351));
	SDL_Rect tempRectFour;
	tempRectFour.x = 0;
	tempRectFour.y = 5739;
	tempRectFour.w = 373;
	tempRectFour.h = 351;
	player.getAnimatedSprite().addFrame(tempRectFour);// sf::IntRect(0, 5739, 373, 351));
	SDL_Rect tempRectFive;
	tempRectFive.x = 373;
	tempRectFive.y = 5739;
	tempRectFive.w = 373;
	tempRectFive.h = 351;
	player.getAnimatedSprite().addFrame(tempRectFive);// sf::IntRect(373, 5739, 373, 351));
	SDL_Rect tempRectSix;
	tempRectSix.x = 746;
	tempRectSix.y = 5739;
	tempRectSix.w = 373;
	tempRectSix.h = 351;
	player.getAnimatedSprite().addFrame(tempRectSix);// sf::IntRect(746, 5739, 373, 351));
	SDL_Rect tempRectSeven;
	tempRectSeven.x = 0;
	tempRectSeven.y = 6090;
	tempRectSeven.w = 373;
	tempRectSeven.h = 351;
	player.getAnimatedSprite().addFrame(tempRectSeven);// sf::IntRect(0, 6090, 373, 351));
	SDL_Rect tempRectEight;
	tempRectEight.x = 373;
	tempRectEight.y = 6090;
	tempRectEight.w = 373;
	tempRectEight.h = 351;
	player.getAnimatedSprite().addFrame(tempRectEight);// sf::IntRect(373, 6090, 373, 351));
	SDL_Rect tempRectNine;
	tempRectNine.x = 746;
	tempRectNine.y = 6090;
	tempRectNine.w = 373;
	tempRectNine.h = 351;
	player.getAnimatedSprite().addFrame(tempRectNine);// sf::IntRect(746, 6090, 373, 351));
	SDL_Rect tempRectTen;
	tempRectTen.x = 746;
	tempRectTen.y = 6441;
	tempRectTen.w = 373;
	tempRectTen.h = 351;
	player.getAnimatedSprite().addFrame(tempRectTen);// sf::IntRect(746, 6441, 373, 351));

	player.getAnimatedSpriteFrame().setTime(30);
}
void SlidePlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting SlidePlayerState");
}