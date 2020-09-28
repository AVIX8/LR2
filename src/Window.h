#ifndef WINDOW_h_
#define WINDOW_h_

#include <stdio.h>
#include "SDL2/SDL.h"
#include "Vector2.h"

SDL_Window *WindowInit()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("SDL_Error: %s\n", SDL_GetError());
	}

	SDL_Window *window = SDL_CreateWindow("DA", SDL_WINDOWPOS_CENTERED, 25, 501, 501, 0);
	SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	return window;
}

void WindowClear(SDL_Window *window)
{
	SDL_Renderer *renderer = SDL_GetRenderer(window);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 96, 96, 96, 255);

	for (int x = 0; x <= 500; x += 25)
	{
		SDL_RenderDrawLine(renderer, x, 0, x, 500);
	}

	for (int y = 0; y <= 500; y += 25)
	{
		SDL_RenderDrawLine(renderer, 0, y, 500, y);
	}

	SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255);
	SDL_RenderDrawLine(renderer, 250, 0, 250, 500);
	SDL_RenderDrawLine(renderer, 0, 250, 500, 250);

	SDL_RenderPresent(renderer);
}

void DrawVector2(SDL_Window *window, Vector2 *vector)
{
	SDL_Renderer *renderer = SDL_GetRenderer(window);

	SDL_SetRenderDrawColor(renderer, vector->color[0], vector->color[1], vector->color[2], 255);
	SDL_RenderDrawLine(renderer, 250, 250, 250 + vector->x * 25, 250 + vector->y * -25);

	SDL_RenderPresent(renderer);
}

void Quit(SDL_Window *window)
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

#endif