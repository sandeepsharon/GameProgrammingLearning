#include "Rectangles.h"
#include"Graphics.h"

void Rectangles::ClampToScreen()
{
	const int right = x0 + x1;
	const int bottom = y0 + y1;
	const int tempx1 = x1;
	if (x0<=0)
	{
		x0 = 0;
		lefthit = true;
	}
	else if (x1>=Graphics::ScreenWidth-1)
	{
		x1 = Graphics::ScreenWidth - 1;
		righthit = true;
	}
	else
	{
		righthit = false;
		lefthit = false;
	}

	if (y0 <= 0)
	{
		y0 = 0;
		tophit = true;
	}
	else if (y1 >= Graphics::ScreenHeight-1)
	{
		y1 = Graphics::ScreenHeight - 1;
		bottomhit = true;
	}
	else
	{
		tophit = false;
		bottomhit = false;
	}

}
