#include<bits/stdc++.h>
using namespace std;
bool f[5][20];
int n;
string s;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        char a=s[0];
        char b=s[1];
        int a1;
        int b1;
        if(a=='D')
        {
            a1=1;
        }
        else if(a=='C')
        {
            a1=2;
        }
        else if(a=='H')
        {
            a1=3;
        }
        else if(a=='S')
        {
            a1=4;
        }
        if(b=='A')
        {
            b1=1;
        }
        else if(b=='2')
        {
            b1=2;
        }
        else if(b=='3')
        {
            b1=3;
        }
        else if(b=='4')
        {
            b1=4;
        }
        else if(b=='5')
        {
            b1=5;
        }
        else if(b=='6')
        {
            b1=6;
        }
        else if(b=='7')
        {
            b1=7;
        }
        else if(b=='8')
        {
            b1=8;
        }
        else if(b=='9')
        {
            b1=9;
        }
        else if(b=='T')
        {
            b1=10;
        }
        else if(b=='J')
        {
            b1=11;
        }
        else if(b=='Q')
        {
            b1=12;
        }
        else if(b=='K')
        {
            b1=13;
        }
        f[a1][b1]=1;
    }
    int cnt=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(f[i][j]==0)
            {
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
