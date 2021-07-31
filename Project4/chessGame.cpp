/*
    This code file contains member functions of chessGame.h
*/

#include "chessGame.h"

const char* cmd[] = { R"(C:\Users\paul\source\repos\Chess AI\x64\Debug\Chess AI.exe)", nullptr };
Utlils::Subprocess proc(cmd);
sf::Sprite setTexture(char c, int);
ChessGame::ChessGame()
    
{
    // The code is taking account of these indexes.
    // Changing them may brake normal chess rules.
    // Comment out pieces if you want to remove some pieces at beggining.

    font.loadFromFile("Textures/arial.ttf");


    infoRestart.setFillColor(sf::Color::White);
    infoRestart.setOutlineThickness(-5.f);
    infoRestart.setOutlineColor(sf::Color::Black);
    infoRestart.setPosition(sf::Vector2f(512.f, 0.f));
    infoRestart.setSize(sf::Vector2f(256.f, 50.f));

    textRestart.setFont(font);
    textRestart.setString("RESTART");
    textRestart.setCharacterSize(24);
    textRestart.setStyle(sf::Text::Bold);
    textRestart.setFillColor(sf::Color::Black);
    textRestart.setPosition(infoRestart.getPosition().x + 75.f, infoRestart.getPosition().y + 10.f);

    textTurn.setFont(font);
    textTurn.setCharacterSize(24);
    textTurn.setStyle(sf::Text::Bold);
    textTurn.setFillColor(sf::Color::White);
    textTurn.setPosition(530.f, 70.f);

    textSituation.setFont(font);
    textSituation.setCharacterSize(24);
    textSituation.setStyle(sf::Text::Bold);
    textSituation.setFillColor(sf::Color::White);
    textSituation.setPosition(530.f, 110.f);

    textLastMove.setFont(font);
    textLastMove.setCharacterSize(24);
    textLastMove.setStyle(sf::Text::Bold);
    textLastMove.setFillColor(sf::Color::White);
    textLastMove.setPosition(530.f, 200.f);


    //restart();

}

/*

void ChessGame::restart() {

    selected = false;
    playerTurn = true;
    playerTurnCheck = false;
    mate = false;
    turn = 1;

    blackPieces[0].setPiece('R', false, 7);
    blackPieces[1].setPiece('N', false, 6);
    blackPieces[2].setPiece('B', false, 5);
    blackPieces[3].setPiece('K', false, 4);
    blackPieces[4].setPiece('Q', false, 3);
    blackPieces[5].setPiece('B', false, 2);
    blackPieces[6].setPiece('N', false, 1);
    blackPieces[7].setPiece('R', false, 0);

    whitePieces[0].setPiece('R', true, 56);
    whitePieces[1].setPiece('N', true, 57);
    whitePieces[2].setPiece('B', true, 58);
    whitePieces[3].setPiece('Q', true, 59);
    whitePieces[4].setPiece('K', true, 60);
    whitePieces[5].setPiece('B', true, 61);
    whitePieces[6].setPiece('N', true, 62);
    whitePieces[7].setPiece('R', true, 63);


    for (int i = 8;i < 16;i++) {
        whitePieces[i].setPiece('P', true, 48 + (i - 8));
        blackPieces[i].setPiece('P', false, 15 - (i - 8));
    }

    //calcPossibleMoves();

    textLastMove.setString(" ");


}*/
/*
void ChessGame::updateInfo() {
    textTurn.setString("Turn: " + std::to_string(turn));
    textLastMove.setString(lastMove);

    if (!mate) {
        if (playerTurn)
            textSituation.setString("White's Turn");
        else
            textSituation.setString("Blacks's Turn");

        if (playerTurnCheck)
            textSituation.setString(textSituation.getString() + "\nCheck");
    }
    else {
        if (playerTurnCheck) {
            if (playerTurn)
                textSituation.setString("CHECKMATE\nBlack Wins");
            else
                textSituation.setString("CHECKMATE\nWhite Wins");
        }
        else {
            textSituation.setString("STALEMATE\nIts a DRAW");
        }

    }
}


*/

