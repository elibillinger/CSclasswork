//
//  InputComponent.h
//  Asteroid
//
//  Created by Eli Billinger on 4/6/22.
//

#ifndef InputComponent_h
#define InputComponent_h

#include "MoveComponent.h"
#include "SDL2/SDL.h"


class InputComponent: public MoveComponent
{
public:
    InputComponent(class Actor* pOwner);
    ~InputComponent();
    
    virtual void ProcessInput(const Uint8* keyboardState);
    void SetForwardKey(int key) { _nForwardKey = key;}
    void SetBackKey(int key) { _nBackwardKey = key;}
    void SetClockwiseKey(int key) { _nClockwiseKey = key;}
    void SetCounterClockwiseKey(int key) { _nCounterClockwiseKey = key;}
    void SetMaxForwardSpeed(float speed) {_nMaxForwardSpeed = speed;}
    void SetMaxAngularSpeed(float speed) {_nMaxAngularSpeed = speed;}
    
private:
    int _nForwardKey;
    int _nBackwardKey;
    int _nClockwiseKey;
    int _nCounterClockwiseKey;
    
    float _nMaxForwardSpeed;
    float _nMaxAngularSpeed;
    
};

#endif /* InputComponent_h */
