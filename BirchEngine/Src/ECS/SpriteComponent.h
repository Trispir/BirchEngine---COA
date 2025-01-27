#pragma once
#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"



class SpriteComponent : public Component
{
private:

	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

public:

	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		setTex(path);
	}
	~SpriteComponent()
	{
		SDL_DestroyTexture(texture);
	}

	void setTex(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}
	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		srcRect.h = destRect.h = 64;
	}

	void update() override
	{
		destRect.x = (int)transform->position.x;
		destRect.x = (int)transform->position.y;

	}

	void draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}

};