#ifndef CIRCUITMANAGER_HPP
    #define CIRCUITMANAGER_HPP

    #include "EComponent.hpp"
    #include <SFML/Graphics.hpp>
    #include <memory>
    #include <vector>

class CircuitManager
{
    public:
        CircuitManager();
        ~CircuitManager();
        void displayCircuit();
        void displayButton();
        std::vector<std::shared_ptr<EComponent>> getComponents() const;
        template <typename T> 
        void addComponent();
        void changeButtonColor();
        bool changeIndex(sf::Event event);
        void drawName();
        sf::RenderWindow window;
        int index = 0;
    private:
        std::vector<std::shared_ptr<EComponent>> _components;
        sf::RectangleShape button_left;
        sf::RectangleShape button_right;
        sf::ConvexShape arrow_left;
        sf::ConvexShape arrow_right;
};;


#endif /* !CIRCUITMANAGER */
