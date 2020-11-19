#include "Events.h"

#include "ClimbDownPlayerState.h"

#include "ClimbPausePlayerState.h"
#include "AccendLadderPlayerState.h"


PlayerState* ClimbDownPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::MOVE_DOWN_STOP_EVENT)
	{
		DEBUG_MSG("ClimbDownPlayerState -> ClimbPausePlayerState");
		return new ClimbPausePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT)
	{
		DEBUG_MSG("ClimbDownPlayerState -> AccendLadderPlayerState");
		return new AccendLadderPlayerState();
	}
	return nullptr;
}
void ClimbDownPlayerState::update(Player& player) {}
void ClimbDownPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering ClimbDownPlayerState");
	// Climb Down Animated Sprite
	player.getAnimatedSprite().clearFrames();

	SDL_Rect tempRectOne;
	tempRectOne.x = 1608;
	tempRectOne.y = 0;
	tempRectOne.w = 282;
	tempRectOne.h = 464;
	player.getAnimatedSprite().addFrame(tempRectOne);// sf::IntRect(1608, 0, 282, 464));
	SDL_Rect tempRectTwo;
	tempRectTwo.x = 1890;
	tempRectTwo.y = 0;
	tempRectTwo.w = 282;
	tempRectTwo.h = 464;
	player.getAnimatedSprite().addFrame(tempRectTwo);// sf::IntRect(1890, 0, 282, 464));
	SDL_Rect tempRectThree;
	tempRectThree.x = 2172;
	tempRectThree.y = 0;
	tempRectThree.w = 282;
	tempRectThree.h = 464;
	player.getAnimatedSprite().addFrame(tempRectThree);// sf::IntRect(2172, 0, 282, 464));
	SDL_Rect tempRectFour;
	tempRectFour.x = 1608;
	tempRectFour.y = 464;
	tempRectFour.w = 282;
	tempRectFour.h = 464;
	player.getAnimatedSprite().addFrame(tempRectFour);// sf::IntRect(1608, 464, 282, 464));
	SDL_Rect tempRectFive;
	tempRectFive.x = 1890;
	tempRectFive.y = 464;
	tempRectFive.w = 282;
	tempRectFive.h = 464;
	player.getAnimatedSprite().addFrame(tempRectFive);// sf::IntRect(1890, 464, 282, 464));
	SDL_Rect tempRectSix;
	tempRectSix.x = 2172;
	tempRectSix.y = 464;
	tempRectSix.w = 282;
	tempRectSix.h = 464;
	player.getAnimatedSprite().addFrame(tempRectSix);;// sf::IntRect(2172, 464, 282, 464));
	SDL_Rect tempRectSeven;
	tempRectSeven.x = 1608;
	tempRectSeven.y = 928;
	tempRectSeven.w = 282;
	tempRectSeven.h = 464;
	player.getAnimatedSprite().addFrame(tempRectSeven);// sf::IntRect(1608, 928, 282, 464));
	SDL_Rect tempRectEight;
	tempRectEight.x = 1890;
	tempRectEight.y = 928;
	tempRectEight.w = 282;
	tempRectEight.h = 464;
	player.getAnimatedSprite().addFrame(tempRectEight);// sf::IntRect(1890, 928, 282, 464));
	SDL_Rect tempRectNine;
	tempRectNine.x = 2172;
	tempRectNine.y = 928;
	tempRectNine.w = 282;
	tempRectNine.h = 464;
	player.getAnimatedSprite().addFrame(tempRectNine);// sf::IntRect(2172, 928, 282, 464));
	SDL_Rect tempRectTen;
	tempRectTen.x = 1608;
	tempRectTen.y = 1392;
	tempRectTen.w = 282;
	tempRectTen.h = 464;
	player.getAnimatedSprite().addFrame(tempRectTen);// sf::IntRect(1608, 1392, 282, 464));

	player.getAnimatedSprite().setTime(500);
}
void ClimbDownPlayerState::exit(Player& player) 
{
	DEBUG_MSG("Exiting ClimbDownPlayerState");
}