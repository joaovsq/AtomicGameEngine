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