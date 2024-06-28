#include "Gates.hpp"
#include <math.h>

AndGate::AndGate() : EComponent("AndGate")
{
    input1.setRadius(20);
    input1.setFillColor(sf::Color::Green);
    input1.setPosition(450, 450);

    input2.setRadius(20);
    input2.setFillColor(sf::Color::Green);
    input2.setPosition(330, 450);

    output.setRadius(20);
    output.setFillColor(sf::Color::Red);
    output.setPosition(390, 100);

    line1[0].position = sf::Vector2f(470, 470);
    line1[1].position = sf::Vector2f(410, 120);
    line2[0].position = sf::Vector2f(350, 470);
    line2[1].position = sf::Vector2f(410, 120);
}

AndGate::~AndGate()
{
}

void AndGate::displayComponent(sf::RenderWindow &window)
{
    // std::cout << "AND GATE\n";
    // std::cout << "   o\n";
    // std::cout << "  / \\\n";
    // std::cout << " o   o\n";
    // std::cout << "  \\ /\n";
    // std::cout << "   o\n";
    if (_input1) {
        input1.setFillColor(sf::Color::Green);
    } else {
        input1.setFillColor(sf::Color::Red);
    }
    if (_input2) {
        input2.setFillColor(sf::Color::Green);
    } else {
        input2.setFillColor(sf::Color::Red);
    }
    _output = _input1 && _input2;
    if (_output) {
        output.setFillColor(sf::Color::Green);
    } else {
        output.setFillColor(sf::Color::Red);
    }

    window.draw(line1, 2, sf::Lines);
    window.draw(line2, 2, sf::Lines);
    window.draw(input1);
    window.draw(input2);
    window.draw(output);
}

void AndGate::handleClickEvent(sf::RenderWindow &window, sf::Event event)
{
    std::cout << "Handling click event for and gate\n";
    if (input1.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
        _input1 = !_input1;
    }
    if (input2.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
        _input2 = !_input2;
    }
}

OrGate::OrGate() : EComponent("OrGate")
{
    input1.setRadius(20);
    input1.setFillColor(sf::Color::Green);
    input1.setPosition(450, 450);

    input2.setRadius(20);
    input2.setFillColor(sf::Color::Green);
    input2.setPosition(330, 450);

    output.setRadius(20);
    output.setFillColor(sf::Color::Red);
    output.setPosition(390, 100);

    line1[0].position = sf::Vector2f(470, 470);
    line1[1].position = sf::Vector2f(410, 120);
    line2[0].position = sf::Vector2f(350, 470);
    line2[1].position = sf::Vector2f(410, 120);
}

OrGate::~OrGate()
{
}

void OrGate::displayComponent(sf::RenderWindow &window)
{
    // std::cout << "OR GATE\n";
    // std::cout << "   o\n";
    // std::cout << "  / \\\n";
    // std::cout << " o   o\n";
    // std::cout << "  \\ /\n";
    // std::cout << "   o\n";
    if (_input1) {
        input1.setFillColor(sf::Color::Green);
    } else {
        input1.setFillColor(sf::Color::Red);
    }
    if (_input2) {
        input2.setFillColor(sf::Color::Green);
    } else {
        input2.setFillColor(sf::Color::Red);
    }
    _output = _input1 || _input2;
    if (_output) {
        output.setFillColor(sf::Color::Green);
    } else {
        output.setFillColor(sf::Color::Red);
    }

    window.draw(line1, 2, sf::Lines);
    window.draw(line2, 2, sf::Lines);
    window.draw(input1);
    window.draw(input2);
    window.draw(output);
}

void OrGate::handleClickEvent(sf::RenderWindow &window, sf::Event event)
{
    std::cout << "Handling click event for or gate\n";
    if (input1.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
        _input1 = !_input1;
    }
    if (input2.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
        _input2 = !_input2;
    }
}
