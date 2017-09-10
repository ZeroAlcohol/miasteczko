#pragma once

#include <IAppState.hpp>
#include <Level.hpp>

class Game : public IAppState
{
public:
    Game();
	virtual bool onEntry() final;
	virtual bool onQuit() final;
	virtual void onEvent(sf::Event & p_event) final;
	virtual void renderFrame(sf::RenderWindow & p_window, const float dt) final;
	virtual AppStateCode update(const float dt) final;

private:
	bool m_isLoaded;
	Level m_level;
	IAppState::AppStateCode m_currentAppState;
};

