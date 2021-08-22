/*
    This header file contains th ChessGame class.
    contains the whole game.
*/

#ifndef _CHESSGAME_H
#define _CHESSGAME_H

#include "subprocess/Subprocess.h";

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <fstream>
#include <iostream>
#include "pieceTexture.h"
#include "board.h"
//#include "piece.h"

class ChessGame : public sf::Drawable {
private:
    Board boardu;
  //  std::array<Piece, 16> whitePieces;
   // std::array<Piece, 16> blackPieces;
   
    std::vector<sf::RectangleShape> possibleMovesSquares;
    std::string lastMove;
    char board[8][8];
    sf::RectangleShape infoRestart;
    std::vector<std::pair<int, char>> pieces;
    sf::Font font;
    sf::Text textRestart;
    sf::Text textTurn;
    sf::Text textSituation;
    sf::Text textLastMove;


    bool selected;
    bool playerTurn= true; // true = White turn, false = Black Turn
    bool playerTurnCheck;
    bool mate;
    int turn;
    
    void createMovesSquares(int);
/*
    void calcPossibleMoves();
    void calcKingMoves(Piece* tmpPiece);
    void calcQueenMoves(Piece* tmpPiece);
    void calcRookMoves(Piece* tmpPiece);
    void calcBishopMoves(Piece* tmpPiece);
    void calcKnightMoves(Piece* tmpPiece);
    void calcPawnMoves(Piece* tmpPiece);
    void calcCastling(Piece* tmpPiece);

    void eraseMoves(Piece* tmpPiece);

    void checkMate();*/

    //void updateInfo();
    
   virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    ChessGame();

    bool getSelected() { return selected; }

    bool getMate() { return mate; }
    void loadPosition();
   bool selectPiece(int pos);

//    void moveSelected(int pos);

   // void restart();



};


#endif