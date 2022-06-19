#include "Screen.h"

namespace GJ {

	Screen::Screen() :
		m_window(NULL) ,
		m_renderer(NULL),
		m_texture(NULL),
		m_buffer(NULL) {

	}

	bool Screen::init() {

		if (SDL_Init(SDL_INIT_VIDEO) < NULL) {
			cout << "Sdl init failed... " << endl;
			return false;
		}

		m_window = SDL_CreateWindow("Particle fire explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (m_window == NULL) {
			SDL_Quit();
			return 2;
		}

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

		if (m_renderer == NULL) {
			cout << "Renderer not created" << endl;
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}
		else {
			cout << "Renderer  created" << endl;
		}
		if (m_texture == NULL) {
			cout << "Texture not created" << endl;

			SDL_DestroyRenderer(m_renderer);
			SDL_Quit();
			return false;
		}
		else {
			cout << "Texture  created" << endl;
		}

		Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

		buffer[30000] = 0xFFFFFFFF;


		for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
			buffer[i] = 0xFFFF00FF; //0x0080FFFF
		}

		SDL_UpdateTexture(m_texture, 0, buffer, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, 0, 0);
		SDL_RenderPresent(m_renderer);

		return true;
	}
	bool Screen::processEvents() {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return false;
			}
		}
		return true;
	}
	void Screen::close() {
		delete[] m_buffer;
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyTexture(m_texture);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}

}