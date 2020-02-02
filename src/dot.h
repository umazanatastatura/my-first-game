#ifndef DOT_H
#define DOT_H
#include <SDL2/SDL.h> // TODO : can I delete this include when I fix all the other errors?
#include "tile.h"

//The dot that will move around on the screen
class Dot
{
    public:

        //Checks collision box against set of tiles
        bool touchesWall( SDL_Rect box, Tile* tiles[] );

		//The dimensions of the dot
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 20;

		//Maximum axis velocity of the dot
		static const int DOT_VEL = 10;

		//Initializes the variables
		Dot(LTexture* t);

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot and check collision against tiles
		void move( Tile *tiles[] );

		//Centers the camera over the dot
		void setCamera( SDL_Rect& camera );

		//Shows the dot on the screen
		void render( SDL_Rect& camera, SDL_Renderer* gRenderer);

    private:
		//Collision box of the dot
		SDL_Rect mBox;
		//The velocity of the dot
		int mVelX, mVelY;
        // Texture associated with dot
        LTexture* mDotTexture;
};
#endif