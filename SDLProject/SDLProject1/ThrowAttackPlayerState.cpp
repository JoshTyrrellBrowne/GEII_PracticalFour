#include "Events.h"

#include "ThrowAttackPlayerState.h"

#include "RunRightPlayerState.h"
#include "IdlePlayerState.h"
#include "DiedPlayerState.h"

PlayerState* ThrowAttackPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT)
	{
		DEBUG_MSG("AttackPlayerState -> RunRightPlayerState");
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::THROW_STOP_EVENT)
	{
		DEBUG_MSG("AttackPlayerState -> IdlePlayerState");
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("ThrowAttackPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void ThrowAttackPlayerState::update(Player& player) {}
void ThrowAttackPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering AttackPlayerState");
	player.getAnimatedSprite().clearFrames();

	SDL_Rect tempRectOne;
	tempRectOne.x = 6075;
	tempRectOne.y = 0;
	tempRectOne.w = 377;
	tempRectOne.h = 451;
	player.getAnimatedSprite().addFrame(tempRectOne);// sf::IntRect(6075, 0, 377, 451));
	SDL_Rect tempRectTwo;
	tempRectTwo.x = 6452;
	tempRectTwo.y = 0;
	tempRectTwo.w = 377;
	tempRectTwo.h = 451;
	player.getAnimatedSprite().addFrame(tempRectTwo);// sf::IntRect(6452, 0, 377, 451));
	SDL_Rect tempRectThree;
	tempRectThree.x = 6829;
	tempRectThree.y = 0;
	tempRectThree.w = 377;
	tempRectThree.h = 451;
	player.getAnimatedSprite().addFrame(tempRectThree);// sf::IntRect(6829, 0, 377, 451));
	SDL_Rect tempRectFour;
	tempRectFour.x = 6075;
	tempRectFour.y = 451;
	tempRectFour.w = 377;
	tempRectFour.h = 451;
	player.getAnimatedSprite().addFrame(tempRectFour);// sf::IntRect(6075, 451, 377, 451));
	SDL_Rect tempRectFive;
	tempRectFive.x = 6452;
	tempRectFive.y = 451;
	tempRectFive.w = 377;
	tempRectFive.h = 451;
	player.getAnimatedSprite().addFrame(tempRectFive);// sf::IntRect(6452, 451, 377, 451));
	SDL_Rect tempRectSix;
	tempRectSix.x = 6829;
	tempRectSix.y = 451;
	tempRectSix.w = 377;
	tempRectSix.h = 451;
	player.getAnimatedSprite().addFrame(tempRectSix);// sf::IntRect(6829, 451, 377, 451));
	SDL_Rect tempRectSeven;
	tempRectSeven.x = 6075;
	tempRectSeven.y = 902;
	tempRectSeven.w = 377;
	tempRectSeven.h = 451;
	player.getAnimatedSprite().addFrame(tempRectSeven);// sf::IntRect(6075, 902, 377, 451));
	SDL_Rect tempRectEight;
	tempRectEight.x = 6452;
	tempRectEight.y = 902;
	tempRectEight.w = 377;
	tempRectEight.h = 451;
	player.getAnimatedSprite().addFrame(tempRectEight);// sf::IntRect(6452, 902, 377, 451));
	SDL_Rect tempRectNine;
	tempRectNine.x = 6829;
	tempRectNine.y = 902;
	tempRectNine.w = 377;
	tempRectNine.h = 451;
	player.getAnimatedSprite().addFrame(tempRectNine);// sf::IntRect(6829, 902, 377, 451));
	SDL_Rect tempRectTen;
	tempRectTen.x = 6075;
	tempRectTen.y = 1353;
	tempRectTen.w = 377;
	tempRectTen.h = 451;
	player.getAnimatedSprite().addFrame(tempRectTen);// sf::IntRect(6075, 1353, 377, 451));

	player.getAnimatedSprite().setTime(30);
}
void ThrowAttackPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting AttackPlayerState");
}