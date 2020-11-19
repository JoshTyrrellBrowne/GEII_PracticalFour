#include "Events.h"

#include "IdlePlayerState.h"

#include "AttackPlayerState.h"
#include "ThrowAttackPlayerState.h"
#include "RunRightPlayerState.h"
#include "AccendLadderPlayerState.h"
#include "DecendLadderPlayerState.h"
#include "JumpPlayerState.h"
#include "DiedPlayerState.h"


PlayerState* IdlePlayerState::handleInput(gpp::Events& input) {

	if (input.getCurrent() == gpp::Events::Event::ATTACK_START_EVENT)
	{
		DEBUG_MSG("IdlePlayerState -> AttackPlayerState");
		return new AttackPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::THROW_START_EVENT)
	{
		DEBUG_MSG("IdlePlayerState -> ThrowAttackPlayerState");
		return new ThrowAttackPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT) {
		DEBUG_MSG("IdlePlayerState -> RunRightPlayerState");
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT) {
		DEBUG_MSG("IdlePlayerState -> AccendLadderPlayerState");
		return new AccendLadderPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_TOP_EVENT) {
		DEBUG_MSG("IdlePlayerState -> DecendLadderPlayerState");
		return new DecendLadderPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::JUMP_UP_EVENT) {
		DEBUG_MSG("IdlePlayerState -> JumpPlayerState");
		return new JumpPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("IdlePlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}

void IdlePlayerState::update(Player& player) {}

void IdlePlayerState::enter(Player& player) 
{
	DEBUG_MSG("Entering IdlePlayerState");
	player.getAnimatedSprite().clearFrames();

	SDL_Rect tempRectOne;
	tempRectOne.x = 3900;
	tempRectOne.y = 0;
	tempRectOne.w = 232;
	tempRectOne.h = 439;
	player.getAnimatedSprite().addFrame(tempRectOne);// sf::IntRect(3900, 0, 232, 439));
	SDL_Rect tempRectTwo;
	tempRectTwo.x = 4132;
	tempRectTwo.y = 0;
	tempRectTwo.w = 232;
	tempRectTwo.h = 439;
	player.getAnimatedSprite().addFrame(tempRectTwo);// sf::IntRect(4132, 0, 232, 439));
	SDL_Rect tempRectThree;
	tempRectThree.x = 4364;
	tempRectThree.y = 0;
	tempRectThree.w = 232;
	tempRectThree.h = 439;
	player.getAnimatedSprite().addFrame(tempRectThree);// sf::IntRect(4364, 0, 232, 439));
	SDL_Rect tempRectFour;
	tempRectFour.x = 3900;
	tempRectFour.y = 439;
	tempRectFour.w = 232;
	tempRectFour.h = 439;
	player.getAnimatedSprite().addFrame(tempRectFour);// sf::IntRect(3900, 439, 232, 439));
	SDL_Rect tempRectFive;
	tempRectFive.x = 4132;
	tempRectFive.y = 439;
	tempRectFive.w = 232;
	tempRectFive.h = 439;
	player.getAnimatedSprite().addFrame(tempRectFive);// sf::IntRect(4132, 439, 232, 439));
	SDL_Rect tempRectSix;
	tempRectSix.x = 4364;
	tempRectSix.y = 439;
	tempRectSix.w = 232;
	tempRectSix.h = 439;
	player.getAnimatedSprite().addFrame(tempRectSix);// sf::IntRect(4364, 439, 232, 439));
	SDL_Rect tempRectSeven;
	tempRectSeven.x = 3900;
	tempRectSeven.y = 878;
	tempRectSeven.w = 232;
	tempRectSeven.h = 439;
	player.getAnimatedSprite().addFrame(tempRectSeven);// sf::IntRect(3900, 878, 232, 439));
	SDL_Rect tempRectEight;
	tempRectEight.x = 4132;
	tempRectEight.y = 878;
	tempRectEight.w = 232;
	tempRectEight.h = 439;
	player.getAnimatedSprite().addFrame(tempRectEight);// sf::IntRect(4132, 878, 232, 439));
	SDL_Rect tempRectNine;
	tempRectNine.x = 4364;
	tempRectNine.y = 878;
	tempRectNine.w = 232;
	tempRectNine.h = 439;
	player.getAnimatedSprite().addFrame(tempRectNine);// sf::IntRect(4364, 878, 232, 439));
	SDL_Rect tempRectTen;
	tempRectTen.x = 3900;
	tempRectTen.y = 1317;
	tempRectTen.w = 232;
	tempRectTen.h = 439;
	player.getAnimatedSprite().addFrame(tempRectTen);// sf::IntRect(3900, 1317, 232, 439));
	
	player.getAnimatedSprite().setTime(50);
}

void IdlePlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting IdlePlayerState");
}