void ChessGame::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.clear(sf::Color::Black);

    target.draw(boardu);
    target.draw(infoRestart);
    target.draw(textRestart);
    target.draw(textTurn);
    target.draw(textSituation);
    target.draw(textLastMove);

   // if ((selectedPiece != NULL) && (selected)) {
     //   for (int i = 0; i < possibleMovesSquares.size();i++) {
       //     target.draw(possibleMovesSquares.at(i));
       // }
    //}

    for (auto i : pieces)
    {
        target.draw(setTexture(i.second, i.first));
    }
}
sf::Sprite setTexture(char c, int pos) {
    sf::Sprite m_sprite = sf::Sprite();
    switch (c)
    {
    case 'K':
        m_sprite.setTexture(PieceTextures::whiteKing);
        break;
    case 'k':
        m_sprite.setTexture(PieceTextures::blackKing);
        break;

    case 'Q':
        m_sprite.setTexture(PieceTextures::whiteQueen);
        break;
    case 'q':
        m_sprite.setTexture( PieceTextures::blackQueen);
        break;

    case 'R':
        m_sprite.setTexture(PieceTextures::whiteRook);
        break;
    case 'r':
        m_sprite.setTexture(PieceTextures::blackRook);
        break;

    case 'B':
        m_sprite.setTexture(PieceTextures::whiteBishop);
        break;
    case 'b':
        m_sprite.setTexture(PieceTextures::blackBishop);
        break;

    case 'N':
        m_sprite.setTexture(PieceTextures::whiteKnight);
        break;
    case 'n':
        m_sprite.setTexture(PieceTextures::blackKnight);
        break;

    case 'P':
        m_sprite.setTexture(PieceTextures::whitePawn);
        break;
    case 'p':
        m_sprite.setTexture(PieceTextures::blackPawn);
        break;

    default:
        std::cerr << "Error piece type does not exist.\n";
        break;
    }
    m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize().x / 2, m_sprite.getTexture()->getSize().y / 2));
    m_sprite.setScale(sf::Vector2f(0.375f, 0.375f));
    m_sprite.setPosition(sf::Vector2f((pos % 8) * 64.f + 32.f, (pos / 8) * 64.f + 32.f));
    return m_sprite;
}
void ChessGame::loadPosition()
{
    // loadpositionul e gata cred
    std::ifstream fin("Text.txt");
    std::string position, moveList;
    fin >> position;


    int line = 0, col = 0;
    for (char c : position)
    {
        if (c <= '9' and c >= '0')
        {
            col += c - '0';
        }
        else
            if (c == '/')
                line++, col = 0;
            else
            {
                board[line][col] = c;
                
                pieces.emplace_back((line * 8 + col) , c );
                col++;
            }
    }
  /*  for (int i = 0; i < 8; i++, std::cout << '\n')
        for (int j = 0;j < 8;j++)
            if (board[i][j] != ' ') std::cout << board[i][j] << " ";
            else
                std::cout << 0 << " ";
  */
    for (auto i : pieces)
    {
        std::cout << i.first << " ";
    }
}




void ChessGame::createMovesSquares(int pos) {

    //if (selectedPiece == NULL)
      //  return;

    possibleMovesSquares.clear();
    char line = pos / 8+'1';
    char col = pos % 8 +'a';
    printf("getMovesPiece %c%c \n", line, col);
    proc.write("getMovesPiece %c%c \n", line,col);
    char x[2];
    proc.read(x, '\n');
        printf(x);
    /*for (int i = 0; i < selectedPiece->getPossibleMoves().size();i++) {
        sf::RectangleShape tmp;
        tmp.setPosition(sf::Vector2f((selectedPiece->getPossibleMoves().at(i) % 8) * 64.f, (selectedPiece->getPossibleMoves().at(i) / 8) * 64.f));
        tmp.setSize(sf::Vector2f(64.f, 64.f));
        tmp.setFillColor(sf::Color(0x66b4cc50));
        possibleMovesSquares.push_back(tmp);
    }

    sf::RectangleShape tmp;
    tmp.setPosition(sf::Vector2f((selectedPiece->getPosition() % 8) * 64.f, (selectedPiece->getPosition() / 8) * 64.f));
    tmp.setSize(sf::Vector2f(64.f, 64.f));
    tmp.setFillColor(sf::Color(0x00000000));
    tmp.setOutlineColor(sf::Color::Red);
    tmp.setOutlineThickness(-3.f);
    possibleMovesSquares.push_back(tmp);
    */
    return;
    }



