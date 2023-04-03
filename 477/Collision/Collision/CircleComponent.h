//
//  CircleComponent.h
//  Collision
//
//  Created by Eli Billinger on 4/11/22.
//

#ifndef CircleComponent_h
#define CircleComponent_h

#include "Component.h"
#include "Math.h"

class CircleComponent : public Component
{
public:
    CircleComponent(class Actor* pOwner);
    ~CircleComponent();
    
    const Vector2& GetCenter() const;
    
    void SetRadius(float radius) {_fRadius = radius;}
    float GetRadius() const;
    
    bool Intersect(const CircleComponent& other);
    
private:
    float _fRadius;
};


#endif /* CircleComponent_h */
