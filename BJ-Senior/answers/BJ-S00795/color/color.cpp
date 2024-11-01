#include<bits/stdc++.h>
using namespace std;
map<long long,long long>mp;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        for(long long i=1;i<=n;i++){
            long long x;
            cin>>x;
            mp[x]++;
        }
        long long cnt=0;
        for(auto i:mp){
            if(i.second>1)cnt+=i.first*(i.second-1);
            mp[i.first]=0;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
