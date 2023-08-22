#pragma once
#include"define.h"

class Animation
{
public:

	Animation(Texture* texture, Vector2u imageCount, float switchTime);
	~Animation();
	Animation();
	void Update(int row, float deltaTime);
	IntRect uvRect;
private:
	Vector2u imageCount;
	Vector2u currentImage;
	float totalTime;
	float switchTime;
};
