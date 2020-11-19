#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite() : 
	m_current_frame(0),
	m_time(500), // 500 milliseconds for each frame
	m_loop(true),
	m_play_count(0),
	m_max_plays(0),
	m_played(false)
{
	DEBUG_MSG("AnimatedSprite()");
	m_initialTime = SDL_GetTicks();
}

AnimatedSprite::AnimatedSprite(SDL_Texture& t_sdlTexture) : AnimatedSprite(){
	DEBUG_MSG("AnimatedSprite(const Texture&)");
	m_texture = &t_sdlTexture; 
}

AnimatedSprite::AnimatedSprite(SDL_Texture& t_sdlTexture, const SDL_Rect& t_sdlRect, SDL_Renderer* t_renderer) :
	AnimatedSprite(t_sdlTexture)
{
	DEBUG_MSG("AnimatedSprite(const Texture&, const IntRect&)");
	m_frames.push_back(t_sdlRect);
	m_renderer = t_renderer;
}

AnimatedSprite::~AnimatedSprite() {
	DEBUG_MSG("~AnimatedSprite()");
	SDL_DestroyTexture(m_texture);
}

const int& AnimatedSprite::getTime() {
	return m_time;
}

void AnimatedSprite::setTime(int t)
{
	this->m_time = t;
}

void AnimatedSprite::setTextureRect(SDL_Rect r)
{
	m_textureRect = r;
}

const vector<SDL_Rect>& AnimatedSprite::getFrames() {
	return m_frames;
}

void AnimatedSprite::clearFrames() {
	m_current_frame = 0;
	m_played = false;
	if (!m_frames.empty())
	{
		m_frames.clear();
	}
}

const SDL_Rect& AnimatedSprite::getFrame(int n) {
	return m_frames[n];
}

void AnimatedSprite::addFrame(const SDL_Rect& frame) {
	m_frames.push_back(frame);
}

const int AnimatedSprite::getCurrentFrame() {
	return m_current_frame;
}

void AnimatedSprite::setLooped(bool loop) {
	this->m_loop = loop;
}

const bool AnimatedSprite::getLooped() {
	return this->m_loop;
}

void AnimatedSprite::setPlayed(bool played) {
	this->m_played = played;
}

const bool AnimatedSprite::getPlayed() {
	return this->m_played;
}

void AnimatedSprite::update(){
	// If not looped only play once
	if (m_played == true && !m_loop)
	{
		m_current_frame = m_frames.size() - 1;
	}
	else {
		if (m_initialTime - SDL_GetTicks() > m_time) {
			m_initialTime = SDL_GetTicks(); // reset for next check
			if (m_frames.size() > (m_current_frame + 1))
			{
				m_current_frame++;
			}
			else {
				m_current_frame = 0;
				m_played = true;
			}
		}
	}
	
}

