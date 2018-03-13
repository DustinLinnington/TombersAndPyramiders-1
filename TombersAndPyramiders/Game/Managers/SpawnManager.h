#pragma once

#include <memory>
#include "Wall.h"
#include "MiscSquare.h"
#include "MovingSquare.h"
#include "Character.h"
#include "BaseItem.h"
#include "WorldItem.h"
#include "HostCharacter.h"
#include "ClientCharacter.h"
#include "GhostCharacter.h"
#include "Boulder.h"
#include "SingleDoor.h"

class SpawnManager : public GameObject
{
public:
	SpawnManager();
	~SpawnManager();
	std::shared_ptr<MiscSquare> generateMiscSquare(float x, float y, float z, float scale, string spriteName, bool hasCollider, float colliderSize = 5);
	//std::shared_ptr<Wall> generateWall(float x, float y, float scale);
	//std::shared_ptr<MiscSquare> generateMiscSquare(float x, float y, float scale);
	std::shared_ptr<MovingSquare> generateMovingSquare(float x, float y);
	std::shared_ptr<Character> generatePlayerCharacter(float x, float y);
	std::shared_ptr<Character> generateAiCharacter(float x, float y);
	std::shared_ptr<WorldItem> generateWorldItem(float x, float y, std::shared_ptr<BaseItem> item);
	std::shared_ptr<Character> generateDummyCharacter(float x, float y);
	std::shared_ptr<GhostCharacter> generateGhost(float x, float y);
	std::shared_ptr<Boulder> generateBoulder(float x, float y); 
	std::shared_ptr<SingleDoor> generateSingleDoor(float x, float y, Door::Direction direction, Door::Mode startState);


	std::shared_ptr<HostCharacter> generateNetworkCharacter(Uint32 ip, float x, float y);

	std::shared_ptr<ClientCharacter> generatePlayerCharacter(Uint32 ip, float x, float y);
	void sendStartPacket();

	static std::shared_ptr<SpawnManager> getInstance();

private:
	static std::shared_ptr<SpawnManager> s_instance;
};