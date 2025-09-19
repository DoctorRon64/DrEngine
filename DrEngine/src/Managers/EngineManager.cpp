#include "EngineManager.h"

EngineManager::EngineManager() {
    assetManager = std::make_shared<AssetManager>();

    assetManager->registerLoader<XmlLoader>("xml");
    assetManager->registerLoader<SpriteLoader>("png");
    assetManager->registerLoader<SpriteLoader>("jpg");

    entityManager = std::make_shared<EntityManager>(maxEntities);
    
    std::shared_ptr<Entity> player = entityManager->createEntity();
    std::shared_ptr<Entity> Enemy = entityManager->createEntity();
    std::shared_ptr<Entity> Villager = entityManager->createEntity();
    std::shared_ptr<Entity> NPC = entityManager->createEntity();
    std::shared_ptr<Entity> oBAMA = entityManager->createEntity();
    std::shared_ptr<Entity> Paco = entityManager->createEntity();
}

EngineManager::~EngineManager() {

}

void EngineManager::Update() {

}