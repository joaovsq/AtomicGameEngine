#include "Game.h"

#include <Atomic/Engine/Application.h>
#include <Atomic/Graphics/Camera.h>
#include <Atomic/Engine/Engine.h>
#include <Atomic/IO/FileSystem.h>
#include <Atomic/Graphics/Graphics.h>
#include <Atomic/Input/Input.h>
#include <Atomic/Input/InputEvents.h>
#include <Atomic/Graphics/Renderer.h>
#include <Atomic/Resource/ResourceCache.h>
#include <Atomic/Scene/Scene.h>
#include <Atomic/Scene/SceneEvents.h>
#include <Atomic/Graphics/Texture2D.h>
#include <Atomic/Core/Timer.h>
#include <Atomic/UI/UI.h>
#include <Atomic/UI/UIView.h>
#include <Atomic/Resource/XMLFile.h>
#include <Atomic/IO/Log.h>
#include <Atomic/Engine/EngineDefs.h>


ATOMIC_DEFINE_APPLICATION_MAIN(Game)

Game::Game(Context* context) : Application(context) {

}

void Game::Setup() {
	// Modify engine startup parameters
	engineParameters_[EP_WINDOW_TITLE] = GetTypeName();
	engineParameters_[EP_WINDOW_WIDTH] = 1440;
	engineParameters_[EP_WINDOW_HEIGHT] = 960;
	engineParameters_[EP_LOG_NAME] = GetSubsystem<FileSystem>()->GetAppPreferencesDir("atomic", "logs") + GetTypeName() + ".log";
	engineParameters_[EP_FULL_SCREEN] = false;
	engineParameters_[EP_HEADLESS] = false;
	engineParameters_[EP_SOUND] = false;
	engineParameters_[EP_RESOURCE_PATHS] = "Resources";

	if (!engineParameters_.Contains(EP_RESOURCE_PREFIX_PATHS))
	{
		engineParameters_[EP_RESOURCE_PREFIX_PATHS] = GAME_ROOT_DIR;
	}
}

void Game::Start()
{

}

void Game::Stop()
{

}

void Game::SetWindowTitleAndIcon()
{
	ResourceCache* cache = GetSubsystem<ResourceCache>();
	Graphics* graphics = GetSubsystem<Graphics>();
	Image* icon = cache->GetResource<Image>("Textures/AtomicIcon48.png");
	graphics->SetWindowIcon(icon);
	graphics->SetWindowTitle("Game");
}