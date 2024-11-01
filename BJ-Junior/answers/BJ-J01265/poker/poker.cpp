#include <bits/stdc++.h>
using namespace std;
bool p[5][14];
int ans;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char x,y;
        int xx,yy;
        cin>>x>>y;
        if(x=='D')xx=1;
        else if(x=='C')xx=2;
        else if(x=='H')xx=3;
        else xx=4;
        if(y=='A')yy=1;
        else if(y=='T')yy=10;
        else if(y=='J')yy=11;
        else if(y=='Q')yy=12;
        else if(y=='K')yy=13;
        else yy=y-'0';
        p[xx][yy]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!p[i][j])ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}