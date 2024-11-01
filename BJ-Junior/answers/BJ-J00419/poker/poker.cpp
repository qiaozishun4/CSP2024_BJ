#include <bits/stdc++.h>
using namespace std;

const int MAXN = 52 + 1;
string s[MAXN];
bool str[5][14];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for(int i=1, string s; i<=n; i++)
    {
        cin >> s;
        if(s[0] == 'D'){
            if(s[1] == 'A')
                str[1][1] = true;
            else if(s[1] == 'T')
                str[1][10] = true;
            else if(s[1] == 'J')
                str[1][11] = true;
            else if(s[1] == 'Q')
                str[1][12] = true;
            else if(s[1] == 'K')
                str[1][13] = true;
        } else if (s[0] == 'C'){
            if(s[1] == 'A')
                str[2][1] = true;
            else if(s[1] == 'T')
                str[2][10] = true;
            else if(s[1] == 'J')
                str[2][11] = true;
            else if(s[1] == 'Q')
                str[2][12] = true;
            else if(s[1] == 'K')
                str[2][13] = true;
        } else if(s[0] == 'H'){
            if(s[1] == 'A')
                str[3][1] = true;
            else if(s[1] == 'T')
                str[3][10] = true;
            else if(s[1] == 'J')
                str[3][11] = true;
            else if(s[1] == 'Q')
                str[3][12] = true;
            else if(s[1] == 'K')
                str[3][13] = true;
        } else {
            if(s[1] == 'A')
                str[4][1] = true;
            else if(s[1] == 'T')
                str[4][10] = true;
            else if(s[1] == 'J')
                str[4][11] = true;
            else if(s[1] == 'Q')
                str[4][12] = true;
            else if(s[1] == 'K')
                str[4][13] = true;
        }
    }
    int cnt=0;
    for(int i=1; i<=4; i++)
        for(int j=1; j<=13; j++)
            if(!str[i][j]) cnt++;
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
