#pragma once

#include <Atomic/Engine/Application.h>
#include <Atomic/Input/Input.h>


using namespace Atomic;

class Game : public Atomic::Application {

	// Enable type information.
	ATOMIC_OBJECT(Game, Application)

public:
	Game(Context* context);

	/// Setup before engine initialization. Modifies the engine parameters.
	virtual void Setup();
	/// Setup after engine initialization. Creates the logo, console & debug HUD.
	virtual void Start();
	/// Cleanup after the main loop. Called by Application.
	virtual void Stop();

private:
	void SetWindowTitleAndIcon();


};