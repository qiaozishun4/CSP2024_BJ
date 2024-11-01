#include<iostream>
using namespace std;
int n, cnt;
bool p[10][15];
string temp;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> temp;
        int res = 0;

        if(temp[1] == 'A') res = 1;
        else if(temp[1] == 'T') res = 10;
        else if(temp[1] == 'J') res = 11;
        else if(temp[1] == 'Q') res = 12;
        else if(temp[1] == 'K') res = 13;
        else res = temp[1] - '0';

        if(temp[0] == 'D') p[1][res] = true;
        else if(temp[0] == 'C') p[2][res] = true;
        else if(temp[0] == 'H') p[3][res] = true;
        else p[4][res] = true; // S
    }
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 13; j++)
        {
            if(p[i][j] == false) cnt++;
        }
    }
    cout << cnt;
    return 0;
}

