#include "Actor.h"
#include "Component.h"
#include "Game.h"


Actor::Actor(Game* pGame) {
	_pGame = pGame;
	_state = ACTIVE;

    // Tell the Game to add this actor to its list.
	_pGame->AddActor(this);
}


Actor::~Actor() {
    // Tell the Game to remove this actor from its list.
	_pGame->RemoveActor(this);

	// Cleanup all this actor's components.
	while (!_vecComponents.empty()) {
		delete _vecComponents.back();
	}

}

// Called from the Game loop.
void Actor::Update(float deltaTime) {
	UpdateComponents(deltaTime);
	UpdateActor(deltaTime);
}

// Update all this actor's components.
void Actor::UpdateComponents(float deltaTime) {
	for (Component* pc : _vecComponents) {
		pc->Update(deltaTime);
	}
}

// Overrideable by child classes, base class does nothing.
void Actor::UpdateActor(float deltaTime) {

}

// Getter for state.
Actor::State Actor::GetState() const {
	return _state;
}

// Getter for Game pointer.
Game* Actor::GetGame() const {
    return _pGame;
}

// Add component to _vecComponents list.
void Actor::AddComponent(Component* pComponent) {
	_vecComponents.push_back(pComponent);
}

// Remove component from _vecComponents list.
void Actor::RemoveComponent(Component* pComponent) {
	vector<Component*>::iterator it = find(_vecComponents.begin(), _vecComponents.end(), pComponent);
	if (it != _vecComponents.end()) {
		_vecComponents.erase(it);
	}
}
