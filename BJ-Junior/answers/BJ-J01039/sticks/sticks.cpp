#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int T,n;
int f[maxn]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,228,208,288,688};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n<=20){
            cout<<f[n]<<endl;
            continue;
        }
        else if(n%7==0){
            int k=n/7;
            for(int i=1;i<=k;i++)cout<<8;
            cout<<endl;
        }
        else if(n%7==1){
            int k=n/7-1;
            cout<<10;
            for(int i=1;i<=k;i++)cout<<8;
            cout<<endl;
        }
    }
    return 0;
}
