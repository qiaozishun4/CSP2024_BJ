#include<bits/stdc++.h>
using namespace std;
int n,ans;
char f[200][200];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char ch,cc;
        cin>>ch>>cc;
        int a=0,b=0;
        if(ch=='D')a=1;
        else if(ch=='C')a=2;
        else if(ch=='H')a=3;
        else a=4;
        if(cc>='2'&&cc<='9')b=cc-'0';
        else if(cc=='A')b=1;
        else if(cc=='J')b=11;
        else if(cc=='Q')b=12;
        else if(cc=='K')b=13;
        else b=10;
        f[b][a]=1;
    }
    for(int i=1;i<=13;i++){
        for(int j=1;j<=4;j++){
            if(!f[i][j])ans++;
        }
    }
    cout<<ans;
    return 0;
}
