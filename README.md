# Intro-au-C-Deuxieme-Partie
Cours sur le cpp

Introduction

Bienvenue dans ce cours de C++ ! Le but de ce cours est d'apprendre à créer des composants d'ordinateur de base en utilisant la programmation orientée objet. Vous apprendrez à créer une classe de base abstraite, E-Component, à partir de laquelle dériveront divers composants électroniques tels que des portes logiques.
Objectifs du cours

Comprendre la programmation orientée objet en C++ : Création de classes et héritage.
Développer des composants électroniques : Création de différents types de portes logiques et autres composants.
Implémenter des interfaces graphiques avec SFML : Ajouter une représentation visuelle des composants avec des fonctionnalités de simulation et d'affichage.

Structure du projet
Classe de base E-Component

Nous allons commencer par créer une classe virtuelle appelée E-Component. Cette classe servira d'interface pour tous les composants que nous développerons. Elle inclura les éléments suivants :

Bouton Simulate : Pour simuler le fonctionnement du composant.
Bouton Display Window : Pour afficher une représentation graphique du composant à l'aide de SFML.

```cpp
class EComponent {
public:
    virtual void simulate() = 0;
    virtual void displayWindow() = 0;
    virtual ~EComponent() = default;
};
```
Composants dérivés

À partir de E-Component, nous créerons plusieurs composants dérivés. Voici une liste des composants que nous allons implémenter :

    AND Gate (Porte ET)
    OR Gate (Porte OU)
    NOT Gate (Porte NON)
    NAND Gate (Porte NAND)
    NOR Gate (Porte NOR)
    XOR Gate (Porte OU Exclusif)
    XNOR Gate (Porte NON-OU Exclusif)

Chaque composant implémentera les méthodes simulate et displayWindow pour réaliser ses fonctionnalités spécifiques.
Exemple de composant dérivé

Voici un exemple de ce à quoi pourrait ressembler l'implémentation d'une porte AND :

```cpp
class ANDGate : public EComponent {
public:
    void simulate() override {
        // Code pour simuler le comportement de la porte AND
    }

    void displayWindow() override {
        // Code pour afficher la porte AND à l'aide de SFML
    }
};
```

Représentation graphique avec SFML

Chaque composant aura une représentation graphique que nous allons afficher en utilisant SFML. SFML (Simple and Fast Multimedia Library) est une bibliothèque de multimédia simple et rapide à utiliser qui nous permettra de créer des interfaces graphiques pour nos composants.

Gestion des Composants et Affichage des Circuits

En plus de créer des composants individuels, nous allons développer une class pour gérer et organiser ces multiples éléments. Cette classe sera responsable de l'affichage de l'ensemble du circuit électronique et de l'orchestration des interactions entre les composants. Cependant, il est crucial que chaque composant reste autonome en ce qui concerne la gestion des clics et des interactions de l'utilisateur.
Vous pouvez meme en bonus ajouter un charger de .so qui permettra de charger des composants dynamiquement.
Classe de Gestion des Composants

Nous allons introduire une classe appelée CircuitManager (ou un nom similaire) qui aura les responsabilités suivantes :

    Gestion des composants : Maintenir une liste de tous les composants présents dans le circuit.
    Affichage global : Dessiner l'ensemble du circuit sur une fenêtre SFML.
    Coordination des interactions : Relayer les interactions utilisateur aux composants appropriés.

```cpp
class CircuitManager {
private:
    std::vector<std::unique_ptr<EComponent>> components;
    size_t index;

public:
    void addComponent(std::unique_ptr<EComponent> component) {
        components.push_back(std::move(component));
    }

    void displayCircuit() {
        component[index]->displayWindow();
    }

    void handleUserInteraction(const sf::Event& event) {
        component[index]->handleClick(event);
    }
};
```
Affichage et Interaction

La classe CircuitManager sera chargée d'afficher tous les composants sur une fenêtre SFML. Cependant, c'est chaque composant qui doit gérer ses propres interactions. Lorsque l'utilisateur clique sur un composant, celui-ci doit pouvoir changer l'état de ses entrées (de 0 à 1 et de 1 à 0).
Gestion des Clics par les Composants

Chaque composant doit implémenter une méthode handleClick pour gérer les clics de l'utilisateur. Cette méthode permettra au composant de détecter les clics sur ses éléments graphiques et de modifier l'état de ses entrées en conséquence.

cpp

class EComponent {
public:
    virtual void simulate() = 0;
    virtual void displayWindow() = 0;
    virtual void handleClick(const sf::Event& event) = 0;
    virtual ~EComponent() = default;
};

class ANDGate : public EComponent {
private:
    bool input1;
    bool input2;

public:
    ANDGate() : input1(false), input2(false) {}

    void simulate() override {
        // Simulation de la porte AND
    }

    void displayWindow() override {
        // Affichage graphique avec SFML
    }

    void handleClick(const sf::Event& event) override {
        // Gérer les clics et modifier input1 et input2
        if (/* condition pour détecter le clic sur input1 */) {
            input1 = !input1;
        } else if (/* condition pour détecter le clic sur input2 */) {
            input2 = !input2;
        }
    }
};

Conclusion

En résumant, nous allons :

    Créer une classe CircuitManager pour gérer et afficher l'ensemble des composants du circuit.
    Déléguer la gestion des clics aux composants individuels afin qu'ils puissent modifier leurs états d'entrée en fonction des interactions de l'utilisateur.

Cette structure permettra de maintenir une bonne séparation des responsabilités et de rendre notre système modulaire et extensible. Chaque composant pourra ainsi gérer ses propres états et interactions tout en s'intégrant harmonieusement dans l'ensemble du circuit géré par CircuitManager.
Instructions pour démarrer

Clonez le dépôt :

```sh
    git clone git@github.com:perso-eliot-GOURDOUX/Intro-au-C-Deuxieme-Partie.git
```

Installez SFML :
Suivez les instructions sur le site officiel de SFML pour installer la bibliothèque sur votre système.

Compilez le projet :
Utilisez un Makefile et assurez-vous que SFML est correctement configuré.

Exécutez le projet :
Lancez le projet pour voir les composants en action et utilisez les boutons Simulate et Display Window pour interagir avec eux.
