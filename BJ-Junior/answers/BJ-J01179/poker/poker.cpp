#include <bits/stdc++.h>
using namespace std;
bool flag[5][15] = {0};
int n,ans = 0;
char x,y;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    while (n--){
        cin >> x >> y;
        int a,b;
        if (x == 'D') a = 1;
        else if (x == 'C') a = 2;
        else if (x == 'H') a = 3;
        else a = 4;
        if (y == 'A') b = 1;
        else if (y == 'K') b = 13;
        else if (y == 'Q') b = 12;
        else if (y == 'J') b = 11;
        else if (y == 'T') b = 10;
        else b = y - '0';
        flag[a][b] = 1;
    }
    for (int i = 1;i <= 4;i++)
        for (int j = 1;j <= 13;j++)
            if (!flag[i][j]) ans++;
    cout << ans;
    return 0;
}