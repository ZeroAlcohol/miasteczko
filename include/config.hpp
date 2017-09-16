#pragma once
#include <cstdint>

constexpr uint32_t MAX_FRAMESKIP{ 10 };
constexpr uint32_t GAME_TARGET_UPS{ 50 };
constexpr uint64_t DELAY_PER_UPDATE_FRAME{ 1000000ULL / GAME_TARGET_UPS };
constexpr float DELAY_PER_UPDATE_FRAME_SEC{ 1.0f/ GAME_TARGET_UPS };
constexpr uint32_t GAME_MAX_FPS{ 100 };
constexpr uint64_t MIN_DELAY_PER_RENDER_FRAME{ 1000000ULL / GAME_MAX_FPS };

constexpr unsigned WINDOW_WIDTH{ 1000 };
constexpr unsigned WINDOW_HEIGHT{ 600 };

constexpr unsigned APP_STATE_CODE_GAME{ 1 };
constexpr unsigned APP_STATE_CODE_MENU{ 2 };

#ifdef WIN32

#include "config.win.hpp"

#else

#include "config.linux.hpp"

#endif

