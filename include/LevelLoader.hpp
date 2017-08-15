#pragma once

#include "level.hpp"

class LevelLoader
{
public:
	Level load(const std::string p_id);
};