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
    
private:
    int _nForwardKey;
    int _nBackwardKey;
    int _nClockwiseKey;
    int _nCounterClockwiseKey;
};

#endif /* InputComponent_h */
