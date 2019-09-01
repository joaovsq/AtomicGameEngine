#pragma once

#include "Sample.h"

namespace Atomic
{

class Node;
class Scene;

}

class Character;
class Touch;

/// Moving character example.
/// This sample demonstrates:
///     - Controlling a humanoid character through physics
///     - Driving animations using the AnimationController component
///     - Manual control of a bone scene node
///     - Implementing 1st and 3rd person cameras, using raycasts to avoid the 3rd person camera clipping into scenery
///     - Defining attributes of a custom component so that it can be saved and loaded
///     - Using touch inputs/gyroscope for iOS/Android (implemented through an external file)
class CharacterDemo : public Sample
{
    ATOMIC_OBJECT(CharacterDemo, Sample)

public:
    /// Construct.
    CharacterDemo(Context* context);
    /// Destruct.
    ~CharacterDemo();

    /// Setup after engine initialization and before running the main loop.
    virtual void Start();

protected:

private:
    /// Create static scene content.
    void CreateScene();
    /// Create controllable character.
    void CreateCharacter();
    /// Construct an instruction text to the UI.
    void CreateInstructions();
    /// Subscribe to necessary events.
    void SubscribeToEvents();
    /// Handle application update. Set controls to character.
    void HandleUpdate(StringHash eventType, VariantMap& eventData);
    /// Handle application post-update. Update camera position after character has moved.
    void HandlePostUpdate(StringHash eventType, VariantMap& eventData);

    /// Touch utility object.
    SharedPtr<Touch> touch_;
    /// The controllable character component.
    WeakPtr<Character> character_;
    /// First person camera flag.
    bool firstPerson_;
};
