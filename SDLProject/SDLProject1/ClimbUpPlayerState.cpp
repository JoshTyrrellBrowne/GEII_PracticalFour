#include "Events.h"

#include "ClimbUpPlayerState.h"

#include "ClimbPausePlayerState.h"
#include "ClimbDownPlayerState.h"
#include "DecendLadderPlayerState.h"


PlayerState* ClimbUpPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::MOVE_UP_STOP_EVENT)
	{
		DEBUG_MSG("ClimbUpPlayerState -> ClimbPausePlayerState");
		return new ClimbPausePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::MOVE_DOWN_START_EVENT)
	{
		DEBUG_MSG("ClimbUpPlayerState -> ClimbDownPlayerState");
		return new ClimbDownPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_TOP_EVENT)
	{
		DEBUG_MSG("ClimbUpPlayerState -> DecendLadderPlayerState");
		return new DecendLadderPlayerState();
	}
	
	return nullptr;
}
void ClimbUpPlayerState::update(Player& player) {}
void ClimbUpPlayerState::enter(Player& player) 
{
	DEBUG_MSG("Entering ClimbUpPlayerState");

	// Climb Up Animated Sprite
	player.getAnimatedSprite().clearFrames();

	SDL_Rect tempRectOne;
	tempRectOne.x = 1608;
	tempRectOne.y = 1392;
	tempRectOne.w = 282;
	tempRectOne.h = 464;
	player.getAnimatedSprite().addFrame(tempRectOne);// sf::IntRect(1608, 1392, 282, 464));
	SDL_Rect tempRectTwo;
	tempRectTwo.x = 2172;
	tempRectTwo.y = 928;
	tempRectTwo.w = 282;
	tempRectTwo.h = 464;
	player.getAnimatedSprite().addFrame(tempRectTwo);// sf::IntRect(2172, 928, 282, 464));
	SDL_Rect tempRectThree;
	tempRectThree.x = 1890;
	tempRectThree.y = 928;
	tempRectThree.w = 282;
	tempRectThree.h = 464;
	player.getAnimatedSprite().addFrame(tempRectThree);// sf::IntRect(1890, 928, 282, 464));
	SDL_Rect tempRectFour;
	tempRectFour.x = 1608;
	tempRectFour.y = 928;
	tempRectFour.w = 282;
	tempRectFour.h = 464;
	player.getAnimatedSprite().addFrame(tempRectFour);// sf::IntRect(1608, 928, 282, 464));
	SDL_Rect tempRectFive;
	tempRectFive.x = 2172;
	tempRectFive.y = 464;
	tempRectFive.w = 282;
	tempRectFive.h = 464;
	player.getAnimatedSprite().addFrame(tempRectFive);// sf::IntRect(2172, 464, 282, 464));
	SDL_Rect tempRectSix;
	tempRectSix.x = 1890;
	tempRectSix.y = 464;
	tempRectSix.w = 282;
	tempRectSix.h = 464;
	player.getAnimatedSprite().addFrame(tempRectSix);// sf::IntRect(1890, 464, 282, 464));
	SDL_Rect tempRectSeven;
	tempRectSeven.x = 1608;
	tempRectSeven.y = 464;
	tempRectSeven.w = 282;
	tempRectSeven.h = 464;
	player.getAnimatedSprite().addFrame(tempRectSeven);// sf::IntRect(1608, 464, 282, 464));
	SDL_Rect tempRectEight;
	tempRectEight.x = 2172;
	tempRectEight.y = 0;
	tempRectEight.w = 282;
	tempRectEight.h = 464;
	player.getAnimatedSprite().addFrame(tempRectEight);// sf::IntRect(2172, 0, 282, 464));
	SDL_Rect tempRectNine;
	tempRectNine.x = 1890;
	tempRectNine.y = 0;
	tempRectNine.w = 282;
	tempRectNine.h = 464;
	player.getAnimatedSprite().addFrame(tempRectNine);//sf::IntRect(1890, 0, 282, 464));
	SDL_Rect tempRectTen;
	tempRectTen.x = 1890;
	tempRectTen.y = 0;
	tempRectTen.w = 282;
	tempRectTen.h = 464;
	player.getAnimatedSprite().addFrame(tempRectTen);// sf::IntRect(1608, 0, 282, 464));
	
	player.getAnimatedSprite().setTime(500);
}
void ClimbUpPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting ClimbUpPlayerState");
}