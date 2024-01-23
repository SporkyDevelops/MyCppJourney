#include <raylib.h>
#include "game.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval) {

	double currentTime = GetTime();

	if (currentTime - lastUpdateTime >= interval) {

		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

int main() {

	//color is a structure defined in raylib which takes 4 inputs red, green, blue, and the alpha
	Color darkBlue = { 44, 44, 127, 255 };

	//initializes window, takes 3 values
	InitWindow(300, 600, "raylib Tetris");

	//sets targeted frames to value
	SetTargetFPS(60);

	//makes game object of the game class
	Game game = Game();

	//while window is open and esc or x button arent pressed/clicked then it runs the loop
	while (WindowShouldClose() == false) {

		//calls input handler from game class
		game.HandleInput();

		//calls move block down from game
		if (EventTriggered(0.2)) {

			game.MoveBlockDown();
		}

		//creates game/ui canvas for drawing
		BeginDrawing();

		//Clears backround that way every frame is a fresh backround without any artifacts
		ClearBackground(darkBlue);

		//uses the game classes draw function
		game.Draw();

		//closes game/ui canvas for drawing
		EndDrawing();
	}



	CloseWindow();
	return 0;
}