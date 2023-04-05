#include <SFML/Graphics.hpp>

int main()
{
    // Ventana main utilizando sfml
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pantalla Principal");

    // crear los 3 botones de dificultad
    sf::RectangleShape easyButton(sf::Vector2f(200, 50));
    easyButton.setPosition(300, 200);
    easyButton.setFillColor(sf::Color::Green);

    sf::RectangleShape mediumButton(sf::Vector2f(200, 50));
    mediumButton.setPosition(300, 300);
    mediumButton.setFillColor(sf::Color::Yellow);

    sf::RectangleShape hardButton(sf::Vector2f(200, 50));
    hardButton.setPosition(300, 400);
    hardButton.setFillColor(sf::Color::Red);

    // Ciclo principal
    while (window.isOpen())
    {
        // manejar eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                // verificar cuando un boton se presiona
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                window.close();

                if (easyButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    // boton facil se presiona
                    // TODO: codigo para definir dificultad en facil
                    sf::RenderWindow gameWindow(sf::VideoMode(800, 600), "Modo Fácil");


                    {
                        // textura de la nave
                        sf::Texture spaceshipTexture;
                        if (!spaceshipTexture.loadFromFile("navee.png")
                                )
                        {
                            // por si hay error al cargar la imagen
                            return -1;
                        }

                        // Creaar el sprite y ubicarlo
                        sf::Sprite spaceship(spaceshipTexture);
                        spaceship.setPosition(100, 100);

                        // ciclo principal para la pantalla en facil
                        while (gameWindow.isOpen())
                        {
                            // manejar eventos
                            sf::Event event;
                            while (gameWindow.pollEvent(event))
                            {
                                if (event.type == sf::Event::Closed)
                                {
                                    gameWindow.close();
                                }
                                else if(event.type == sf::Event::KeyPressed)
                                {
                                    // manejar movimiento de la nave
                                    if (event.key.code == sf::Keyboard::W)
                                    {
                                        spaceship.move(0, -10); // mover arriba
                                    }
                                    else if (event.key.code == sf::Keyboard::S)
                                    {
                                        spaceship.move(0, 10); // mover abajo
                                    }
                                }
                            }

                            // limpiar ventana
                            gameWindow.clear();

                            // dibujar la nave
                            gameWindow.draw(spaceship);

                            // mostrar la ventana de juego
                            gameWindow.display();
                        }
                    }
                }

                else if (mediumButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    // cuando el boton de difiucltad medio se presiona
                    // TODO: codigo para definir dificultad en medio
                    sf::RenderWindow gameWindow(sf::VideoMode(800, 600), "Modo Medio");
                    window.close();

                    // TODO: aqui va el codigo para el nivel medio
                    while (gameWindow.isOpen())
                    {
                        sf::Event gameEvent;
                        while (gameWindow.pollEvent(gameEvent))
                        {
                            if (gameEvent.type == sf::Event::Closed)
                            {
                                gameWindow.close();
                            }
                        }

                        gameWindow.clear();
                        // TODO: codigo para dibujar la ventana
                        gameWindow.display();
                    }
                }
                else if (hardButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    // oboton dificil se presiona
                    // TODO: codigo para definir la dificultad
                    sf::RenderWindow gameWindow(sf::VideoMode(800, 600), "Modo Difícil");
                    window.close();
                    // TODO: codigo para el juego en dificil
                    while (gameWindow.isOpen())
                    {
                        sf::Event gameEvent;
                        while (gameWindow.pollEvent(gameEvent))
                        {
                            if (gameEvent.type == sf::Event::Closed)
                            {
                                gameWindow.close();
                            }
                        }

                        gameWindow.clear();
                        // TODO: codigo para dibujar el juego
                        gameWindow.display();
                    }
                }
            }
        }

        // limpiar ventana
        window.clear();

        // dibujar botones
        window.draw(easyButton);
        window.draw(mediumButton);
        window.draw(hardButton);

        // Mostrar la ventana principal
        window.display();
    }

    return 0;
}