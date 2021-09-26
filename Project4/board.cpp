/*
    This code file contains member functions of board.h
*/

#include "board.h"

Board::Board(sf::Color col1, sf::Color col2) {
    load(col1, col2);
    sf::Color color= sf::Color(233,232,197);
    sf::Color color2= sf::Color(193,189,46);
    float xCentral = 32;
    for(int i = 0; i < 4; i ++)
    {
        promotingBoxes[i].setOutlineThickness(-2.f);
        promotingBoxes[i].setOutlineColor(sf::Color::Black);
    }
    promotingBoxes[0].setPosition(xCentral +542.f, 190.f);
    promotingBoxes[0].setSize(sf::Vector2f (64.f,  64.f));
    promotingBoxes[0].setFillColor(color);
    promotingBoxes[1].setPosition(xCentral +542.f, 254.f);
    promotingBoxes[1].setSize(sf::Vector2f (64.f,  64.f));
    promotingBoxes[1].setFillColor(color2);
    promotingBoxes[2].setPosition(xCentral +608.f, 190.f);
    promotingBoxes[2].setSize(sf::Vector2f (64.f,  64.f));
    promotingBoxes[2].setFillColor(color2);
    promotingBoxes[3].setPosition(xCentral +608.f, 254.f);
    promotingBoxes[3].setSize(sf::Vector2f (64.f,  64.f));
    promotingBoxes[3].setFillColor(color);
}

// Member function that sets Board stuff, can choose square colors in parameters
void Board::load(sf::Color col1, sf::Color col2) {
    for (int i = 0; i < 8;i++) {

        bool tmpColor = ((i % 2) == 0) ? true : false;

        for (int j = 0; j < 8;j++) {

            m_boardSquares[j + (i * 8)].setPosition(sf::Vector2f(j * 64.f, i * 64.f));
            m_boardSquares[j + (i * 8)].setSize(sf::Vector2f(64.f, 64.f));
            m_boardSquares[j + (i * 8)].setFillColor(tmpColor ? col1 : col2);

            tmpColor = !tmpColor;
        }
    }
}

// Draw class on SFML Window
void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (int i = 0;i < 64;i++) {
        target.draw(m_boardSquares[i]);
    }

    if(inPromote)
        for(int i = 0; i< 4 ;i ++)
        {

            target.draw(promotingBoxes[i]);
        }
}
// interface in case of promoting move
/*void Board::promotingInterface() {


    m_boardSquares[3 + 3 * 8].setPosition(3 * 64.f, 3 * 64.f);
        m_boardSquares[3 + 3 * 8].setSize(sf::Vector2f (64.f,  64.f));
        m_boardSquares[3 + 3 * 8].setFillColor(color);

        m_boardSquares[4 + 3 * 8].setPosition(4 * 64.f, 3 * 64.f);
        m_boardSquares[4 + 3 * 8].setSize(sf::Vector2f (64.f,  64.f));
        m_boardSquares[4 + 3 * 8].setFillColor(color);

        m_boardSquares[3 + 4 * 8].setPosition(3 * 64.f, 4 * 64.f);
        m_boardSquares[3 + 4 * 8].setSize(sf::Vector2f (64.f,  64.f));
        m_boardSquares[3 + 4 * 8].setFillColor(color);

        m_boardSquares[4 + 4 * 8].setPosition(4 * 64.f, 4 * 64.f);
        m_boardSquares[4 + 4 * 8].setSize(sf::Vector2f (64.f,  64.f));
        m_boardSquares[4 + 4 * 8].setFillColor(color);

}*/