#include "Juego.h"

using namespace Bomberman;
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

void main() {
	srand(static_cast<unsigned>(time(nullptr)));
	// Semilla �nica
	Application::EnableVisualStyles();

	Application::Run(gcnew Juego());
}
