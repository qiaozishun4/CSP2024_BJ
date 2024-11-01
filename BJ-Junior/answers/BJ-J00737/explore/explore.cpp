

#include <bits/stdc++.h>

using namespace std;

int _maxi = 0;
vector<string> _myMap;
int _checkMap[1009][1009];

//yes -> false no -> true
bool Check (int x , int y , int way , int sizeX , int sizeY) {
    if (way == 0) {
        if (y+1 > sizeY || _myMap[x][y+1] == 'x') {
            //cout << "STUCK" << "first: " << y+1 << "than" << endl;
            return true;
        }
    }

    if (way == 1) {
        if (x+1 > sizeX || _myMap[x+1][y] == 'x') {
            //cout << "STUCK" << "first: " << x+1 << "than" << endl;
            return true;
        }
    }

    if (way == 2) {
        if (y-1 < 1 || _myMap[x][y-1] == 'x') {
            //cout << "STUCK" << "first: " << y-1 << "than" << endl;
            return true;
        }
    }

    if (way == 3) {
        if (x-1 < 1 || _myMap[x-1][y] == 'x') {
            //cout << "STUCK" << "first: " << x-1 << "than"<< endl;
            return true;
        }
    }

    return false;
}


void Move (int x , int y , int way , int stepRemain, int sizeX , int sizeY) {
    //cout << 1 << endl;
    _checkMap[x][y]++;

    while (Check(x , y , way , sizeX , sizeY)) {
        stepRemain--;
        way = (way + 1) % 4;

        //cout << "![ " << stepRemain << "way : " << way << endl;
    }

    if (stepRemain < 1) {

        return;
    }

    if (way == 0) {
        //cout << "[" << stepRemain << "]" << x << y << endl;
        Move (x , y+1 , way , stepRemain-1 , sizeX , sizeY);
    }

    if (way == 1) {
        //cout << "[" << stepRemain << "]" << x << y << endl;
        Move (x+1 , y , way , stepRemain-1 , sizeX , sizeY);
    }

    if (way == 2) {
        //cout << "[" << stepRemain << "]" << x << y << endl;
        Move (x , y-1 , way , stepRemain-1 , sizeX , sizeY);
    }

    if (way == 3) {
        //cout << "[" << stepRemain << "]" << x << y << endl;
        Move (x-1 , y , way , stepRemain-1 , sizeX , sizeY);
    }
}

int CheckRes (int maxiX , int maxiY) {
    int res = 0;

    for (int i = 1; i < maxiX + 1; i++) {
        for (int m = 1; m < maxiY + 1; m++) {
            if (_checkMap[i][m] != 0) {

                _checkMap[i][m] = 0;
                res++;
            }
        }

    }

    return res;
}

int main () {
    int step = 0;
    int x = 0;
    int y = 0;
    int sizeX = 0;
    int sizeY = 0;
    int position = 0;
    string curStr = "";
    char curChar = 'E';

    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin >> _maxi;

    for (int i = 0; i < _maxi; i++) {

        cin >> sizeX >> sizeY >> step;
        cin >> x >> y >> position;

        for (int m = 0; m < sizeY; m++) {

            curStr += 'x';
        }
        _myMap.push_back(curStr);
        curStr = "";

        //cout << sizeX << "!" << endl;
        for (int m = 0; m < sizeX; m++) {
            curStr += 'x';
            //cout << "In" << sizeY << endl;
            for (int k = 0; k < sizeY; k++) {
                cin >> curChar;
                curStr += curChar;
            }

            //cout << curStr << endl;
            _myMap.push_back(curStr);
            curStr = "";

            //cout << m << " " << sizeX << endl;
        }

        //cout << _myMap[x][y-1] << endl;
        //cout << "start" << endl;

        Move(x, y , position , step , sizeX , sizeY);

        cout << CheckRes(sizeX , sizeY) << endl;

        _myMap.clear();
    }

    return 0;
}