#include "UnnamedEngine.h"

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	auto* windowPtr = SDL_CreateWindow(
		"Unnamed Engine"
		, SDL_WINDOWPOS_UNDEFINED
		, SDL_WINDOWPOS_UNDEFINED
		, 800
		, 600
		, SDL_WINDOW_OPENGL
	);

	if (windowPtr == nullptr)
	{
		std::printf("Could not create window: %s", SDL_GetError());
		return 1;
	}

	// Add application stuff here.

	SDL_Delay(3000); // Yolo

	SDL_DestroyWindow(windowPtr);

	return 0;
}
