#include "CGame.hpp"

CGame::CGame() : m_sharedPtrWindow(nullptr)
{
}

CGame::~CGame()
{
}

void CGame::vCreateComponent()
{
    m_sharedPtrWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(600, 600), "Game!");
    m_sharedPtrWindow->setFramerateLimit(144);
    vShape();
}

void CGame::vDestroyComponent()
{
    m_sharedPtrWindow.reset();
}

bool CGame::bIsRunning()
{
    return m_sharedPtrWindow->isOpen();
}

void CGame::vKeyFunction()
{
    if (m_event.key.code == sf::Keyboard::Escape || m_event.key.code == sf::Keyboard::Q)
        m_sharedPtrWindow->close();

    if (m_event.key.code == sf::Keyboard::Right || m_event.key.code == sf::Keyboard::D)
        m_rectangle.move(10.f, 0.f);

    if (m_event.key.code == sf::Keyboard::Left || m_event.key.code == sf::Keyboard::A)
        m_rectangle.move(-10.f, 0.f);

    if (m_event.key.code == sf::Keyboard::Up || m_event.key.code == sf::Keyboard::W)
        m_rectangle.move(0.f, -10.f);

    if (m_event.key.code == sf::Keyboard::Down || m_event.key.code == sf::Keyboard::S)
        m_rectangle.move(0.f, 10.f);
}

void CGame::vEvent()
{
    while (m_sharedPtrWindow->pollEvent(m_event))
    {
        switch (m_event.type)
        {
        case sf::Event::Closed:
            m_sharedPtrWindow->close();
            break;

        case sf::Event::KeyPressed:
            vKeyFunction();
            break;
        }
    }
}

void CGame::vShape()
{
    m_rectangle.setPosition(300.f, 300.f);
    m_rectangle.setSize(sf::Vector2f(10.f, 10.f));
    m_rectangle.setFillColor(sf::Color::Blue);
    m_rectangle.setOutlineColor(sf::Color::Green);
    m_rectangle.setOutlineThickness(1.f);
}

void CGame::vRender()
{
    m_sharedPtrWindow->clear(sf::Color::Cyan);
    m_sharedPtrWindow->draw(m_rectangle);
    m_sharedPtrWindow->display();
}