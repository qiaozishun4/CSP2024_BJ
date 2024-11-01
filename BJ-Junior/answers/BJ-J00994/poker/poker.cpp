#include <bits/stdc++.h>
using namespace std;
int n,cnt=52;
bool v[20][6];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        int d=0,n=0;
        if(a=='D') n=1;
        if(a=='C') n=2;
        if(a=='H') n=3;
        if(a=='S') n=4;
        if(b=='T') d=10;
        else if(b=='A')d=1;
        else if(b=='J') d=11;
        else if(b=='Q') d=12;
        else if(b=='K') d=13;
        else d=b-'0';
        if(v[d][n]==0){
            cnt--;
            if(cnt==0) break;
            v[d][n]=1;
        }
    }
    cout<<cnt;
    return 0;
}
