#pragma once

class Poo
{
public:
	void Update();
	void ProcessConsumption(int dudex, int dudey, int dudewidth, int dudeheight);
	int x;
	int y;
	int vx = 1;
	int vy = 1;
	static constexpr int width = 24;
	static constexpr int height = 24;
	bool isEaten = false;
};