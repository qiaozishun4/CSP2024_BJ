#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool an[20][100];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        string s;
        cin>>s;
        b=s[0];
        a=s[1];
        if(a=='A')a=1;
        else if(a=='T')a=10;
        else if(a=='J')a=11;
        else if(a=='Q')a=12;
        else if(a=='K')a=13;
        else a-=48;
        if(b=='D')an[1][a]=true;
        if(b=='C')an[2][a]=true;
        if(b=='H')an[3][a]=true;
        if(b=='S')an[4][a]=true;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!an[i][j])ans++;
        }
    }
    cout<<ans;
    return 0;
}
