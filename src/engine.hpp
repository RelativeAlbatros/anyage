#pragma once

class Engine {
private:
		void process_key_events(int ch);

		// framerate
		unsigned int _frames = 0;
		double _start_time = 0;
		double _time_passed = 0;
		bool _first = true;
		float _fps = 0.0f;
public:
    Engine(unsigned int frames);
    virtual ~Engine();

    void run();
    void terminate();
    virtual void update()=0;
};
