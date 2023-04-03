//
//  AIComponent.h
//  Collision
//
//  Created by Eli Billinger on 4/13/22.
//

#ifndef AIComponent_h
#define AIComponent_h
#include "Component.h"
#include <string>
#include <map>

class AIComponent : public Component
{
public:
    AIComponent(class Actor* pOwner);
    ~AIComponent();
    
    void Update(float deltaTime) override;
    void RegisterState(class AIState*);
    
    //Change this component's AIState
    void ChangeState(const std::string& stateName);
    
private:
    class AIState* _pCurrentState;
    
    //Map of state name to AIStates this component might need
    std::map<std::string, class AIState*> _mapAIStates;
};

#endif /* AIComponent_h */
