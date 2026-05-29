#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
using namespace std;

int rollDice() {
    return rand() % 6 + 1;
}

void showBoard(int p1, int p2) {
    cout << "\nBOARD:\n";

    for (int i = 30; i >= 1; i--) {

        if (i == p1 && i == p2)
            cout << "[P1P2] ";
        else if (i == p1)
            cout << "[ P1 ] ";
        else if (i == p2)
            cout << "[ P2 ] ";
        else
            cout << "[ " << i << " ] ";

        if (i % 6 == 1)
            cout << "\n";
    }

    cout << "------------------------\n";
}

int main() {
    srand(time(0));

    map<int, int> jump;

    // Ladders
    jump[3] = 22;
    jump[5] = 8;
    jump[11] = 26;
    jump[20] = 29;

    // Snakes
    jump[27] = 1;
    jump[21] = 9;
    jump[17] = 4;

    int player1 = 0;
    int player2 = 0;
    int turn = 1;

    cout << "=== SNAKE & LADDER GAME STARTED ===\n";

    while (player1 < 30 && player2 < 30) {

        showBoard(player1, player2);

        cout << "\nPress Enter to roll dice...";
        cin.ignore();

        int dice = rollDice();
        cout << "Dice: " << dice << endl;

        if (turn == 1) {
            player1 += dice;

            if (jump.count(player1)) {
                cout << "Snake/Ladder hit for Player 1!\n";
                player1 = jump[player1];
            }

            cout << "Player 1 Position: " << player1 << endl;

            if (player1 >= 30) {
                cout << "\n🎉 Player 1 Wins!" << endl;
                break;
            }

            turn = 2;
        }
        else {
            player2 += dice;

            if (jump.count(player2)) {
                cout << "Snake/Ladder hit for Player 2!\n";
                player2 = jump[player2];
            }

            cout << "Player 2 Position: " << player2 << endl;

            if (player2 >= 30) {
                cout << "\n🎉 Player 2 Wins!" << endl;
                break;
            }

            turn = 1;
        }
    }

    return 0;
}