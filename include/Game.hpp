#pragma once

#include "IAppState.hpp"
#include "ITextureProvider.hpp" 
#include "Level.hpp"

class Game : public IAppState
{
public:
    Game(const Spirit::ITextureProvider &);
	virtual bool onEntry() final;
	virtual bool onQuit() final;
	virtual void onEvent(sf::Event & p_event) final;
	virtual void renderFrame(sf::RenderWindow & p_window, const float dt) final;
	virtual AppStateCode update(const float dt) final;

private:
	bool m_isLoaded;
	const Spirit::ITextureProvider & m_textureProvider;
	Level m_level;
	IAppState::AppStateCode m_currentAppState;
};

