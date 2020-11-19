#include "Events.h"

#include "DiedPlayerState.h"

#include "RevivedPlayerState.h"

PlayerState* DiedPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::REVIVED_EVENT)
	{
		DEBUG_MSG("DiedPlayerState -> RevivedPlayerState");
		return new RevivedPlayerState();
	}
	return nullptr;
}
void DiedPlayerState::update(Player& player) {}
void DiedPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering DiedPlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(false);

	SDL_Rect tempRectOne;
	tempRectOne.x = 2454;
	tempRectOne.y = 0;
	tempRectOne.w = 482;
	tempRectOne.h = 498;
	player.getAnimatedSprite().addFrame(tempRectOne);// sf::IntRect(2454, 0, 482, 498));
	SDL_Rect tempRectTwo;
	tempRectTwo.x = 2936;
	tempRectTwo.y = 0;
	tempRectTwo.w = 482;
	tempRectTwo.h = 498;
	player.getAnimatedSprite().addFrame(tempRectTwo);// sf::IntRect(2936, 0, 482, 498));
	SDL_Rect tempRectThree;
	tempRectThree.x = 3418;
	tempRectThree.y = 0;
	tempRectThree.w = 482;
	tempRectThree.h = 498;
	player.getAnimatedSprite().addFrame(tempRectThree);// sf::IntRect(3418, 0, 482, 498));
	SDL_Rect tempRectFour;
	tempRectFour.x = 2454;
	tempRectFour.y = 498;
	tempRectFour.w = 482;
	tempRectFour.h = 498;
	player.getAnimatedSprite().addFrame(tempRectFour);// sf::IntRect(2454, 498, 482, 498));
	SDL_Rect tempRectFive;
	tempRectFive.x = 2936;
	tempRectFive.y = 498;
	tempRectFive.w = 482;
	tempRectFive.h = 498;
	player.getAnimatedSprite().addFrame(tempRectFive);// sf::IntRect(2936, 498, 482, 498));
	SDL_Rect tempRectSix;
	tempRectSix.x = 3418;
	tempRectSix.y = 498;
	tempRectSix.w = 482;
	tempRectSix.h = 498;
	player.getAnimatedSprite().addFrame(tempRectSix);// sf::IntRect(3418, 498, 482, 498));
	SDL_Rect tempRectSeven;
	tempRectSeven.x = 2454;
	tempRectSeven.y = 996;
	tempRectSeven.w = 482;
	tempRectSeven.h = 498;
	player.getAnimatedSprite().addFrame(tempRectSeven);// sf::IntRect(2454, 996, 482, 498));
	SDL_Rect tempRectEight;
	tempRectEight.x = 2936;
	tempRectEight.y = 996;
	tempRectEight.w = 482;
	tempRectEight.h = 498;
	player.getAnimatedSprite().addFrame(tempRectEight);// sf::IntRect(2936, 996, 482, 498));
	SDL_Rect tempRectNine;
	tempRectNine.x = 3418;
	tempRectNine.y = 996;
	tempRectNine.w = 482;
	tempRectNine.h = 498;
	player.getAnimatedSprite().addFrame(tempRectNine);// sf::IntRect(3418, 996, 482, 498));
	SDL_Rect tempRectTen;
	tempRectTen.x = 2454;
	tempRectTen.y = 1494;
	tempRectTen.w = 482;
	tempRectTen.h = 498;
	player.getAnimatedSprite().addFrame(tempRectTen);// sf::IntRect(2454, 1494, 482, 498));

	player.getAnimatedSprite().setTime(300);
}

void DiedPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting DiedPlayerState");
	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(true);
}