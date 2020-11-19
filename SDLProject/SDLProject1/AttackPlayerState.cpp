#include "Events.h"

#include "AttackPlayerState.h"

#include "RunRightPlayerState.h"
#include "IdlePlayerState.h"
#include "DiedPlayerState.h"

PlayerState* AttackPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT)
	{
		DEBUG_MSG("AttackPlayerState -> RunRightPlayerState");
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::ATTACK_STOP_EVENT)
	{
		DEBUG_MSG("AttackPlayerState -> IdlePlayerState");
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("AttackPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void AttackPlayerState::update(Player& player) {}
void AttackPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering AttackPlayerState");
	player.getAnimatedSprite().clearFrames();

	SDL_Rect tempRectOne;
	tempRectOne.x = 0;
	tempRectOne.y = 0;
	tempRectOne.w = 536;
	tempRectOne.h = 495;
	player.getAnimatedSprite().addFrame(tempRectOne);//sf::IntRect(0, 0, 536, 495));
	SDL_Rect tempRectTwo;
	tempRectTwo.x = 536;
	tempRectTwo.y = 0;
	tempRectTwo.w = 536;
	tempRectTwo.h = 495;
	player.getAnimatedSprite().addFrame(tempRectTwo);// sf::IntRect(536, 0, 536, 495));
	SDL_Rect tempRectThree;
	tempRectThree.x = 1072;
	tempRectThree.y = 0;
	tempRectThree.w = 536;
	tempRectThree.h = 495;
	player.getAnimatedSprite().addFrame(tempRectThree);// sf::IntRect(1072, 0, 536, 495));
	SDL_Rect tempRectFour;
	tempRectFour.x = 0;
	tempRectFour.y = 495;
	tempRectFour.w = 536;
	tempRectFour.h = 495;
	player.getAnimatedSprite().addFrame(tempRectFour);// sf::IntRect(0, 495, 536, 495));
	SDL_Rect tempRectFive;
	tempRectFive.x = 536;
	tempRectFive.y = 495;
	tempRectFive.w = 536;
	tempRectFive.h = 495;
	player.getAnimatedSprite().addFrame(tempRectFive);// sf::IntRect(536, 495, 536, 495));
	SDL_Rect tempRectSix;
	tempRectSix.x = 1072;
	tempRectSix.y = 495;
	tempRectSix.w = 536;
	tempRectSix.h = 495;
	player.getAnimatedSprite().addFrame(tempRectSix);// sf::IntRect(1072, 495, 536, 495));
	SDL_Rect tempRectSeven;
	tempRectSeven.x = 0;
	tempRectSeven.y = 990;
	tempRectSeven.w = 536;
	tempRectSeven.h = 495;
	player.getAnimatedSprite().addFrame(tempRectSeven);// sf::IntRect(0, 990, 536, 495));
	SDL_Rect tempRectEight;
	tempRectEight.x = 536;
	tempRectEight.y = 990;
	tempRectEight.w = 536;
	tempRectEight.h = 495;
	player.getAnimatedSprite().addFrame(tempRectEight);// sf::IntRect(536, 990, 536, 495));
	SDL_Rect tempRectNine;
	tempRectNine.x = 1072;
	tempRectNine.y = 990;
	tempRectNine.w = 536;
	tempRectNine.h = 495;
	player.getAnimatedSprite().addFrame(tempRectNine);// sf::IntRect(1072, 990, 536, 495));
	SDL_Rect tempRectTen;
	tempRectTen.x = 0;
	tempRectTen.y = 1485;
	tempRectTen.w = 536;
	tempRectTen.h = 495;
	player.getAnimatedSprite().addFrame(tempRectTen);// sf::IntRect(0, 1485, 536, 495));

	player.getAnimatedSprite().setTime(300);
}
void AttackPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting AttackPlayerState");
}