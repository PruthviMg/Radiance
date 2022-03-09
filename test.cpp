#include "CGame.hpp"

int main()
{
    std::shared_ptr<CGame> game;
    game = std::make_shared<CGame>();
    game->vCreateComponent();

    while (game->bIsRunning())
    {
        game->vEvent();
        game->vRender();
    }

    return 0;
}