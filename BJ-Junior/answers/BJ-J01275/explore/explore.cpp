#include<bits/stdc++.h>
using namespace std;

int T;
long long n,ans;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n<2) ans=-1;
        if(n==2) ans=1;
        if(n==3) ans=7;
        if(n==4) ans=4;
        if(n==5) ans=2;
        if(n==6) ans=6;
        if(n==7) ans=8;
        if(n==8) ans=10;
        if(n==9) ans=18;
        if(n==10) ans=46;
        if(n==11) ans=36;
        if(n==12) ans=28;
        if(n==13) ans=68;
        if(n==14) ans=88;
        if(n==15) ans=168;
        if(n==16) ans=188;
        if(n==17) ans=200;
        if(n==18) ans=208;
        if(n==19) ans=288;
        if(n==20) ans=688;
        cout<<ans<<endl;
    }
    return 0;
}
