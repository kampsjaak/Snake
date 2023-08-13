#include <iostream>

#include "Localisation.h"
#include "lua.hpp"

Snek::Localisation::Localisation() {
	ImportFromLUA();
};

std::string Snek::Localisation::GetString(LocalisedString localised_string) {
	return m_strings[static_cast<unsigned short>(localised_string)];
};

void Snek::Localisation::ImportFromLUA() {
	lua_State* L;
	L = luaL_newstate();
	luaL_openlibs(L);

	if (!luaL_dofile(L, "Language.lua") == LUA_OK) {
		std::cout << "[C] Error reading script\n";
		luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
		lua_close(L);
		return;
	}
	
	for (unsigned short i = 0; i < static_cast<unsigned short>(LocalisedString::ENUM_LENGTH); i++) {
		lua_getglobal(L, "GetLocalisedString");
		
		if (!lua_isfunction(L, -1)) {
			lua_close(L);
			return;
		}

		lua_pushnumber(L, i);
		lua_pushnumber(L, CLI::LANGUAGE+1);

		const int arguments_count = 2;
		const int returnvalues_count = 1;

		lua_pcall(L, arguments_count, returnvalues_count, 0);
		std::string result = std::string(lua_tostring(L, -1));

		m_strings[i] = result;
	}

	lua_close(L);
};