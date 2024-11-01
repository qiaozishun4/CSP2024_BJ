#include<bits/stdc++.h>
using namespace std;
int n;
int t[10][40];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        char a,b;
        cin >> a >> b;
        int aaa,bbb;
        if(a=='D')aaa=1;
        if(a=='C')aaa=2;
        if(a=='H')aaa=3;
        if(a=='S')aaa=4;
        if(b>'0'&&b<='9')bbb=(int)(b-'0');
        else if(b=='A')bbb=1;
        else if(b=='T')bbb=10;
        else if(b=='J')bbb=11;
        else if(b=='Q')bbb=12;
        else if(b=='K')bbb=13;
        t[aaa][bbb]=1;
    }
    int ans=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!t[i][j])ans++;
        }
    }
    cout << ans;
    return 0;
}
