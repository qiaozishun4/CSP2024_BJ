#include <bits/stdc++.h>
using namespace std;
int ans[]={0,-1,1,7,4,2,0,8},tmp[]={88,10,18,200,20,28,68};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(n<=7) cout<<ans[n]<<'\n';
        else if(n==10) cout<<"22\n";
        else{
            cout<<tmp[n%7];
            if(n%7==3||n%7==0) n-=7;
            n=n-n%7-7;
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<'\n';
        }
    }
    return 0;
}
//CSP rp++;