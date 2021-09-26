/*
    This header file contains th ChessGame class.
    contains the whole game.
*/

#ifndef _CHESSGAME_H
#define _CHESSGAME_H

#include "subprocess/Subprocess.h"

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <fstream>
#include <iostream>
#include "pieceTexture.h"
#include "board.h"
//#include "piece.h"
#include <unordered_map>
class ChessGame : public sf::Drawable {
private:
    int promotedPiece = -1;
    int piecePosition = -1;
  //  std::array<Piece, 16> whitePieces;
   // std::array<Piece, 16> blackPieces;
    std::unordered_map<int, char> pieces;
    std::vector<sf::RectangleShape> possibleMovesSquares;
    std::string lastMove;

    char board[8][8];
    sf::RectangleShape infoRestart;
    //std::vector<std::pair<int, char>> pieces;
    sf::Font font;
    sf::Text textRestart;
    sf::Text textTurn;
    sf::Text textSituation;
    sf::Text textLastMove;
    int enpasant = -1;


    std::vector<int> moves;
    int selected = -1;

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

    void updateInfo();
    
   virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    std::vector<int> remeberPromotePosition;
    bool isPromote = false;
    int chosenPromote = -1;
    Board boardu;
    ChessGame();
    bool playerTurn= true; // true = White turn, false = Black Turn
    int getSelected() { return selected; }
    void promoting_Interface();
    bool getMate() { return mate; }
    void loadPosition();
   bool selectPiece(int pos);
    void selectPiecePromote(int , int);
    void moveSelected(int pos);

   // void restart();



};


#endif