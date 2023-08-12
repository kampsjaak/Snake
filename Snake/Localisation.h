#pragma once
#include <string>

enum class LocalisedString : unsigned short {
	SCORE = 0,
	LIVES = 1,
	QUIT = 2,
	ENUM_LENGTH = 3
};

class Localisation {
public:
	Localisation() {};
	Localisation(unsigned short);
	std::string GetString(LocalisedString);
	void ImportFromLUA();
private:
	std::string m_strings[static_cast<unsigned short>(LocalisedString::ENUM_LENGTH)];
	unsigned short m_language = 0;
};

