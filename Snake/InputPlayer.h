#pragma once


#ifdef _WIN32
#include <windows.h> // input https://visualstudioclient.gallerycdn.vsassets.io/extensions/visualstudioclient/microsoftvisualstudio2017installerprojects/1.0.0/1620063166533/InstallerProjects.vsix
#elif defined(__linux__)

#endif

#include "Player.h"

namespace Snek {
class InputPlayer
{
public:
	InputPlayer() {};
	InputPlayer(Player*);

	void Update();
private:
	Player* m_player = nullptr;
};
}
