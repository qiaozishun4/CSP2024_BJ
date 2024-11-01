#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int T,n;
int a[N];
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    a[2]=1;
    a[3]=7;
    a[4]=4;
    a[5]=2;
    a[6]=0;
    a[7]=8;
    cin>>T;
    while(T--){
        cin>>n;
        if(a[n]==0&&n!=6){
            cout<<"-1"<<endl;
        }
        else{
            cout<<a[n]<<endl;
        }
    }
    return 0;
}
//0123456789
//6255456376
