#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 20;

int a[N][N];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        char x,y;
        cin >> x >> y;
        int nx,ny;
        if(x == 'D') nx = 1;
        if(x == 'C') nx = 2;
        if(x == 'H') nx = 3;
        if(x == 'S') nx = 4;
        if('0' <= y && y <= '9') ny = y - '0';
        if(y == 'A') ny = 1;
        if(y == 'T') ny = 10;
        if(y == 'J') ny = 11;
        if(y == 'Q') ny = 12;
        if(y == 'K') ny = 13;
        a[nx][ny]++;
    }
    int cnt = 0;
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 13; j++)
            if(a[i][j] == 0) cnt++;
    }
    cout << cnt;
    return 0;
}
