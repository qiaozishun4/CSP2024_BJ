#include<bits/stdc++.h>
using namespace std;
bool a[5][15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int ans=52,nn,m,n;
    char x,y;
    cin>>nn;
    memset(a,0,sizeof(a));
    for(int i=1;i<=nn;i++){
        cin>>x>>y;
        //cout<<x<<" "<<y<<endl;
        if(x=='D') m=1;
        else if(x=='C') m=2;
        else if(x=='H') m=3;
        else if(x=='S') m=4;
        if(y>'0'&&y<='9')n=y-'0';
        else if(y=='A') n=1;
        else if(y=='T') n=10;
        else if(y=='J') n=11;
        else if(y=='Q') n=12;
        else if(y=='K') n=13;
        if(a[m][n]==0){
            ans--;
            a[m][n]=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}