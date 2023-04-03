//
//  MoveComponent.h
//  Asteroid
//
//  Created by Eli Billinger on 4/4/22.
//

#ifndef MoveComponent_h
#define MoveComponent_h

#include "Component.h"

class MoveComponent : public Component
{
public:
    MoveComponent(class Actor* pActorOwner);
    ~MoveComponent();
    
    void Update(float deltaTime) override;
    void SetForwardSpeed(float speed) {_fForwardSpeed = speed;}
    void SetAngularSpeed(float speed) {_fAngularSpeed = speed;}
    
private:
    // Controls rotation (radians/second)
    float _fAngularSpeed;
    //Controls the forward movement (units/second)
    float _fForwardSpeed;
};

#endif /* MoveComponent_h */
