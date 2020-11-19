#include "Events.h"

#include "JumpPlayerState.h"

#include "DiedPlayerState.h"
#include "JumpAttackPlayerState.h"
#include "JumpThrowAttackPlayerState.h"
#include "GlidePlayerState.h"

PlayerState* JumpPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("JumpPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::ATTACK_START_EVENT)
	{
		DEBUG_MSG("JumpPlayerState -> JumpAttackPlayerState");
		return new JumpAttackPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::THROW_START_EVENT)
	{
		DEBUG_MSG("JumpPlayerState -> JumpThrowAttackPlayerState");
		return new JumpThrowAttackPlayerState();
	}
	return nullptr;
}
void JumpPlayerState::update(Player& player) {
	DEBUG_MSG("JumpPlayerState -> GlidePlayerState");
	if (m_time - SDL_GetTicks() > 120) {
		m_time = SDL_GetTicks();
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new GlidePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp;
	}
}
void JumpPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering JumpPlayerState");
	player.getAnimatedSprite().clearFrames();
	m_time = SDL_GetTicks();
	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(false);

	SDL_Rect tempRectOne;
	tempRectOne.x = 3900;
	tempRectOne.y = 1756;
	tempRectOne.w = 362;
	tempRectOne.h = 483;
	player.getAnimatedSprite().addFrame(tempRectOne);// sf::IntRect(3900, 1756, 362, 483));
	SDL_Rect tempRectTwo;
	tempRectTwo.x = 4262;
	tempRectTwo.y = 1756;
	tempRectTwo.w = 362;
	tempRectTwo.h = 483;
	player.getAnimatedSprite().addFrame(tempRectTwo);// sf::IntRect(4262, 1756, 362, 483));
	SDL_Rect tempRectThree;
	tempRectThree.x = 4624;
	tempRectThree.y = 1756;
	tempRectThree.w = 362;
	tempRectThree.h = 483;
	player.getAnimatedSprite().addFrame(tempRectThree);// sf::IntRect(4624, 1756, 362, 483));
	SDL_Rect tempRectFour;
	tempRectFour.x = 3900;
	tempRectFour.y = 2239;
	tempRectFour.w = 362;
	tempRectFour.h = 483;
	player.getAnimatedSprite().addFrame(tempRectFour);// sf::IntRect(3900, 2239, 362, 483));
	SDL_Rect tempRectFive;
	tempRectFive.x = 4262;
	tempRectFive.y = 2239;
	tempRectFive.w = 362;
	tempRectFive.h = 483;
	player.getAnimatedSprite().addFrame(tempRectFive);// sf::IntRect(4262, 2239, 362, 483));
	SDL_Rect tempRectSix;
	tempRectSix.x = 4624;
	tempRectSix.y = 2239;
	tempRectSix.w = 362;
	tempRectSix.h = 483;
	player.getAnimatedSprite().addFrame(tempRectSix);// sf::IntRect(4624, 2239, 362, 483));
	SDL_Rect tempRectSeven;
	tempRectSeven.x = 3900;
	tempRectSeven.y = 2722;
	tempRectSeven.w = 362;
	tempRectSeven.h = 483;
	player.getAnimatedSprite().addFrame(tempRectSeven);// sf::IntRect(3900, 2722, 362, 483));
	SDL_Rect tempRectEight;
	tempRectEight.x = 4262;
	tempRectEight.y = 2722;
	tempRectEight.w = 362;
	tempRectEight.h = 483;
	player.getAnimatedSprite().addFrame(tempRectEight);// sf::IntRect(4262, 2722, 362, 483));
	SDL_Rect tempRectNine;
	tempRectNine.x = 4624;
	tempRectNine.y = 2722;
	tempRectNine.w = 362;
	tempRectNine.h = 483;
	player.getAnimatedSprite().addFrame(tempRectNine);// sf::IntRect(4624, 2722, 362, 483));
	SDL_Rect tempRectTen;
	tempRectTen.x = 3900;
	tempRectTen.y = 3205;
	tempRectTen.w = 362;
	tempRectTen.h = 483;
	player.getAnimatedSprite().addFrame(tempRectTen);// sf::IntRect(3900, 3205, 362, 483));

	player.getAnimatedSpriteFrame().setTime(30);
}
void JumpPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting JumpPlayerState");
	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(true);
}