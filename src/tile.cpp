#include <SDL2/SDL.h>

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

Tile::Tile( const int tileWidth, const int tileHeight, const int x, const int y, const int tileType )
{
    //Get the offsets
    mBox.x = x;
    mBox.y = y;
    //Set the collision box
    mBox.w = tileWidth;
    mBox.h = tileHeight;
    //Get the tile type
    mType = tileType;
}

void Tile::render(SDL_Rect& camera, LTexture* tex, SDL_Rect* gTileClips, SDL_Renderer* gRenderer)
{
    //If the tile is on screen
    if( checkCollision(camera, mBox))
    {
        //Show the tile
        tex->render(gRenderer, mBox.x - camera.x, mBox.y - camera.y, &gTileClips[ mType ]);
    }
}

int Tile::getType()
{
    return mType;
}

SDL_Rect Tile::getBox()
{
    return mBox;
}

bool Tile::checkCollision( SDL_Rect a, SDL_Rect b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}