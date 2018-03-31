#include "stdafx.h"
#include "Engine.h"
#include <iostream>
#include <SDL\SDL.h>
#include <stdio.h>
#include "Scene.h"
#include "SystemManager.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
		SDL_Window* window = NULL;

		//The surface contained by the window
		SDL_Surface* screenSurface = NULL;

		//
		SDL_Surface* ScottOnAJetski = NULL;

		SDL_Surface* CurrentSurface = NULL;

		SDL_Rect* ImageRect = NULL;
		
namespace core {

	Engine::Engine(scene::Scene *s)
	{
	}


	Engine::~Engine()
	{
	}

	int Engine::Init()
	{
		

		//Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Create window
			window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
			if (window == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			}
			else
			{
				//Get window surface
				screenSurface = SDL_GetWindowSurface(window);


				//Fill the surface white
				SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));

				ScottOnAJetski = SDL_LoadBMP("scottjetski.bmp");
				if (ScottOnAJetski == NULL)
				{
					printf("Unable to load image %s! SDL Error: %s\n", "scottjetski.bmp", SDL_GetError());
				}

				SDL_BlitSurface(ScottOnAJetski, NULL, screenSurface, NULL);

				//Update the surface
				SDL_UpdateWindowSurface(window);

				//Wait two seconds
				SDL_Delay(20000);
			}
		}

		//Deallocate surface
		SDL_FreeSurface(ScottOnAJetski);
		ScottOnAJetski = NULL;

		//Destroy window
		SDL_DestroyWindow(window);
		window = NULL;

		//Quit SDL subsystems
		SDL_Quit();

		return 0;
	}

	void Engine::Draw() const
	{
		/*SDL_Surface* ScottOnAJetski = NULL;

		ScottOnAJetski = SDL_LoadBMP("scottjetski.bmp");
		if (ScottOnAJetski == NULL)
		{
			printf("Unable to load image %s! SDL Error: %s\n", "scottjetski.bmp", SDL_GetError());
		}*/

	}

	void Engine::Update()
	{
		/*Scene1->Update();*/

		SDL_Event e;

		while (SDL_PollEvent(&e) != 0) {

			switch (e.type) {

			case SDL_KEYDOWN:

				switch (e.key.keysym.sym) {

				case SDLK_LEFT:
					std::cout << "left " << std::endl;
					ImageRect->x--;
					break;

				case SDLK_RIGHT:
					ImageRect->x++;
					break;

				case SDLK_DOWN:
					ImageRect->y++;
					break;

				case SDLK_UP:
					ImageRect->y--;
					break;
				}
				break;
			}

		}
		
	}

	void Engine::print()
	{
		std::cout << "this is working" << std::endl;
	}
}