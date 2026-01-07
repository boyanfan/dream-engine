//
// Created by fanboyan on 2025/6/29.
//

#include "ember.h"

namespace Revenants {
    EmberScene::EmberScene(DreamEngine::Camera& camera) : backgroundSequence(loadBackgroundSequence()), camera(camera) {
        // Set up the player character
        playableCharacter = new SwordMaster();
        playableCharacter->transform.position = DreamEngine::Vector2(characterBoundary.rightBoundary / 2, characterBoundary.floorBoundary);

        // Set up the boss character
        bossCharacter = new EmberLord();
        bossCharacter->transform.position = playableCharacter->transform.position;
        bossCharacter->transform.position.x += EMBER_SCENE_INITIAL_BOSS_PLAYABLE_DISTANCE;

        // Set up boss health bar
        bossHealthBar = new DreamEngine::BarView(EMBER_LORD_HEALTH_POINTS * WORLD_LEVEL);
        bossHealthBar->frame = {
            BOSS_HEALTH_BAR_POSITION_X, BOSS_HEALTH_BAR_POSITION_Y, BOSS_HEALTH_BAR_WIDTH, BOSS_HEALTH_BAR_HEIGHT
        };
        bossHealthBar->foregroundColor = DreamEngine::Color(HEALTH_BAR_FOREGROUND_COLOR);
        bossHealthBar->backgroundColor = DreamEngine::Color(HEALTH_BAR_BACKGROUND_COLOR);
        bossHealthBar->trailingColor = DreamEngine::Color(HEALTH_BAR_TRAILING_COLOR);
        bossHealthBar->outlineWidth = BOSS_HEALTH_BAR_OUTLINE_WIDTH;
        bossHealthBar->titleContent = EMBER_LORD_TITLE;
        bossHealthBar->titleFont = DEFAULT_FONT;
        bossHealthBar->titleScaleFactor = BOSS_HEALTH_BAR_TITLE_SCALE_FACTOR;
        bossHealthBar->titlePaddings.bottom = DEFAULT_TITLE_PADDING;

        // Set up camera follow target
        playableCharacter->registerObserver(&camera);
        bossCharacter->registerObserver(bossHealthBar);
        camera.enableTargetFollowing(playableCharacter->transform);

        // Register to pools
        characters.push_back(bossCharacter);
        characters.push_back(playableCharacter);
        views.push_back(bossHealthBar);
    }

    EmberScene::~EmberScene() {
        for (const DreamEngine::View* view : views) { delete view; }
        for (const Character* character : characters) { delete character; }
        views.clear();
        characters.clear();
    }

    void EmberScene::onEntry() {
        // Set up virtual resolution for the scene
        camera.enableVirtualResolution(DreamEngine::Vector2(EMBER_SCENE_BACKGROUND_WIDTH, EMBER_SCENE_BACKGROUND_HEIGHT));

        // Publish boundaries for characters
        for (Character* character : characters) {
            if (character) { character->setBoundary(characterBoundary); character->onEntry(); }
        }
    }

    void EmberScene::onEvent(const SDL_Event& event) {
        for (Character* character : characters) { if (character) character->onEvent(event); }
    }

    void EmberScene::onUpdate(const float interval) {
        // Update characters and UI
        for (Character* character : characters) { if (character) character->onUpdate(interval); }
        for (DreamEngine::View* view : views) { if (view) view->onUpdate(interval); }

        // Check for the camera boundary
        if (camera.transform.position.x <= cameraBoundary.leftBoundary) camera.transform.position.x = cameraBoundary.leftBoundary;
        if (camera.transform.position.x >= cameraBoundary.rightBoundary) camera.transform.position.x = cameraBoundary.rightBoundary;

        // Move foreground fog
        foregroundOffset += EMBER_SCENE_FOREGROUND_SPEED, foregroundOffsetComplementary += EMBER_SCENE_FOREGROUND_SPEED;
        if (foregroundOffset <= -EMBER_SCENE_BACKGROUND_WIDTH) foregroundOffset = EMBER_SCENE_BACKGROUND_WIDTH;
        if (foregroundOffsetComplementary <= -EMBER_SCENE_BACKGROUND_WIDTH) foregroundOffsetComplementary = EMBER_SCENE_BACKGROUND_WIDTH;

        // Should display Health bar
        bossHealthBar->isVisible = bossCharacter->shouldDisplayHealthBar;
    }

    void EmberScene::onRender(const DreamEngine::Camera& camera) const {
        renderBackground();
        for (const Character* character : characters) { if (character) character->onRender(camera); }
        renderForeground();
        for (const DreamEngine::View* view : views) { if (view) view->onRender(camera); }
    }

    void EmberScene::onExit() { camera.disableVirtualResolution(); }

    Identifier EmberScene::getIdentifier() const { return EMBER_SCENE_IDENTIFIER; }

    DreamEngine::TextureSequence EmberScene::loadBackgroundSequence() {
        const DreamEngine::ResourceManager* resourceManager = DreamEngine::ResourceManager::getInstance();
        return DreamEngine::TextureSequence(resourceManager->getTexture(EMBER_SCENE_BACKGROUND), EMBER_SCENE_BACKGROUND_WIDTH, EMBER_SCENE_BACKGROUND_HEIGHT);
    }

    void EmberScene::renderBackground() const {
        constexpr SDL_FRect screenSpace = {0, 0, EMBER_SCENE_BACKGROUND_WIDTH, EMBER_SCENE_BACKGROUND_HEIGHT};

        // Display the sky layer
        DreamEngine::TextureRepresentable backgroundLayer = backgroundSequence.getTexture(0);
        camera.renderTexture(backgroundLayer.texture, &backgroundLayer.source, &screenSpace, 0);

        // Display far mountains
        backgroundLayer = backgroundSequence.getTexture(1);
        camera.renderTexture(backgroundLayer.texture, &backgroundLayer.source, &screenSpace, 0.3);

        // Display close mountains
        backgroundLayer = backgroundSequence.getTexture(2);
        camera.renderTexture(backgroundLayer.texture, &backgroundLayer.source, &screenSpace, 0.5);

        // Display ground
        backgroundLayer = backgroundSequence.getTexture(3);
        camera.renderTexture(backgroundLayer.texture, &backgroundLayer.source, &screenSpace, NO_PARALLEX);
    }

    void EmberScene::renderForeground() const {
        const SDL_FRect screenSpace = {foregroundOffset, 0, EMBER_SCENE_BACKGROUND_WIDTH, EMBER_SCENE_BACKGROUND_HEIGHT};
        const SDL_FRect screenSpaceComplementary = {foregroundOffsetComplementary, 0, EMBER_SCENE_BACKGROUND_WIDTH, EMBER_SCENE_BACKGROUND_HEIGHT};

        // Display the fog
        const DreamEngine::TextureRepresentable backgroundLayer = backgroundSequence.getTexture(4);
        camera.renderTexture(backgroundLayer.texture, &backgroundLayer.source, &screenSpace, NO_PARALLEX);
        camera.renderTexture(backgroundLayer.texture, &backgroundLayer.source, &screenSpaceComplementary, NO_PARALLEX);
    }
}
