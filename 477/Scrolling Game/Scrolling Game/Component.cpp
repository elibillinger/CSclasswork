#include "Component.h"
#include "Actor.h"


Component::Component(Actor* pActorOwner) {
	_pActorOwner = pActorOwner;

    // Tell my actor owner to add me to its list.
	_pActorOwner->AddComponent(this);
}


Component::~Component() {
    // Tell my actor owner to remove me from its list.
	_pActorOwner->RemoveComponent(this);
}

void Component::Update(float deltaTime) {

}
