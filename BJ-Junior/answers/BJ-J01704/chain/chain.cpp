#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,cnt;
string s;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++) cin>>s;
        if(cnt%2==0) cout<<1;
        else cout<<0;
        cout<<endl;
        cnt++;
        cnt%=2;
    }
    return 0;
} 
