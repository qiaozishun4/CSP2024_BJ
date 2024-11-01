

#include <bits/stdc++.h>

using namespace std;

int _myArray[109];
int _maxi = 0;

int main () {
    int solo = 0;
    int res = 0;
    string card = "";

    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin >> _maxi;

    for (int i = 0; i < _maxi; i++) {
        cin >> card;

        if (card[0] == 'C') {
            solo += 13;
        }

        if (card[0] == 'H') {
            solo += 26;
        }

        if (card[0] == 'S') {
            solo += 39;
        }

        if (card[1] == 'A') {
            solo += 1;
        }

        if (card[1] == '2') {
            solo += 2;
        }

        if (card[1] == '3') {
            solo += 3;
        }

        if (card[1] == '4') {
            solo += 4;
        }

        if (card[1] == '5') {
            solo += 5;
        }

        if (card[1] == '6') {
            solo += 6;
        }

        if (card[1] == '7') {
            solo += 7;
        }

        if (card[1] == '8') {
            solo += 8;
        }

        if (card[1] == '9') {
            solo += 9;
        }

        if (card[1] == 'T') {
            solo += 10;
        }

        if (card[1] == 'J') {
            solo += 11;
        }

        if (card[1] == 'Q') {
            solo += 12;
        }

        if (card[1] == 'K') {
            solo += 13;
        }

        _myArray[solo]++;
        solo = 0;
    }

    for (int i = 1; i < 53; i++) {
        if (_myArray[i] == 0) {

            res++;
        }
    }

    cout << res << endl;

    return 0;
}