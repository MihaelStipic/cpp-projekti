#include <iostream>
#include <vector>
using namespace std;
class Player{
private:
    string name;
    char symbol;
public:
    Player(string n, char s) {
        name = n;
        symbol = s;
    }

};

class Board {
private:
    char grid[9];
public:
    Board();
    void display();
    bool update(int position, char symbol);
    bool is_full();

    bool check_winner(char symbol) {                       // Provjerava jel' igrač pobijedio
        int win_positions[8][3] = {                        // Moguće kombinacije s kojima igrač moze pobijediti
            {0,1,2}, {3,4,5}, {6,7,8},            // Redovi
            {0,3,6}, {1,4,7}, {2,5,8},            // Stupci
            {0,4,8}, {2,4,6}                         // Dijagonale
        };
        for (int i =0; i<8; i++) {                         // Prolazi petljom te provjerava.
            if (grid[win_positions[i][0]] == symbol &&
                grid[win_positions[i][1]] == symbol &&
                grid[win_positions[i][2]] == symbol) {
                return true;
            }

        }

        return false;

    }


};


Board::Board() {                       // konstruktor
    for (int i = 0; i < 9; i++) {
        grid[i] = ' ';
    }
}

bool Board::is_full() {                // Provjerava je li mreža popunjena
    for (int i=0; i<9;i++) {
        if (grid[i] == ' ') {
            return false;
        }
    }
    return true;
}

bool Board::update(int position, char symbol) {              // Postavljanje X / O u mrežu
    if (position < 0 || position >= 9) {
        cout<< "Pozicija ne postoji";
        return false;
    }

    if (grid[position] ==' ') {
        grid[position] = symbol;
        return true;
    }else {
        cout<<"Pozicija zauzeta";
        return false;
    }


}



void Board::display() {             // print
    cout<<endl;
    for (int i =0; i<9; i++) {
        if (grid[i] == ' ') {
            cout<< i;
        }else {
            cout<< grid[i];
        }

        if (i == 2 || i == 5) {
            cout<<endl;
            cout<<"--+---+---";
            cout<<endl;
        } else if (i ==8) {
            cout<<endl;
        }else {
            cout<< " | ";
        }


    }
}


class Game {
private:
    Board board;
    char player;
public:
    Game () : player ('X'){}
    void play() {
        int positions;
        bool run = true;
        while (run) {
            board.display();
            cout<<"Igrac "<<player<< " unesi poziciju (0-8): "<< endl;
            cin>>positions;
            if (!board.update(positions,player)) {
                cout<<"Potez nije valjan, probaj opet."<<endl;
                continue;
            }

            if (board.check_winner(player)) {
                cout<< "Igrac "<< player << " je pobijedio"<<endl;
                run = false;

            } else if (board.is_full()){
                cout<< "Izjednaceno"<<endl;
                run = false;
            }else {
                if (player == 'X') {
                    player = 'O';

                }else {
                    player = 'X';
                }
            }
        }
    }
};


int main() {

    Game P;
    P.play();

}
