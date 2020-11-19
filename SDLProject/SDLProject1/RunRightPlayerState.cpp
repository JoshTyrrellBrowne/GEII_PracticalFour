#include "Events.h"

#include "RunRightPlayerState.h"

#include "AttackPlayerState.h"
#include "ThrowAttackPlayerState.h"
#include "IdlePlayerState.h"
#include "AccendLadderPlayerState.h"
#include "DecendLadderPlayerState.h"
#include "JumpPlayerState.h"
#include "DiedPlayerState.h"
#include "SlidePlayerState.h"

PlayerState* RunRightPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::ATTACK_START_EVENT)
	{
		DEBUG_MSG("RunRightPlayerState -> AttackPlayerState");
		return new AttackPlayerState();
	}
	if (input.getCurrent() == gpp::Events::Event::THROW_START_EVENT)
	{
		DEBUG_MSG("RunRightPlayerState -> ThrowAttackPlayerState");
		return new ThrowAttackPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_WALL_EVENT || input.getCurrent() == gpp::Events::Event::RUN_RIGHT_STOP_EVENT)
	{
		DEBUG_MSG("RunRightPlayerState -> IdlePlayerState");
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT)
	{
		DEBUG_MSG("RunRightPlayerState -> AccendLadderPlayerState");
		return new AccendLadderPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_TOP_EVENT)
	{
		DEBUG_MSG("RunRightPlayerState -> DecendLadderPlayerState");
		return new DecendLadderPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::JUMP_UP_EVENT) {
		DEBUG_MSG("IdlePlayerState -> JumpPlayerState");
		return new JumpPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::SLIDE_EVENT) {
		DEBUG_MSG("RunRightPlayerState -> SlidePlayerState");
		return new SlidePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("RunRightPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void RunRightPlayerState::update(Player& player) {}
void RunRightPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering RunRightPlayerState");
	player.getAnimatedSprite().clearFrames();

	SDL_Rect tempRectOne;
	tempRectOne.x = 4986;
	tempRectOne.y = 3556;
	tempRectOne.w = 363;
	tempRectOne.h = 458;
	player.getAnimatedSprite().addFrame(tempRectOne);// sf::IntRect(4986, 3556, 363, 458));
	SDL_Rect tempRectTwo;
	tempRectTwo.x = 5349;
	tempRectTwo.y = 3556;
	tempRectTwo.w = 363;
	tempRectTwo.h = 458;
	player.getAnimatedSprite().addFrame(tempRectTwo);// sf::IntRect(5349, 3556, 363, 458));
	SDL_Rect tempRectThree;
	tempRectThree.x = 5712;
	tempRectThree.y = 3556;
	tempRectThree.w = 363;
	tempRectThree.h = 458;
	player.getAnimatedSprite().addFrame(tempRectThree);// sf::IntRect(5712, 3556, 363, 458));
	SDL_Rect tempRectFour;
	tempRectFour.x = 4986;
	tempRectFour.y = 4014;
	tempRectFour.w = 363;
	tempRectFour.h = 458;
	player.getAnimatedSprite().addFrame(tempRectFour);// sf::IntRect(4986, 4014, 363, 458));
	SDL_Rect tempRectFive;
	tempRectFive.x = 5349;
	tempRectFive.y = 4014;
	tempRectFive.w = 363;
	tempRectFive.h = 458;
	player.getAnimatedSprite().addFrame(tempRectFive);// sf::IntRect(5349, 4014, 363, 458));
	SDL_Rect tempRectSix;
	tempRectSix.x = 5712;
	tempRectSix.y = 4014;
	tempRectSix.w = 363;
	tempRectSix.h = 458;
	player.getAnimatedSprite().addFrame(tempRectSix);// sf::IntRect(5712, 4014, 363, 458));
	SDL_Rect tempRectSeven;
	tempRectSeven.x = 4986;
	tempRectSeven.y = 4472;
	tempRectSeven.w = 363;
	tempRectSeven.h = 458;
	player.getAnimatedSprite().addFrame(tempRectSeven);// sf::IntRect(4986, 4472, 363, 458));
	SDL_Rect tempRectEight;
	tempRectEight.x = 5349;
	tempRectEight.y = 4472;
	tempRectEight.w = 363;
	tempRectEight.h = 458;
	player.getAnimatedSprite().addFrame(tempRectEight);// sf::IntRect(5349, 4472, 363, 458));
	SDL_Rect tempRectNine;
	tempRectNine.x = 5712;
	tempRectNine.y = 4472;
	tempRectNine.w = 363;
	tempRectNine.h = 458;
	player.getAnimatedSprite().addFrame(tempRectNine);// sf::IntRect(5712, 4472, 363, 458));
	SDL_Rect tempRectTen;
	tempRectTen.x = 4986;
	tempRectTen.y = 4930;
	tempRectTen.w = 363;
	tempRectTen.h = 458;
	player.getAnimatedSprite().addFrame(tempRectTen);// sf::IntRect(4986, 4930, 363, 458));

	player.getAnimatedSpriteFrame().setTime(50);
}
void RunRightPlayerState::exit(Player& player) 
{
	DEBUG_MSG("Exiting RunRightPlayerState");
}