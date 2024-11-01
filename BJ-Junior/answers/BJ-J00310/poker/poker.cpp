#include<bits/stdc++.h>
using namespace std;
int a[5][15];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string st;
    for(int i=1;i<=n;i++)
    {
        cin>>st;
        int x,y;
        switch(st[0])
        {
            case 'D':x=1;break;
            case 'C':x=2;break;
            case 'H':x=3;break;
            case 'S':x=4;break;
        }
        if(st[1]=='T'||st[1]=='J'||st[1]=='Q'||st[1]=='K'||st[1]=='A')
        {
            if(st[1]=='T')
                y=10;
            if(st[1]=='J')
                y=11;
            if(st[1]=='Q')
                y=12;
            if(st[1]=='K')
                y=13;
            if(st[1]=='A')
                y=1;
        }
        else
            y=st[1]-'0';
        a[x][y]=1;
    }
    int ans=0;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            if(!a[i][j])
                ans++;
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
