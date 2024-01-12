#include "Rectangles.h"
#include"Graphics.h"

void Rectangles::ClampToScreen()
{
	const int right = x + length;
	const int bottom = y + breadth;
	if (x<0)
	{
		x = 0;
	}
	else if (right>=Graphics::ScreenWidth)
	{
		x = Graphics::ScreenWidth - 1 - length;
	}
	if (y < 0)
	{
		y = 0;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - 1 - breadth;
	}

}
