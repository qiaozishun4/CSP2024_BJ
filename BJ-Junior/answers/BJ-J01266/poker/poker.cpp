#include<iostream>
using namespace std;

int n;
int flag[5][15]; // D C H S

int num(char c)
{
    if(c == 'A') return 1;
    if(c == 'T') return 10;
    if(c == 'J') return 11;
    if(c == 'Q') return 12;
    if(c == 'K') return 13;
    return c - '0';
}
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n ;
    for(int i = 1; i <= n; i++)
    {
        char c1, c2;
        cin >> c1 >> c2 ;
        if(c1 == 'D') flag[1][num(c2)]++;
        else if(c1 == 'C') flag[2][num(c2)]++;
        else if(c1 == 'H') flag[3][num(c2)]++;
        else if(c1 == 'S') flag[4][num(c2)]++;
    }
    int cnt = 0;
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 13; j++)
        {
            if(!flag[i][j]) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

