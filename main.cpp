//appwindow.cpp -  a basic SDL window
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>

//SDL window and surfaces to be used 
SDL_Window *window = NULL;

SDL_Surface* screen = NULL;

SDL_Surface* displayedImage = NULL;

SDL_Renderer* myRenderer = NULL;

//image loader
SDL_Surface* loadImage( std::string filename ) {

  SDL_Surface*  loadedImage = SDL_LoadBMP( filename.c_str() ); 

  if( loadedImage == NULL ) {
    std:: cout << "Unable to load image "<< filename.c_str() <<", SDL Error:" <<SDL_GetError() << "\n";
    }

  return loadedImage;
}

int main( int argc, char* argv[] ) {
 
  //Initialization code here - initialize (use SDL_INIT_EVERYTHING because I'm lazy) and use SDL_CreateWindow

  SDL_Init( SDL_INIT_EVERYTHING );

  window = SDL_CreateWindow(
			    "An SDL2 Window", //window title
			    SDL_WINDOWPOS_UNDEFINED, //initial x pos
			    SDL_WINDOWPOS_UNDEFINED, //initial y pos
			    640, //width in pixels
			    480, //height in pixels
			    SDL_WINDOW_SHOWN ); //flag

			    
  if( window == NULL ) {
    std::cout << "Could not create window:\n" << SDL_GetError() << "\n";
    return 1;
  }

  //I quite like the new SDL 2 way of doing things - just grab the details of the window rather than 
  //use SDL_SetVideoMode as in 1.2.
  screen = SDL_GetWindowSurface( window );

  //this is self explanatory... our main event loop

  displayedImage = loadImage( "../helloworld.bmp" );

  bool running = true;
  
  SDL_Event event;

  while( running ) {

    while( SDL_PollEvent( &event ) != 0 ) {
      if( event.type == SDL_QUIT ) {
	running = false;
      }

      else if( event.type == SDL_KEYDOWN ) {
	switch( event.key.keysym.sym ) {
	case SDLK_ESCAPE:
	  running = false;

	default: break;
	}
      }

      SDL_BlitSurface( displayedImage, NULL, screen, NULL );
      SDL_UpdateWindowSurface( window );
    }
  }   

  //cleanup and quit

  SDL_FreeSurface( displayedImage );
  SDL_DestroyWindow( window );
  displayedImage = NULL;
  window = NULL;

  SDL_Quit();
  return 0;
}

