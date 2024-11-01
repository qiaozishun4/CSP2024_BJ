#include <bits/stdc++.h>
using namespace std;
long long t,n,m,k,cnt=0;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>t;
    while(t--){
            int n,cnt=0;
            cin>>n;
            int ls[10]={6,2,5,5,4,5,6,3,7,6};
            int x=n/2+1;
            for(int i=1;i<=x;i++){
                for(int j=1;j<10;j++){
                        if(n>ls[i]){
                                n-=ls[i];
                                cnt=cnt*10+i;
                        }}
            }
            if(cnt==0)cout<<-1<<endl;
            else cout<<cnt<<endl;
    }
return 0;
}
//x.
