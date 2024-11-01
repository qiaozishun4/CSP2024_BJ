#include <bits/stdc++.h>
using namespace std;
string s;
int n,ans;
bool book[7][15];
void work(int x,char y)
{
    if(y == 'A') book[x][1] = 1;
    else if(y == '2') book[x][2] = 1;
    else if(y == '3') book[x][3] = 1;
    else if(y == '4') book[x][4] = 1;
    else if(y == '5') book[x][5] = 1;
    else if(y == '6') book[x][6] = 1;
    else if(y == '7') book[x][7] = 1;
    else if(y == '8') book[x][8] = 1;
    else if(y == '9') book[x][9] = 1;
    else if(y == 'T') book[x][10] = 1;
    else if(y == 'J') book[x][11] = 1;
    else if(y == 'Q') book[x][12] = 1;
    else if(y == 'K') book[x][13] = 1;

}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        cin >> s;
        if(s[0] == 'D') work(1,s[1]);
        else if(s[0] == 'C') work(2,s[1]);
        else if(s[0] == 'H') work(3,s[1]);
        else if(s[0] == 'S') work(4,s[1]);
    }
    for(int i = 1;i<=4;i++)
        for(int j = 1;j<=13;j++)
            if(book[i][j]) ans++;
    printf("%d",52-ans);
    return 0;
}