bool ChessGame::selectPiece(int pos) {
    int line = pos / 8;
    int col = pos % 8;
    bool isPiece = false;
    if (playerTurn)
    {
        if (board[line][col] >= 'A' and board[line][col] <= 'Z')
            isPiece = true;
    }
    if (!playerTurn)
    {
        if (board[line][col] >= 'a' and board[line][col] <= 'z')
            isPiece = true;
    }
    
    
        if (!isPiece) {
        possibleMovesSquares.clear();
        return selected;
    }


        createMovesSquares(pos);

        return isPiece;
}


/*
void ChessGame::moveSelected(int pos) {
    bool validMove{ false };

    if ((selectedPiece == NULL) || !selected) //Probably doesnt need both
        return;

    // Check pos with the Piece's possibleMoves
    for (int i = 0;i < selectedPiece->getPossibleMoves().size();i++) {
        if (pos == selectedPiece->getPossibleMoves().at(i)) {
            validMove = true;
            break;
        }
    }

    if (validMove) {

        // If Castling Move
        if ((selectedPiece->getType() == 'K') && (!selectedPiece->getMoved())) {
            if (selectedPiece->getPlayer()) { // If white
                // whitePieces[0] Bot Left Rook, whitePieces[7] Bot Right Rook
                if (pos == 62)
                    whitePieces[7].setPosition(61);
                else if (pos == 58)
                    whitePieces[0].setPosition(59);
            }
            else { // If Black
                // blackPieces[7] Top Left Rook, blackPieces[0] Top Right Rook
                if (pos == 6)
                    blackPieces[0].setPosition(5);
                else if (pos == 2)
                    blackPieces[7].setPosition(3);
            }
        }




        // If Pawn double move (set en passant)
        // White pawn -16, Black pawn +16
        if ((selectedPiece->getType() == 'P')) {
            if (!selectedPiece->getMoved()) {
                if (pos == (selectedPiece->getPosition() - 16)) {
                    selectedPiece->setEnPassant(selectedPiece->getPosition() - 8);
                }
                else if (pos == (selectedPiece->getPosition() + 16)) {
                    selectedPiece->setEnPassant(selectedPiece->getPosition() + 8);
                }
            }
            else {
                for (int i = 0; i < 16; i++) {
                    if (playerTurn) {
                        if (pos == blackPieces[i].getEnPassant())
                            blackPieces[i].setPosition(pos);
                    }
                    else {
                        if (pos == whitePieces[i].getEnPassant())
                            whitePieces[i].setPosition(pos);
                    }
                }
            }
        }
        if (selectedPiece->getMoved()) {
            for (int i = 0; i < 16; i++) {
                whitePieces[i].setEnPassant(-1);
                blackPieces[i].setEnPassant(-1);
            }
        }


        selectedPiece->setPosition(pos);




        lastMove = "Last Turn:\n" + selectedPiece->toString();
        for (int i = 0; i < 16; i++) {
            if (selectedPiece->getPlayer()) { // If White
                if (blackPieces[i].getPosition() == pos) {
                    blackPieces[i].setPosition(-1);
                    break;
                }
            }
            else { // If Black
                if (whitePieces[i].getPosition() == pos) {
                    whitePieces[i].setPosition(-1);
                    break;
                }
            }
        }



        if (playerTurnCheck) {
            playerTurnCheck = false;
        }

        playerTurn = !playerTurn; // Here player turn changes
        calcPossibleMoves();
    }

    selectedPiece = NULL;
    selected = false;

}

*/
