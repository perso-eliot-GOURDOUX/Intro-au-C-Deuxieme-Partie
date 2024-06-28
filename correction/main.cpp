/*
** EPITECH PROJECT, 2024
** testtest
** File description:
** tes
*/

#include "Gates.hpp"
#include "CircuitManager.hpp"

template <typename T>
void CircuitManager::addComponent()
{
    _components.push_back(std::make_shared<T>());
}

CircuitManager::CircuitManager()
{
    button_left.setSize(sf::Vector2f(60, 100));
    button_left.setFillColor(sf::Color::Green);
    button_left.setPosition(30, 250);

    arrow_left.setPointCount(6);
    arrow_left.setPoint(0, sf::Vector2f(50, 50));
    arrow_left.setPoint(1, sf::Vector2f(25, 75));
    arrow_left.setPoint(2, sf::Vector2f(50, 100));
    arrow_left.setPoint(3, sf::Vector2f(45, 100));
    arrow_left.setPoint(4, sf::Vector2f(20, 75));
    arrow_left.setPoint(5, sf::Vector2f(45, 50));

    arrow_left.setFillColor(sf::Color::Black);
    arrow_left.setPosition(25, 225);

    window.draw(arrow_left);

    button_right.setSize(sf::Vector2f(60, 100));
    button_right.setFillColor(sf::Color::Green);
    button_right.setPosition(710, 250);
    window.draw(button_right);

    arrow_right.setPointCount(6);

    arrow_right.setPoint(0, sf::Vector2f(25, 50));
    arrow_right.setPoint(1, sf::Vector2f(50, 75));
    arrow_right.setPoint(2, sf::Vector2f(25, 100));
    arrow_right.setPoint(3, sf::Vector2f(30, 100));
    arrow_right.setPoint(4, sf::Vector2f(55, 75));
    arrow_right.setPoint(5, sf::Vector2f(30, 50));

    arrow_right.setFillColor(sf::Color::Black);

    arrow_right.setPosition(700, 225);
    window.draw(arrow_right);
}

CircuitManager::~CircuitManager()
{
}

std::vector<std::shared_ptr<EComponent>> CircuitManager::getComponents() const
{
    return _components;
}

void CircuitManager::displayCircuit()
{
    std::vector<std::shared_ptr<EComponent>> components = getComponents();
    if (!components.empty()) {
        components.at(index)->displayComponent(window);
    } else
        std::cout << "No components\n";
}

void CircuitManager::displayButton()
{
    window.draw(button_left);
    window.draw(button_right);
    window.draw(arrow_left);
    window.draw(arrow_right);
}

void CircuitManager::changeButtonColor()
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    if (button_left.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
        button_left.setFillColor(sf::Color::Red);
    } else if (button_right.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
        button_right.setFillColor(sf::Color::Red);
    } else {
        button_left.setFillColor(sf::Color(0, 128, 0));
        button_right.setFillColor(sf::Color(0, 128, 0));
    }
}

bool CircuitManager::changeIndex(sf::Event event)
{
    if (button_left.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
        index--;
        index = index % getComponents().size();
        return false;
    } else if (button_right.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
        index++;
        index = index % getComponents().size();
        return false;
    }
    return true;
}

void CircuitManager::drawName()
{
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return;
    }

    sf::Text text;
    text.setFont(font);
    text.setString(getComponents().at(index)->getName());
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);

    window.draw(text);
}

int main()
{
    std::cout << "START CIRCUITMANAGER !\n";
    CircuitManager circuit;
    circuit.window.create(sf::VideoMode(800, 600), "Circuit Manager");
    circuit.window.setFramerateLimit(30);
    circuit.addComponent<OrGate>();
    circuit.addComponent<AndGate>();


    while (circuit.window.isOpen())
    {
        sf::Event event;
        while (circuit.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                circuit.window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                circuit.window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                circuit.changeIndex(event);
                circuit.getComponents().at(circuit.index)->handleClickEvent(circuit.window, event);
            }
        }

        circuit.window.clear(sf::Color(32, 32, 32));
        circuit.displayCircuit();
        circuit.changeButtonColor();
        circuit.displayButton();
        circuit.drawName();

        sf::CircleShape greenCircle(10);
        greenCircle.setFillColor(sf::Color::Green);
        greenCircle.setPosition(10, 40);

        sf::CircleShape redCircle(10);
        redCircle.setFillColor(sf::Color::Red);
        redCircle.setPosition(10, 70);

        circuit.window.draw(greenCircle);
        circuit.window.draw(redCircle);

        sf::Font font;
        if (!font.loadFromFile("arial.ttf")) {
            std::cerr << "Failed to load font" << std::endl;
            return 0;
        }

        sf::Text greenText;
        greenText.setFont(font);
        greenText.setString("= 1");
        greenText.setCharacterSize(18);
        greenText.setFillColor(sf::Color::White);
        greenText.setPosition(40, 40);
        circuit.window.draw(greenText);

        sf::Text redText;
        redText.setFont(font);
        redText.setString("= 0");
        redText.setCharacterSize(18);
        redText.setFillColor(sf::Color::White);
        redText.setPosition(40, 70);
        circuit.window.draw(redText);
        circuit.window.display();
    }
    return 0;
}
