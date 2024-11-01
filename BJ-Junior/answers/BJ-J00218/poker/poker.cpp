#include<bits/stdc++.h>
using namespace std;
bool poker[4][13];
int n, cnt;
const char a[15] = "A123456789TJQK";
char card[5];
int get_pos(char x)
{
    for (int i = 0; i < 13; i++)
    {
        if (a[i] == x) return i;
    }
}
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> card;
        if (card[0] == 'D') poker[0][get_pos(card[1])] = true;
        if (card[0] == 'C') poker[1][get_pos(card[1])] = true;
        if (card[0] == 'H') poker[2][get_pos(card[1])] = true;
        if (card[0] == 'S') poker[3][get_pos(card[1])] = true;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++) cnt += !poker[i][j];
    }
    cout << cnt;
    return 0;
}