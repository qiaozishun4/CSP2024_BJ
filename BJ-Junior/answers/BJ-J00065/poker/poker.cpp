#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=52;
    cin>>n;
    int a[5][14]={0};
    char x,y;
    for(int i=1;i<=n;i++){
        int j,t;
        cin>>x>>y;
        if(x=='D') j=1;
        else if(x=='C') j=2;
        else if(x=='H') j=3;
        else j=4;
        if(y=='T') t=10;
        else if(y=='J') t=11;
        else if(y=='Q') t=12;
        else if(y=='K') t=13;
        else if(y=='A') t=1;
        else t=y-'0';
        if(!a[j][t]){
            a[j][t]=1;
            cnt--;
        }
    }
    cout<<cnt;
    return 0;
}
