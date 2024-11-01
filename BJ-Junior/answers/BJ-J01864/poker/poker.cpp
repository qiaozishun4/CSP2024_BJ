#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
int n;
char b,c;
bool a[5][15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    rep(i,n){
        cin>>b>>c;
        int x=0,y=0;
        if(b=='D')x=1;
        else if(b=='C')x=2;
        else if(b=='H')x=3;
        else x=4;
        if(c=='A')y=1;
        else if(c=='2')y=2;
        else if(c=='3')y=3;
        else if(c=='4')y=4;
        else if(c=='5')y=5;
        else if(c=='6')y=6;
        else if(c=='7')y=7;
        else if(c=='8')y=8;
        else if(c=='9')y=9;
        else if(c=='T')y=10;
        else if(c=='J')y=11;
        else if(c=='Q')y=12;
        else y=13;
        a[x][y]=1;
    }
    int ans=0;
    rep(i,4) rep(j,13){
        if(!a[i][j])ans++;
    }
    cout<<ans<<endl;
    return 0;
}
