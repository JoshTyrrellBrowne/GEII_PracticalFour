#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

//#include <SFML\Graphics\Sprite.hpp>
//#include <SFML\System\Clock.hpp>
#include <vector>
#include <SDL.h>
#include "Debug.h"

using namespace std;
//using namespace sf;

class AnimatedSprite : public SDL_Rect {
public:
	AnimatedSprite();
	AnimatedSprite(SDL_Texture& t_sdlTexture);
	AnimatedSprite(SDL_Texture& t_sdlTexture, const SDL_Rect& t_sdlRect, SDL_Renderer* t_renderer);
	~AnimatedSprite();

	const int& getTime();
	const vector<SDL_Rect>& getFrames();
	void clearFrames();
	const SDL_Rect& getFrame(int);
	void addFrame(const SDL_Rect&);
	const int getCurrentFrame();
	void setLooped(bool);
	const bool getLooped();
	void setPlayed(bool);
	const bool getPlayed();
	void setTime(int t);
	void setTextureRect(SDL_Rect r);
	void update();
	
private:
	int m_time;
	int m_initialTime; // variable to hold an initial time (used for finding elapsed time)
	int m_elapsedTime; 

	vector<SDL_Rect> m_frames;
	unsigned int m_current_frame;
	bool m_loop;
	unsigned int m_play_count;
	unsigned int m_max_plays;
	bool m_played;
	SDL_Texture* m_texture;
	SDL_Rect m_textureRect;
	SDL_Renderer* m_renderer;
};

#endif // !ANIMATED_SPRITE_H
