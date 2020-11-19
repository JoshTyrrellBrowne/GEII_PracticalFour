#include "Events.h"

#include "JumpThrowAttackPlayerState.h"

#include "RunRightPlayerState.h"
#include "GlidePlayerState.h"
#include "DiedPlayerState.h"

PlayerState* JumpThrowAttackPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("JumpThrowAttackPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::THROW_STOP_EVENT)
	{
		DEBUG_MSG("JumpThrowAttackPlayerState -> GlidePlayerState");
		return new GlidePlayerState();
	}
	return nullptr;
}
void JumpThrowAttackPlayerState::update(Player& player) {}
void JumpThrowAttackPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering JumpThrowAttackPlayerState");
	player.getAnimatedSprite().clearFrames();

	SDL_Rect tempRectOne;
	tempRectOne.x = 4596;
	tempRectOne.y = 0;
	tempRectOne.w = 360;
	tempRectOne.h = 431;
	player.getAnimatedSprite().addFrame(tempRectOne);// sf::IntRect(4596, 0, 360, 431));
	SDL_Rect tempRectTwo;
	tempRectTwo.x = 4956;
	tempRectTwo.y = 0;
	tempRectTwo.w = 360;
	tempRectTwo.h = 431;
	player.getAnimatedSprite().addFrame(tempRectTwo);// sf::IntRect(4956, 0, 360, 431));
	SDL_Rect tempRectThree;
	tempRectThree.x = 5316;
	tempRectThree.y = 0;
	tempRectThree.w = 360;
	tempRectThree.h = 431;
	player.getAnimatedSprite().addFrame(tempRectThree);// sf::IntRect(5316, 0, 360, 431));
	SDL_Rect tempRectFour;
	tempRectFour.x = 4596;
	tempRectFour.y = 431;
	tempRectFour.w = 360;
	tempRectFour.h = 431;
	player.getAnimatedSprite().addFrame(tempRectFour);// sf::IntRect(4596, 431, 360, 431));
	SDL_Rect tempRectFive;
	tempRectFive.x = 4956;
	tempRectFive.y = 431;
	tempRectFive.w = 360;
	tempRectFive.h = 431;
	player.getAnimatedSprite().addFrame(tempRectFive);// sf::IntRect(4956, 431, 360, 431));
	SDL_Rect tempRectSix;
	tempRectSix.x = 5316;
	tempRectSix.y = 431;
	tempRectSix.w = 360;
	tempRectSix.h = 431;
	player.getAnimatedSprite().addFrame(tempRectSix);// sf::IntRect(5316, 431, 360, 431));
	SDL_Rect tempRectSeven;
	tempRectSeven.x = 4596;
	tempRectSeven.y = 862;
	tempRectSeven.w = 360;
	tempRectSeven.h = 431;
	player.getAnimatedSprite().addFrame(tempRectSeven);// sf::IntRect(4596, 862, 360, 431));
	SDL_Rect tempRectEight;
	tempRectEight.x = 4956;
	tempRectEight.y = 862;
	tempRectEight.w = 360;
	tempRectEight.h = 431;
	player.getAnimatedSprite().addFrame(tempRectEight);// sf::IntRect(4956, 862, 360, 431));
	SDL_Rect tempRectNine;
	tempRectNine.x = 5316;
	tempRectNine.y = 862;
	tempRectNine.w = 360;
	tempRectNine.h = 431;
	player.getAnimatedSprite().addFrame(tempRectNine);// sf::IntRect(5316, 862, 360, 431));
	SDL_Rect tempRectTen;
	tempRectTen.x = 4596;
	tempRectTen.y = 1293;
	tempRectTen.w = 360;
	tempRectTen.h = 431;
	player.getAnimatedSprite().addFrame(tempRectTen);// sf::IntRect(4596, 1293, 360, 431));

	player.getAnimatedSprite().setTime(50);
}
void JumpThrowAttackPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting JumpThrowAttackPlayerState");
}