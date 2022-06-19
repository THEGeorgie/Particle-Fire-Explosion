#pragma once
#ifndef SCREEN_H_
#define SCREEN_H_
#include "SDL.h"
#include <iostream>
#undef main
using namespace std;

namespace GJ {
	class Screen
	{
	public:
		static const int SCREEN_WIDTH = 800;
		static const int SCREEN_HEIGHT = 600;
	public:
		Screen();
		bool init();
		bool processEvents();
		void close();
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_texture;
		Uint32* m_buffer;
	};
}
#endif // !SCREEN_H_


