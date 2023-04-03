//
//  BGSpriteComponent.h
//  Scrolling Game
//
//  Created by Eli Billinger on 4/6/22.
//

#ifndef BGSpriteComponent_h
#define BGSpriteComponent_h

#include "SpriteComponent.h"
#include <vector>
#include "Math.h"

class BGSpriteComponent : public SpriteComponent
{
public:

    BGSpriteComponent(class Actor* pActorOwner);
    ~BGSpriteComponent();

    void Update(float deltaTime) override;
    void Draw(SDL_Renderer* pRenderer) override;

    void SetBGTextures(const std::vector<SDL_Texture*>& textures);
    void SetScreenSize(const Vector2& size);
    void SetScrollSpeed(float speed);

    float GetScrollSpeed() const { return _pScrollSpeed; }

private:
    struct BGTexture{
        SDL_Texture* texture;
        Vector2 offset;
    };

    std::vector<BGTexture> _pBGTextures;

    Vector2 _pScreenSize;
    float _pScrollSpeed;

};

#endif /* BGSpriteComponent_h */


