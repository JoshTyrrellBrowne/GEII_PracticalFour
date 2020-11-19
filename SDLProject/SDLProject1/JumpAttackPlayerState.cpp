#include "Events.h"

#include "JumpAttackPlayerState.h"

#include "RunRightPlayerState.h"
#include "GlidePlayerState.h"
#include "DiedPlayerState.h"

PlayerState* JumpAttackPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("JumpAttackPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::ATTACK_STOP_EVENT)
	{
		DEBUG_MSG("JumpAttackPlayerState -> GlidePlayerState");
		return new GlidePlayerState();
	}
	return nullptr;
}
void JumpAttackPlayerState::update(Player& player) {}
void JumpAttackPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering JumpAttackPlayerState");
	player.getAnimatedSprite().clearFrames();

	SDL_Rect tempRectOne;
	tempRectOne.x = 1329;
	tempRectOne.y = 1992;
	tempRectOne.w = 504;
	tempRectOne.h = 522;
	player.getAnimatedSprite().addFrame(tempRectOne);// sf::IntRect(1329, 1992, 504, 522));
	SDL_Rect tempRectTwo;
	tempRectOne.x = 1851;
	tempRectOne.y = 1992;
	tempRectOne.w = 504;
	tempRectOne.h = 522;
	player.getAnimatedSprite().addFrame(tempRectTwo);// sf::IntRect(1851, 1992, 504, 522));
	SDL_Rect tempRectThree;
	tempRectThree.x = 2373;
	tempRectThree.y = 1992;
	tempRectThree.w = 504;
	tempRectThree.h = 522;
	player.getAnimatedSprite().addFrame(tempRectThree);// sf::IntRect(2373, 1992, 504, 522));
	SDL_Rect tempRectFour;
	tempRectFour.x = 1329;
	tempRectFour.y = 2514;
	tempRectFour.w = 504;
	tempRectFour.h = 522;
	player.getAnimatedSprite().addFrame(tempRectFour);// sf::IntRect(1329, 2514, 504, 522));
	SDL_Rect tempRectFive;
	tempRectFive.x = 1851;
	tempRectFive.y = 2514;
	tempRectFive.w = 504;
	tempRectFive.h = 522;
	player.getAnimatedSprite().addFrame(tempRectFive);// sf::IntRect(1851, 2514, 504, 522));
	SDL_Rect tempRectSix;
	tempRectSix.x = 2373;
	tempRectSix.y = 2514;
	tempRectSix.w = 504;
	tempRectSix.h = 522;
	player.getAnimatedSprite().addFrame(tempRectSix);// sf::IntRect(2373, 2514, 504, 522));
	SDL_Rect tempRectSeven;
	tempRectSeven.x = 1329;
	tempRectSeven.y = 3036;
	tempRectSeven.w = 504;
	tempRectSeven.h = 522;
	player.getAnimatedSprite().addFrame(tempRectSeven);// sf::IntRect(1329, 3036, 504, 522));
	SDL_Rect tempRectEight;
	tempRectEight.x = 1851;
	tempRectEight.y = 3036;
	tempRectEight.w = 504;
	tempRectEight.h = 522;
	player.getAnimatedSprite().addFrame(tempRectEight);// sf::IntRect(1851, 3036, 504, 522));
	SDL_Rect tempRectNine;
	tempRectNine.x = 2373;
	tempRectNine.y = 3036;
	tempRectNine.w = 504;
	tempRectNine.h = 522;
	player.getAnimatedSprite().addFrame(tempRectNine);// sf::IntRect(2373, 3036, 504, 522));
	SDL_Rect tempRectTen;
	tempRectTen.x = 1329;
	tempRectTen.y = 3558;
	tempRectTen.w = 504;
	tempRectTen.h = 522;
	player.getAnimatedSprite().addFrame(tempRectTen);// sf::IntRect(1329, 3558, 504, 522));

	player.getAnimatedSprite().setTime(30);
}
void JumpAttackPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting JumpAttackPlayerState");
}