#include<bits/stdc++.h>
using namespace std;
int n,d[5][14];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        int x,y;
        if(s[0]=='C')
            x=2;
        else if(s[0]=='D')
            x=1;
        else if(s[0]=='H')
            x=3;
        else if(s[0]=='S')
            x=4;
        if(s[1]=='A')
            y=1;
        else if(s[1]=='T')
            y=10;
        else if(s[1]=='J')
            y=11;
        else if(s[1]=='Q')
            y=12;
        else if(s[1]=='K')
            y=13;
        else
            y=int(s[1])-48;
        ++d[x][y];
    }
    int ans=0;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            if(d[i][j]>0)
                ans++;
    printf("%d",52-ans);
}
