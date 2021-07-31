
/*
    This code file (main.cpp) contains the main function that runs the game
    all libraries that must be used have to be included here.
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "chessGame.h"
//#include "subprocess/Subprocess.h";

//const char* cmd[] = { R"(C:\Users\paul\source\repos\Chess AI\x64\Debug\Chess AI.exe)", nullptr };
//Utlils::Subprocess proc(cmd);
int main() {
    ChessGame chess;
    chess.loadPosition();

    sf::RenderWindow window(sf::VideoMode(768, 512), "Chess", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();

                       if (event.type == sf::Event::MouseButtonPressed) {

                           if (event.mouseButton.button == sf::Mouse::Left) {
                               if ((0 <= event.mouseButton.x) && (event.mouseButton.x <= 512) && (0 <= event.mouseButton.y) && (event.mouseButton.y <= 512)) {
                                   unsigned int buttonPos{ (event.mouseButton.x / 64) + ((event.mouseButton.y / 64) * (8 * (512 / window.getSize().y))) };

                                   //if (!chess.getSelected())
                                  // {
                                   std::cout << chess.selectPiece(buttonPos) << '\n';
                                       
                                  // }
                                    //   chess.moveSelected(buttonPos);
                               }
                               else if ((517 <= event.mouseButton.x) && (event.mouseButton.x <= 763) && (5 <= event.mouseButton.y) && (event.mouseButton.y <= 45)) {
                                   //chess.restart();
                               }
                           }
                       }
                   }
                  
            window.draw(chess);
            window.display();
        }
    }
