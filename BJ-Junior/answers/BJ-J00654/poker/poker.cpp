#include <iostream>
#include <cstdio>
using namespace std;

bool poker[60];
int gets(char c)
{
    if(c == 'D') return 0;
    if(c == 'C') return 1;
    if(c == 'H') return 2;
    if(c == 'S') return 3;
}
int getn(char c)
{
    if('2' <= c && c <= '9') return c - '0';
    if(c == 'T') return 10;
    if(c == 'J') return 11;
    if(c == 'Q') return 12;
    if(c == 'K') return 13;
    if(c == 'A') return 1;
}

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        char c1, c2;
        cin >> c1 >> c2;
        poker[gets(c1) * 13 + getn(c2)] = true;
    }

    int cnt = 0;
    for(int i = 1; i <= 52; i++)
        if(poker[i] == false) cnt++;
    cout << cnt << endl;
    return 0;
}
