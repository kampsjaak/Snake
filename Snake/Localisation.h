#pragma once
#include <string>

#include "CLI.h"

namespace Snek {
enum class LocalisedString : unsigned short {
	SCORE = 0,
	LIVES = 1,
	QUIT = 2,
	ENUM_LENGTH = 3
};

class Localisation {
public:
	Localisation();
	std::string GetString(const LocalisedString);
	void ImportFromLUA();
private:
	std::string m_strings[static_cast<unsigned short>(LocalisedString::ENUM_LENGTH)];
};
}
