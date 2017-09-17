#pragma once
#include <cstdint>

namespace Config
{
	constexpr uint32_t MAX_FRAMESKIP{ 10 };
	constexpr uint32_t GAME_TARGET_UPS{ 50 };
	constexpr uint32_t GAME_MAX_FPS{ 100 };

	constexpr unsigned WINDOW_WIDTH{ 1000 };
	constexpr unsigned WINDOW_HEIGHT{ 600 };

	constexpr unsigned APP_STATE_CODE_GAME{ 1 };
	constexpr unsigned APP_STATE_CODE_MENU{ 2 };
}


#ifdef WIN32

#include "config.win.hpp"

#else

#include "config.linux.hpp"

#endif

