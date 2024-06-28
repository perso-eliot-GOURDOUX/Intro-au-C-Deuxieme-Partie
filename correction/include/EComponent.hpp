#ifndef EComponent_HPP
    #define EComponent_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class EComponent
{
    public:
        EComponent(std::string name) : _name(name) {}
        virtual void displayComponent(sf::RenderWindow &) = 0;
        virtual void handleClickEvent(sf::RenderWindow &window, sf::Event event) = 0;
        virtual ~EComponent() = default;
        std::string getName() const { return _name; }
    private:
        std::string _name;
};

#endif /* !EComponent */
