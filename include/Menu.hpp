#pragma once

#include <IAppState.hpp>
#include <Text.hpp>

class Menu : public IAppState
{
public:

    Menu();
	virtual bool onEntry() final;
	virtual bool onQuit() final;
	virtual void onEvent(sf::Event & p_event) final;
	virtual void renderFrame(sf::RenderWindow & p_window, const float dt) final;
	virtual AppStateCode update(const float dt) final;

private:
	enum class State { Play = 1, Options, Exit };

	void switchToPreviousMenuState();
	void switchToNextMenuState(); 
	void setMenuState(State p_state);

    State m_currentState;
	AppStateCode m_currentAppState;
    Text Play;
    Text Options;
    Text Exit;




};
