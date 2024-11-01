#include<bits/stdc++.h>
using namespace std;
bool ish[5][20];
int n;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    memset(ish,0,sizeof ish);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        int h,l;
        if(s[0] == 'D') h = 1;
        if(s[0] == 'C') h = 2;
        if(s[0] == 'H') h = 3;
        if(s[0] == 'S') h = 4;
        if(s[1] >= '2' && s[1] <= '9')
            l = s[1] - '0';
        else
        {
            if(s[1] == 'A') l = 1;
            if(s[1] == 'T') l = 10;
            if(s[1] == 'J') l = 11;
            if(s[1] == 'Q') l = 12;
            if(s[1] == 'K') l = 13;
        }
        ish[h][l] = true;
    }
    int cnt = 0;
    for(int i = 1;i <= 4;i++)
    {
        for(int j = 1;j <= 13;j++)
        {
            if(!ish[i][j])
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
