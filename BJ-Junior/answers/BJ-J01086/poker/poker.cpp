#include<bits/stdc++.h>
using namespace std;
int n;
int a[55][2];
char c[55][2];
bool b[5][14];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>c[i];
        if(c[i][0]=='D')a[i][0]=1;
        if(c[i][0]=='C')a[i][0]=2;
        if(c[i][0]=='H')a[i][0]=3;
        if(c[i][0]=='S')a[i][0]=4;

        if(c[i][1]=='A')a[i][1]=1;
        else if(c[i][1]=='T')a[i][1]=10;
        else if(c[i][1]=='J')a[i][1]=11;
        else if(c[i][1]=='Q')a[i][1]=12;
        else if(c[i][1]=='K')a[i][1]=13;
        else a[i][1]=c[i][1]-'0';
        b[a[i][0]][a[i][1]]=1;
    }
    int ans=0;
    for(int i=1;i<=4;++i){
        for(int j=1;j<=13;++j){
            if(!b[i][j])++ans;
        }
    }
    cout<<ans;
    return 0;
}
