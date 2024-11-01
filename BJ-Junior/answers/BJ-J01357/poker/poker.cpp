#include <bits/stdc++.h>

using namespace std;

int n;
int cnt;
bool vis[10][20];

int Get1(char ch)
{
    if(ch == 'D')
        return 1;
    else if(ch == 'C')
        return 2;
    else if(ch == 'H')
        return 3;
    else
        return 4;
}

int Get2(char ch)
{
    if(ch == 'A')
        return 1;
    else if(ch == 'T')
        return 10;
    else if(ch == 'J')
        return 11;
    else if(ch == 'Q')
        return 12;
    else if(ch == 'K')
        return 13;
    else
        return ch - '0';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        string str;
        cin >> str;
        vis[Get1(str[0])][Get2(str[1])] = true;
    }

    for(int i = 1;i <= 4;i++)
        for(int j = 1;j <= 13;j++)
            if(vis[i][j])
                cnt++;
    cout << 52 - cnt << '\n';

    return 0;
}