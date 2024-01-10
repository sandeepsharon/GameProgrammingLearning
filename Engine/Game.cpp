/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <iostream>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const int shift = 1;
	//int gb = 255;
	// right,top,R,G,B
	

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if(rightInhibit) 
		{
		}
		else {
			rightVelocity = rightVelocity + shift;
			rightInhibit = true;
		}
	}
	else
	{
		rightInhibit = false;		
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (leftInhibit)
		{
		}
		else
		{
			rightVelocity = rightVelocity - shift;
			leftInhibit = true;
		}
	}
	else 
	{
		leftInhibit = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (topInhibit)
		{
		}
		else
		{
			topVelocity = topVelocity - shift;
			topInhibit = true;
		}
	}
	else
	{
		topInhibit = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (downInhibit)
		{
		}
		else
		{
			topVelocity = topVelocity + shift;
			downInhibit = true;
		}	
	}
	else
	{
		downInhibit = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		gb = 0;
	}
	else
	{
		gb = 255;
	}
	shapeIsChanged = wnd.kbd.KeyIsPressed(VK_TAB);
	top = top + topVelocity;
	right = right + rightVelocity;
	if (right + 10 > gfx.ScreenWidth-1)
	{
		right = gfx.ScreenWidth-10;
		rightVelocity = 0;
	}
	if (right - 10 < 0)
	{
		right = 10;
		rightVelocity = 0;
	}
	if (top + 10 > gfx.ScreenHeight - 1)
	{
		top = gfx.ScreenHeight - 10;
		topVelocity = 0;
	}
	if (top - 10 < 0)
	{
		top = 10;
		topVelocity = 0;
	}
	//if (right > 200 && right < 400)
	//{
	//	shapeIsChanged = true;
	//}
;
	if ((right>=secondright-5 && right<=secondright+5) && (top>=secondtop-5 && top<=secondtop+5))
	{
		gb = 0;
	}
	
}

void Game::ComposeFrame()
{
	 
//int top = 300;
	 
//int right = 400;
	DrawBox();
	FixedBox();
}

void Game::DrawBox()
{
	if (shapeIsChanged)
	{
		gfx.PutPixel(right - 3, top, 255, gb, gb);
		gfx.PutPixel(right - 3, top - 1, 255, gb, gb);
		gfx.PutPixel(right - 3, top - 2, 255, gb, gb);
		gfx.PutPixel(right - 3, top - 3, 255, gb, gb);
		gfx.PutPixel(right - 3, top - 4, 255, gb, gb);
		gfx.PutPixel(right - 3, top - 5, 255, gb, gb);

		gfx.PutPixel(right - 3, top + 1, 255, gb, gb);
		gfx.PutPixel(right - 3, top + 2, 255, gb, gb);
		gfx.PutPixel(right - 3, top + 3, 255, gb, gb);
		gfx.PutPixel(right - 3, top + 4, 255, gb, gb);
		gfx.PutPixel(right - 3, top + 5, 255, gb, gb);

		gfx.PutPixel(right + 3, top, 255, gb, gb);
		gfx.PutPixel(right + 3, top - 1, 255, gb, gb);
		gfx.PutPixel(right + 3, top - 2, 255, gb, gb);
		gfx.PutPixel(right + 3, top - 3, 255, gb, gb);
		gfx.PutPixel(right + 3, top - 4, 255, gb, gb);
		gfx.PutPixel(right + 3, top - 5, 255, gb, gb);

		gfx.PutPixel(right + 3, top + 1, 255, gb, gb);
		gfx.PutPixel(right + 3, top + 2, 255, gb, gb);
		gfx.PutPixel(right + 3, top + 3, 255, gb, gb);
		gfx.PutPixel(right + 3, top + 4, 255, gb, gb);
		gfx.PutPixel(right + 3, top + 5, 255, gb, gb);
	}
	else
	{
		gfx.PutPixel(right - 3, top, 255, gb, gb);
		gfx.PutPixel(right - 4, top, 255, gb, gb);
		gfx.PutPixel(right - 5, top, 255, gb, gb);
		gfx.PutPixel(right - 6, top, 255, gb, gb);
		gfx.PutPixel(right - 7, top, 255, gb, gb);
		gfx.PutPixel(right - 8, top, 255, gb, gb);

		gfx.PutPixel(right + 3, top, 255, gb, gb);
		gfx.PutPixel(right + 4, top, 255, gb, gb);
		gfx.PutPixel(right + 5, top, 255, gb, gb);
		gfx.PutPixel(right + 6, top, 255, gb, gb);
		gfx.PutPixel(right + 7, top, 255, gb, gb);
		gfx.PutPixel(right + 8, top, 255, gb, gb);

		gfx.PutPixel(right, top - 3, 255, gb, gb);
		gfx.PutPixel(right, top - 4, 255, gb, gb);
		gfx.PutPixel(right, top - 5, 255, gb, gb);
		gfx.PutPixel(right, top - 6, 255, gb, gb);
		gfx.PutPixel(right, top - 7, 255, gb, gb);
		gfx.PutPixel(right, top - 8, 255, gb, gb);

		gfx.PutPixel(right, top + 3, 255, gb, gb);
		gfx.PutPixel(right, top + 4, 255, gb, gb);
		gfx.PutPixel(right, top + 5, 255, gb, gb);
		gfx.PutPixel(right, top + 6, 255, gb, gb);
		gfx.PutPixel(right, top + 7, 255, gb, gb);
		gfx.PutPixel(right, top + 8, 255, gb, gb);
	}
}

void Game::FixedBox()
{
	gfx.PutPixel(secondright - 3, secondtop, 255, gb, gb);
	gfx.PutPixel(secondright - 3, secondtop - 1, 255, gb, gb);
	gfx.PutPixel(secondright - 3, secondtop - 2, 255, gb, gb);
	gfx.PutPixel(secondright - 3, secondtop - 3, 255, gb, gb);
	gfx.PutPixel(secondright - 3, secondtop - 4, 255, gb, gb);
	gfx.PutPixel(secondright - 3, secondtop - 5, 255, gb, gb);
	gfx.PutPixel(secondright - 3, secondtop + 1, 255, gb, gb);
	gfx.PutPixel(secondright - 3, secondtop + 2, 255, gb, gb);
	gfx.PutPixel(secondright - 3, secondtop + 3, 255, gb, gb);
	gfx.PutPixel(secondright - 3, secondtop + 4, 255, gb, gb);
	gfx.PutPixel(secondright - 3, secondtop + 5, 255, gb, gb);
	gfx.PutPixel(secondright + 3, secondtop, 255, gb, gb);
	gfx.PutPixel(secondright + 3, secondtop - 1, 255, gb, gb);
	gfx.PutPixel(secondright + 3, secondtop - 2, 255, gb, gb);
	gfx.PutPixel(secondright + 3, secondtop - 3, 255, gb, gb);
	gfx.PutPixel(secondright + 3, secondtop - 4, 255, gb, gb);
	gfx.PutPixel(secondright + 3, secondtop - 5, 255, gb, gb);
	gfx.PutPixel(secondright + 3, secondtop + 1, 255, gb, gb);
	gfx.PutPixel(secondright + 3, secondtop + 2, 255, gb, gb);
	gfx.PutPixel(secondright + 3, secondtop + 3, 255, gb, gb);
	gfx.PutPixel(secondright + 3, secondtop + 4, 255, gb, gb);
	gfx.PutPixel(secondright + 3, secondtop + 5, 255, gb, gb);
}