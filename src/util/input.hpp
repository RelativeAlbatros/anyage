#pragma once

class KeyEvents {
public:
	virtual void key_q(void);
	virtual void key_left(void);
	virtual void key_right(void);
	virtual void key_up(void);
	virtual void key_down(void);
	virtual void key_space(void);
	virtual void key_w(void);
	virtual void key_a(void);
	virtual void key_b(void);
	virtual void key_s(void);
	virtual void key_d(void);
	virtual void key_p(void);
};

extern KeyEvents key_events;
