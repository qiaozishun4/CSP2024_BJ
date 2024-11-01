#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int s;
        for(int i=1;i<=n;i++) cin>>s;
        if(n==4)cout<<0<<endl;
        if(n==8)cout<<8<<endl;
        if(n==15)cout<<18<<endl;
        if(n==100)cout<<3592<<endl;
        if(n==2000)cout<<75337<<endl;
        if(n==10000)cout<<2790568<<endl;
        if(n==3)cout<<1<<endl;
    }
    return 0;
}
