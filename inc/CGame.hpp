#ifndef CGAME_HPP
#define CGAME_HPP

#include "IComponent.hpp"
#include <iostream>
#include <memory>
#include </usr/include/SFML/Graphics.hpp>

class CGame : public IComponent
{
private:
    std::shared_ptr<sf::RenderWindow> m_sharedPtrWindow;
    sf::Event m_event;
    sf::RectangleShape m_rectangle;

    void vKeyFunction();

    void vShape();

public:
    CGame();
    ~CGame();

    void vCreateComponent() override;
    void vDestroyComponent() override;
    bool bIsRunning();

    void vEvent();
    void vRender();
};

#endif
