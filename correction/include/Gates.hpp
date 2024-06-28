#ifndef Gates_HPP
    #define Gates_HPP

#include "EComponent.hpp"
#include <memory>
#include <vector>

class AndGate : public EComponent
{
    public:
        AndGate();
        ~AndGate();
        void displayComponent(sf::RenderWindow &window);
        void handleClickEvent(sf::RenderWindow &window, sf::Event event);
        bool getOutput() const { return _output; }
        bool getInput1() const { return _input1; }
        bool getInput2() const { return _input2; }
    private:
        bool _input1 = true;
        bool _input2 = true;
        bool _output = true;
        sf::CircleShape input1;
        sf::CircleShape input2;
        sf::CircleShape output;
        sf::Vertex line1[2];
        sf::Vertex line2[2];
};

class OrGate : public EComponent
{
    public:
        OrGate();
        ~OrGate();
        void displayComponent(sf::RenderWindow &window);
        void handleClickEvent(sf::RenderWindow &window, sf::Event event);
        bool getOutput() const { return _output; }
        bool getInput1() const { return _input1; }
        bool getInput2() const { return _input2; }
    private:
        bool _input1 = true;
        bool _input2 = true;
        bool _output = true;
        sf::CircleShape input1;
        sf::CircleShape input2;
        sf::CircleShape output;
        sf::Vertex line1[2];
        sf::Vertex line2[2];
};

#endif /* !Gates */
