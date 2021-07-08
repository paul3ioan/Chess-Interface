#include <SFML/Graphics.hpp>
#include <time.h>
//#include "Connector.hpp"
using namespace sf;
#include <fstream>
int size = 56;
Vector2f offset(28, 28);

Sprite f[32]; //figures
void loadPosition();

int board[8][8] =
{
     0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0,
};
std::string toChessNote(Vector2f p)
{
    std::string s = "";
    s += char(p.x / size + 97);
    s += char(7 - p.y / size + 49);
    return s;
}

Vector2f toCoord(char a, char b)
{
    // de ce?
    int x = int(a) - 97;
    int y = 7 - int(b) + 49;
    return Vector2f(x * size, y * size);
}

void move(std::string str)
{
    Vector2f oldPos = toCoord(str[0], str[1]);
    Vector2f newPos = toCoord(str[2], str[3]);

    for (int i = 0;i < 32;i++)
        if (f[i].getPosition() == newPos) f[i].setPosition(-100, -100);

    for (int i = 0;i < 32;i++)
        if (f[i].getPosition() == oldPos) f[i].setPosition(newPos);

    //castling       //if the king didn't move
    if (str == "e1g1") move("h1f1");
    if (str == "e8g8") move("h8f8");
    if (str == "e1c1") move("a1d1");
    if (str == "e8c8") move("a8d8");
}

int main()
{
    //504
    RenderWindow window(VideoMode(1000, 1000), "The Chess! (press SPACE)");
    //    ConnectToEngine("stockfish.exe");    

    Texture t1, t2;
    t1.loadFromFile("images/figure.png");
    t2.loadFromFile("images/94205495-seamless-modern-black-and-white-chess-board-background-design-vector-illustration-eps10.jpg");
    //cautat alte imagini
    for (int i = 0;i < 32;i++) f[i].setTexture(t1);
    Sprite sBoard(t2);

    loadPosition();

    bool isMove = false;
    float dx = 0, dy = 0;
    Vector2f oldPos, newPos;
    std::string str;
    int n = 0;
    // cum functioneaza toata partea asta
    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window) - Vector2i(offset);

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();

            ////move back//////
            //if (e.type == Event::KeyPressed)
              //  if (e.key.code == Keyboard::BackSpace)
                //{
                  //  if (position.length() > 6) position.erase(position.length() - 6, 5); loadPosition();
                //}

            /////drag and drop///////
            if (e.type == Event::MouseButtonPressed)
                if (e.key.code == Mouse::Left)
                    for (int i = 0;i < 32;i++)
                        if (f[i].getGlobalBounds().contains(pos.x, pos.y))
                        {
                            isMove = true; n = i;
                            dx = pos.x - f[i].getPosition().x;
                            dy = pos.y - f[i].getPosition().y;
                            oldPos = f[i].getPosition();
                        }

            if (e.type == Event::MouseButtonReleased)
                if (e.key.code == Mouse::Left)
                {
                    isMove = false;
                    Vector2f p = f[n].getPosition() + Vector2f(size / 2, size / 2);
                    newPos = Vector2f(size * int(p.x / size), size * int(p.y / size));
                    str = toChessNote(oldPos) + toChessNote(newPos);
                    move(str);
                    // if (oldPos != newPos) position += str + " ";
                    f[n].setPosition(newPos);
                }
        }

        //comp move
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            // str =  getNextMove(position);

            oldPos = toCoord(str[0], str[1]);
            newPos = toCoord(str[2], str[3]);

            for (int i = 0;i < 32;i++) if (f[i].getPosition() == oldPos) n = i;

            /////animation///////
            for (int k = 0;k < 50;k++)
            {
                Vector2f p = newPos - oldPos;
                f[n].move(p.x / 50, p.y / 50);
                window.draw(sBoard);
                for (int i = 0;i < 32;i++) f[i].move(offset);
                for (int i = 0;i < 32;i++) window.draw(f[i]); window.draw(f[n]);
                for (int i = 0;i < 32;i++) f[i].move(-offset);
                window.display();
            }

            move(str);  //position += str + " ";
            f[n].setPosition(newPos);
        }

        if (isMove) f[n].setPosition(pos.x - dx, pos.y - dy);

        ////// draw  ///////
        window.clear();
        window.draw(sBoard);
        for (int i = 0;i < 32;i++) f[i].move(offset);
        for (int i = 0;i < 32;i++) window.draw(f[i]); window.draw(f[n]);
        for (int i = 0;i < 32;i++) f[i].move(-offset);
        window.display();
    }

    

    return 0;
}
void loadPosition()
{
    // loadpositionul e gata cred
    std::ifstream cin("Text.txt");
    std::string position, moveList;
    cin >> position;


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
                switch (c)
                {
                case 'r':
                    board[line][col] = -1;
                    break;
                case 'b':
                    board[line][col] = -3;
                    break;
                case 'k':
                    board[line][col] = -5;
                    break;
                case 'q':
                    board[line][col] = -4;
                    break;
                case 'p':
                    board[line][col] = -6;
                    break;
                case 'n':
                    board[line][col] = -2;
                    break;
                case 'R':
                    board[line][col] = 1;
                    break;
                case 'N':
                    board[line][col] = 2;
                    break;
                case 'B':
                    board[line][col] = 3;
                    break;
                case 'Q':
                    board[line][col] = 4;
                    break;
                case 'K':
                    board[line][col] = 5;
                    break;
                case 'P':
                    board[line][col] = 6;
                    break;
                }
                col++;
            }
    }
    cin.close();
    int k = 0;
    for (int i = 0;i < 8;i++)
        for (int j = 0;j < 8;j++)
        {
            int n = board[i][j];
            if (!n) continue;
            int x = abs(n) - 1;
            int y = n > 0 ? 1 : 0;
            f[k].setTextureRect(IntRect(size * x, size * y, size, size));
            f[k].setPosition(size * j, size * i);
            k++;
        }

    
}