#pragma once

class KeyEvents {
public:
	virtual void key_q(void)=0;
	virtual void key_left(void)=0;
	virtual void key_right(void)=0;
	virtual void key_up(void)=0;
	virtual void key_down(void)=0;
	virtual void key_space(void)=0;
	virtual void key_w(void)=0;
	virtual void key_a(void)=0;
	virtual void key_b(void)=0;
	virtual void key_s(void)=0;
	virtual void key_d(void)=0;
	virtual void key_p(void)=0;
};

extern KeyEvents key_events;
