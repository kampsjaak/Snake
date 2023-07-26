#pragma once
#include <string>

enum LocalisedString {
	SCORE,
	LIVES,
	ENUM_LENGTH = 2
};

class Localisation {
public:
	std::string GetString(LocalisedString);
	void ImportFromLUA();
private:
	std::string m_strings[LocalisedString::ENUM_LENGTH];
	
};

