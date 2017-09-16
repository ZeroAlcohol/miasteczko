#pragma once

#include "IAppState.hpp"
#include "ITextureProvider.hpp" 
#include "Level.hpp"

class Game : public Spirit::IAppState
{
public:
    Game(const Spirit::AppStateCode p_id, const Spirit::ITextureProvider &);
	virtual bool onEntry() final;
	virtual bool onQuit() final;
	virtual void onEvent(sf::Event & p_event) final;
	virtual void renderFrame(sf::RenderWindow & p_window, const float dt) final;
	virtual Spirit::AppStateCode update(const float dt) final;
	virtual Spirit::AppStateCode getId() const final;


private:
	const Spirit::AppStateCode m_id;
	bool m_isLoaded;
	const Spirit::ITextureProvider & m_textureProvider;
	Level m_level;
	Spirit::AppStateCode m_currentAppState;
};

