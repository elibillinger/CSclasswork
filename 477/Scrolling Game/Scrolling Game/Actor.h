#pragma once

#include <vector>
using namespace std;
#include "Math.h"

class Actor
{
public:
	enum State {
		ACTIVE,
		DEAD
	};

	Actor(class Game* pGame);
	~Actor();

	// Called from the Game class.
	void Update(float deltaTime);

	// Update all the Actor components.
	void UpdateComponents(float deltaTime);

	// Must be overridden, actor-specific code.
	virtual void UpdateActor(float deltaTime);

	// Getters.
	State GetState() const;
    class Game* GetGame() const;

	// Add/remove components to _vecComponents.
	void AddComponent(class Component* pComponent);
	void RemoveComponent(class Component* pComponet);

    const Vector2& GetPosition() const { return _position; }
    void SetPosition(const Vector2& pos) { _position = pos; }
    
private:
	State _state;
    Vector2 _position;

	// Pointer to the over all Game.
	class Game* _pGame;

	// List of all this actor's components.
	vector<class Component*> _vecComponents;
};

