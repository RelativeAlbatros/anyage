#include "engine.hpp"
#include "util/input.hpp"

Engine::Engine(unsigned int frames)
: _frames(frames) {
}

void Engine::process_key_events(int ch) {
    if(ch == 'q') {
        key_events.key_q();
    }
}
