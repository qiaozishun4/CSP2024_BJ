#include<bits/stdc++.h>
using namespace std;
int t,n,mp[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        bool b=0;
        for(int i=1;i<1000000;i++){
            int num=0;
            int x=i;
            while(x>0){
                num+=mp[x%10];
                x/=10;
            }
            if(num==n){
                cout<<i<<endl;
                b=1;
                break;
            }
        }
        if(b==0) cout<<-1<<endl;
    }
    return 0;
}
