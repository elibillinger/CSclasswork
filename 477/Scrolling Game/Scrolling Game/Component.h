#pragma once

class Component
{
public:
	Component(class Actor* pActorOwner);
	virtual ~Component();

	// Update method for all Components, can be overridden.
	virtual void Update(float deltaTime);

protected:
	class Actor* _pActorOwner;
};

