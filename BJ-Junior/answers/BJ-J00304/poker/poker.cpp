#include<iostream>
using namespace std;
int a[5][14], n, cnt;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        string s;
        cin >> s;
        int x, y;
        if(s[0]=='D')
        {
            x=1;
        }
        else if(s[0]=='C')
        {
            x=2;
        }
        else if(s[0]=='H')
        {
            x=3;
        }
        else
        {
            x=4;
        }
        if(s[1]>='A'&&s[1]<='Z')
        {
            a[x][(s[1]-'A'+1)]+=1;
        }
        else
        {
            a[x][s[1]-'0']+=1;
        }
    }
    for(int i=1; i<=4; i++)
    {
        for(int j=1; j<=13; j++)
        {
            if(a[i][j]==0)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}