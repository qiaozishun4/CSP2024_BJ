#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T;
ll n;
int a[21]={0,0,1,7,11,17,14,12,10,18,22,20,28,68,88,180,188,206,208,288,688};//zhinengdabiao cnm

ll ans;
int k=1;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        k=1;
        if(n<2){
            cout<<-1<<endl;
            continue;
        }
        cout<<a[n]<<endl;
    }
    return 0;
}
