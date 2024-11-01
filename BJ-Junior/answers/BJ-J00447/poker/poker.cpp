#include <bits/stdc++.h>

using namespace std;

int a[4][13];

int main()
{
    int n,sum=0;
    string b;
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x=0,y=0;
        cin>>b;
        if(b[0]=='D')
        {
            x=0;
        }
        else if(b[0]=='C')
        {
            x=1;
        }
        else if(b[0]=='H')
        {
            x=2;
        }
        else
        {
            x=3;
        }
        if(b[1]=='A')
        {
            y=0;
        }
        if(b[1]=='2')
        {
            y=1;
        }
        if(b[1]=='3')
        {
            y=2;
        }
        if(b[1]=='4')
        {
            y=3;
        }
        if(b[1]=='5')
        {
            y=4;
        }
        if(b[1]=='6')
        {
            y=5;
        }
        if(b[1]=='7')
        {
            y=6;
        }
        if(b[1]=='8')
        {
            y=7;
        }
        if(b[1]=='9')
        {
            y=8;
        }
        if(b[1]=='T')
        {
            y=9;
        }
        if(b[1]=='J')
        {
            y=10;
        }
        if(b[1]=='Q')
        {
            y=11;
        }
        if(b[1]=='K')
        {
            y=12;
        }
        a[x][y]++;
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
            if(!a[i][j])
            {
                sum++;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}