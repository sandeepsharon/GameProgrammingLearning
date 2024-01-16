#pragma once
//#include "Graphics.h"
class Rectangles {
//	Graphics gx;
public:
	int x0;
	int y0;
	int x1;
	int y1;
	void ClampToScreen();
	bool righthit = false;
	bool lefthit = false;
	bool tophit = false;
	bool bottomhit = false;
};
