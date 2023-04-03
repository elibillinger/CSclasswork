//
//  AIState.h
//  Collision
//
//  Created by Eli Billinger on 4/13/22.
//

#ifndef AIState_h
#define AIState_h

class AIState
{
public:
    AIState(class AIComponent* pOwner);
    ~AIState();
    
    virtual void Update(float deltaTime) = 0;
    virtual void OnEnter() = 0;
    virtual void OnExit() = 0;
    
    virtual const char* GetName() const = 0;
    
protected:
    class AIComponent* _pOwner;
};


class AIPatrol : public AIState {
public:
    AIPatrol(class AIComponent* pOwner) : AIState(pOwner){
        
    }
    //override four pure virtual methods
    void Update(float deltatime) override;
    void OnEnter() override;
    void OnExit() override;
    
    const char* GetName() const override {
        return "Patrol";
    }
    
};


class AIAttack : public AIState {
public:
    AIAttack(class AIComponent* pOwner) : AIState(pOwner){
        
    }
    //override four pure virtual methods
    void Update(float deltatime) override;
    void OnEnter() override;
    void OnExit() override;
    
    const char* GetName() const override {
        return "Attack";
    }
    
};


#endif /* AIState_h */
