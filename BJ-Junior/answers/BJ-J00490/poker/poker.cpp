#include<bits/stdc++.h>
using namespace std;

int n;
char c[10];
int a[20][10];

int sqy(char x)
{
    int aa;
    if(x=='D')
        aa=1;
    else if(x=='C')
        aa=2;
    else if(x=='H')
        aa=3;
    else
        aa=4;
    return aa;
}

int sqx(char x)
{
    int aa;
    if(x>='2' && x<='9')
        aa=x-'0';
    else if(x=='A')
        aa=1;
    else if(x=='T')
        aa=10;
    else if(x=='J')
        aa=11;
    else if(x=='Q')
        aa=12;
    else if(x=='K')
        aa=13;
    return aa;
}

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c;
        int x,y;
        y=sqy(c[0]);
        x=sqx(c[1]);
        a[x][y]=1;
    }
    int ans=0;
    for(int i=1;i<=13;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(a[i][j]==0)
                ans++;
        }
    }
    cout<<ans;
    return 0;
}
