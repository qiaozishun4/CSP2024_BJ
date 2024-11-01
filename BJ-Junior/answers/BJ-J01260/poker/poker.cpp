#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool tmp[7][20];
int ans,n;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int type=0,num=0;
        string a;
        cin>>a;
        if(a[0]=='D') type=1;
        else if(a[0]=='C') type=2;
        else if(a[0]=='H') type=3;
        else if(a[0]=='S') type=4;
        if(a[1]>='2'&&a[1]<='9') num=a[1]-'0';
        else if(a[1]=='A') num=1;
        else if(a[1]=='T') num=10;
        else if(a[1]=='J') num=11;
        else if(a[1]=='Q') num=12;
        else if(a[1]=='K') num=13;
        tmp[type][num]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            ans+=tmp[i][j];
        }
    }
    cout<<52-ans;
    return 0;
}