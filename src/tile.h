#ifndef TILE_H
#define TILE_H
#include <SDL2/SDL.h> // TODO : can I delete this include when I fix all the other errors?
#include "texture.h"
//The tile
class Tile
{
    public:
		//Initializes position and type
		Tile( const int, const int, const int, const int, const int);
		//Shows the tile
        void render(SDL_Rect& camera, LTexture* t, SDL_Rect* s, SDL_Renderer* r);
		//Get the tile type
		int getType();
        static bool checkCollision( SDL_Rect a, SDL_Rect b );
		//Get the collision box
		SDL_Rect getBox();

    private:
		//The attributes of the tile
		SDL_Rect mBox;
		//The tile type
		int mType;
};
#endif