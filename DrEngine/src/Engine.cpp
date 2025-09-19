#include "Engine.h"

Engine::Engine() {
    assetManager = std::make_shared<AssetManager>();
    
    assetManager->registerLoader<XmlLoader>("xml", "assets/configs/");
    assetManager->registerLoader<SpriteLoader>("png", "assets/sprites/");
    assetManager->registerLoader<SpriteLoader>("jpg", "assets/sprites/");
    
    auto keyAsset = assetManager->get<XmlAsset>("'keybinds'.xml");
    std::shared_ptr<rapidxml::xml_document<>> keyConfig = keyAsset->doc;
    inputManager = std::make_shared<InputManager>(keyConfig);




    entityManager = std::make_shared<EntityManager>(200);
    std::shared_ptr<Entity> player = entityManager->createEntity();
    std::shared_ptr<Entity> Enemy = entityManager->createEntity();
    std::shared_ptr<Entity> Villager = entityManager->createEntity();
    std::shared_ptr<Entity> NPC = entityManager->createEntity();
    std::shared_ptr<Entity> oBAMA = entityManager->createEntity();
    std::shared_ptr<Entity> Paco = entityManager->createEntity();
}

Engine::~Engine() {

}

void Engine::Update() {

}