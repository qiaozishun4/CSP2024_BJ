#include<bits/stdc++.h>
using namespace std;

int n,t;
int l[16]={0,0,1,1,1,1,1,1,2,2,2,2,2,2},
    v[16]={0,0,1,7,4,2,6,8,10,18,22,20,28,68};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1){
            cout<<-1<<'\n';
            continue;
        }
        if(n<=13){
            cout<<v[n]<<'\n';
            continue;
        }
        if(n==17){
            cout<<206<<'\n';
            continue;
        }
        int x=n/7-1;
        cout<<v[n-x*7];
        for(int i=1;i<=x;i++){
            cout<<8;
        }
        cout<<'\n';
    }
    return 0;
}
