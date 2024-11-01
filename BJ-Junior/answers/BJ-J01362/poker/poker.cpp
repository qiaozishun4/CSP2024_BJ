#include <bits/stdc++.h>

using namespace std;
bool p[4][13];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    memset(p,0,sizeof(p));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int a0,a1;
        if(s[0]=='D')a0=0;
        else if(s[0]=='C')a0=1;
        else if(s[0]=='H')a0=2;
        else if(s[0]=='S')a0=3;

        if(s[1]=='A')a1=0;
        else if(s[1]=='T')a1=9;
        else if(s[1]=='J')a1=10;
        else if(s[1]=='Q')a1=11;
        else if(s[1]=='K')a1=12;
        else a1=(s[1]-'1');

        p[a0][a1]=1;
    }

    n=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            n+=(p[i][j]==0);
        }
    }
    cout<<n;
    
    return 0;
}
