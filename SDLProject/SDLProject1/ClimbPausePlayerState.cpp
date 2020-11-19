#include "Events.h"

#include "ClimbPausePlayerState.h"

#include "ClimbDownPlayerState.h"
#include "ClimbUpPlayerState.h"
#include "AccendLadderPlayerState.h"
#include "DecendLadderPlayerState.h"


PlayerState* ClimbPausePlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::MOVE_DOWN_START_EVENT)
	{
		DEBUG_MSG("ClimbPausePlayerState -> ClimbDownPlayerState");
		return new ClimbDownPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::MOVE_UP_START_EVENT)
	{
		DEBUG_MSG("ClimbPausePlayerState -> ClimbUpPlayerState");
		return new ClimbUpPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT)
	{
		DEBUG_MSG("ClimbPausePlayerState -> AccendLadderPlayerState");
		return new AccendLadderPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_TOP_EVENT)
	{
		DEBUG_MSG("ClimbPausePlayerState -> LadderClimbedPlayerState");
		return new DecendLadderPlayerState();
	}
	return nullptr;
}
void ClimbPausePlayerState::update(Player& player) {}
void ClimbPausePlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering ClimbPausePlayerState");
	player.getAnimatedSprite().clearFrames();

	SDL_Rect tempRectOne;
	tempRectOne.x = 1608;
	tempRectOne.y = 464;
	tempRectOne.w = 282;
	tempRectOne.h = 464;
	player.getAnimatedSprite().addFrame(tempRectOne);// sf::IntRect(1608, 464, 282, 464));
	
	player.getAnimatedSprite().setTime(500);
}
void ClimbPausePlayerState::exit(Player& player) 
{
	DEBUG_MSG("Exiting ClimbPausePlayerState");
}