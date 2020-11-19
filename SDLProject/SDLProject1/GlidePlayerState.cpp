#include "Events.h"

#include "GlidePlayerState.h"

#include "DiedPlayerState.h"
#include "IdlePlayerState.h"

PlayerState* GlidePlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::HIT_GROUND_EVENT)
	{
		DEBUG_MSG("GlidePlayerState -> IdlePlayerState");
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT)
	{
		DEBUG_MSG("GlidePlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void GlidePlayerState::update(Player& player) {
	DEBUG_MSG("GlidePlayerState -> IdlePlayerState");
	if (m_time - SDL_GetTicks() > 120) {
		m_time = SDL_GetTicks(); // reset
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new IdlePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp;
	}
}
void GlidePlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering RevivedPlayerState");
	m_time = SDL_GetTicks();
	player.getAnimatedSprite().clearFrames();

	SDL_Rect tempRectOne;
	tempRectOne.x = 0;
	tempRectOne.y = 1992;
	tempRectOne.w = 443;
	tempRectOne.h = 454;
	player.getAnimatedSprite().addFrame(tempRectOne);// sf::IntRect(0, 1992, 443, 454));
	SDL_Rect tempRectTwo;
	tempRectTwo.x = 443;
	tempRectTwo.y = 1992;
	tempRectTwo.w = 443;
	tempRectTwo.h = 454;
	player.getAnimatedSprite().addFrame(tempRectTwo);// sf::IntRect(443, 1992, 443, 454));
	SDL_Rect tempRectThree;
	tempRectThree.x = 886;
	tempRectThree.y = 1992;
	tempRectThree.w = 443;
	tempRectThree.h = 454;
	player.getAnimatedSprite().addFrame(tempRectThree);// sf::IntRect(886, 1992, 443, 454));
	SDL_Rect tempRectFour;
	tempRectFour.x = 0;
	tempRectFour.y = 2446;
	tempRectFour.w = 443;
	tempRectFour.h = 454;
	player.getAnimatedSprite().addFrame(tempRectFour);// sf::IntRect(0, 2446, 443, 454));
	SDL_Rect tempRectFive;
	tempRectFive.x = 443;
	tempRectFive.y = 2446;
	tempRectFive.w = 443;
	tempRectFive.h = 454;
	player.getAnimatedSprite().addFrame(tempRectFive);// sf::IntRect(443, 2446, 443, 454));
	SDL_Rect tempRectSix;
	tempRectSix.x = 886;
	tempRectSix.y = 2446;
	tempRectSix.w = 443;
	tempRectSix.h = 454;
	player.getAnimatedSprite().addFrame(tempRectSix);// sf::IntRect(886, 2446, 443, 454));
	SDL_Rect tempRectSeven;
	tempRectSeven.x = 0;
	tempRectSeven.y = 2900;
	tempRectSeven.w = 443;
	tempRectSeven.h = 454;
	player.getAnimatedSprite().addFrame(tempRectSeven);// sf::IntRect(0, 2900, 443, 454));
	SDL_Rect tempRectEight;
	tempRectEight.x = 443;
	tempRectEight.y = 2900;
	tempRectEight.w = 443;
	tempRectEight.h = 454;
	player.getAnimatedSprite().addFrame(tempRectEight);// sf::IntRect(443, 2900, 443, 454));
	SDL_Rect tempRectNine;
	tempRectNine.x = 886;
	tempRectNine.y = 2900;
	tempRectNine.w = 443;
	tempRectNine.h = 454;
	player.getAnimatedSprite().addFrame(tempRectNine);// sf::IntRect(886, 2900, 443, 454));
	SDL_Rect tempRectTen;
	tempRectTen.x = 0;
	tempRectTen.y = 3354;
	tempRectTen.w = 443;
	tempRectTen.h = 454;
	player.getAnimatedSprite().addFrame(tempRectTen);// sf::IntRect(0, 3354, 443, 454));

	player.getAnimatedSprite().setTime(300);
}
void GlidePlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting RevivedPlayerState");
}