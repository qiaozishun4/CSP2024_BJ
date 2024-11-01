#include<bits/stdc++.h>
using namespace std;
int sum,x[10][20],n;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    //freopen("poker.in","w",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        int a,b;
        cin>>s;
        if(s[0]=='D')
        {
            a=1;
            if(s[1]=='A')
                b=1;
            else if(s[1]=='T')
                b=10;
            else if(s[1]=='J')
                b=11;
            else if(s[1]=='Q')
                b=12;
            else if(s[1]=='K')
                b=13;
            else
                b=int(s[1]-'0');
            x[a][b]++;
        }
        if(s[0]=='C')
        {
            a=2;
            if(s[1]=='A')
                b=1;
            else if(s[1]=='T')
                b=10;
            else if(s[1]=='J')
                b=11;
            else if(s[1]=='Q')
                b=12;
            else if(s[1]=='K')
                b=13;
            else
                b=int(s[1]-'0');
            x[a][b]++;
        }
        if(s[0]=='H')
        {
            a=3;
            if(s[1]=='A')
                b=1;
            else if(s[1]=='T')
                b=10;
            else if(s[1]=='J')
                b=11;
            else if(s[1]=='Q')
                b=12;
            else if(s[1]=='K')
                b=13;
            else
                b=int(s[1]-'0');
            x[a][b]++;
        }
        if(s[0]=='S')
        {
            a=4;
            if(s[1]=='A')
                b=1;
            else if(s[1]=='T')
                b=10;
            else if(s[1]=='J')
                b=11;
            else if(s[1]=='Q')
                b=12;
            else if(s[1]=='K')
                b=13;
            else
                b=int(s[1]-'0');
            x[a][b]++;
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(x[i][j]<1)
            {
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}