#pragma once

#include <IAppState.hpp>
#include <Text.hpp>

class Menu : public Spirit::IAppState
{
public:

    Menu(const Spirit::AppStateCode p_id);
	virtual bool onEntry() final;
	virtual bool onQuit() final;
	virtual void onEvent(sf::Event & p_event) final;
	virtual void renderFrame(sf::RenderWindow & p_window, const float dt) final;
	virtual Spirit::AppStateCode update(const float dt) final;
	virtual Spirit::AppStateCode getId() const final;


private:
	const Spirit::AppStateCode m_id;
	enum class State { Play = 1, Options, Exit };

	void switchToPreviousMenuState();
	void switchToNextMenuState(); 
	void setMenuState(State p_state);

    State m_currentState;
	Spirit::AppStateCode m_currentAppState;
    Text Play;
    Text Options;
    Text Exit;




};
