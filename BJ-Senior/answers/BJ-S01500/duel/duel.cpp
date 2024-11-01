#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+9;
int n,r[maxn];
map<int,bool>mp;
int sum[maxn],tot=0;
int main(){
   freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
     cin>>n;
     for(int i=1;i<=n;i++){
            cin>>r[i];
     }
     sort(r+1,r+1+n);
     int cnt=0;
     for(int i=1;i<=n;i++){
        if(mp[r[i]]){
            sum[tot]++;
            continue;
        }
        if(!mp[r[i]]){
            sum[++tot]++;
            mp[r[i]]=1;

        }
     }
     int ans=0;
     int ss=sum[1];
     for(int i=2;i<=tot;i++){
            if(sum[i]>=ss){
       //         cout<<"&"<<" "<<ss<<" "<<ans<<endl;
                ans+=ss;
                ss=sum[i];
            }
            else{
             //    cout<<"*"<<" "<<ss<<" "<<ans<<endl;
                ans+=sum[i];

            }
     }

  //  for(int i=1;i<=tot;i++){
 //    cout<<sum[i]<<endl;
 //   }

     cout<<n-ans<<endl;

     return 0;
}
