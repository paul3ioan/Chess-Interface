
/*
    This code file (main.cpp) contains the main function that runs the game
    all libraries that must be used have to be included here.
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "chessGame.h"
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
                           unsigned int buttonPos{ (event.mouseButton.x / 64) + ((event.mouseButton.y / 64) * (8 * (512 / window.getSize().y))) };
                           if(event.mouseButton.button == sf::Mouse::Left)
                           if(chess.isPromote and event.mouseButton.x >=574 and event.mouseButton.x <= 704 and
                              event.mouseButton.y >=190 and event.mouseButton.y <=318)
                           {

                               chess.selectPiecePromote(event.mouseButton.x, event.mouseButton.y);
                               chess.moveSelected(chess.chosenPromote);
                           }
                           if (event.mouseButton.button == sf::Mouse::Left) {
                               if (!chess.isPromote and (0 <= event.mouseButton.x) && (event.mouseButton.x <= 512) && (0 <= event.mouseButton.y) && (event.mouseButton.y <= 512)) {
                                   chess.selectPiece(buttonPos);
                                    if(chess.getSelected() > 0)
                                       chess.moveSelected(buttonPos);
                               }
                              /* else if ((517 <= event.mouseButton.x) && (event.mouseButton.x <= 763) && (5 <= event.mouseButton.y) && (event.mouseButton.y <= 45)) {
                                   //chess.restart();
                               }*/
                           }
                       }
                   }

        window.draw(chess);
        window.display();
        }

    }
