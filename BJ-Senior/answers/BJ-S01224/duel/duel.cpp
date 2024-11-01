#include<bits/stdc++.h>
using namespace std;
bool a[100010];
int c[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    long long n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    sort(c+1,c+n+1);
    long long dns=0,j=c[1];
    for(int i=1;i<=n;i++){
        //cout<<c[i]<<" ";
        if(c[i]==j){
            dns++;
            //if(j==2){
                //cout<<i<<" ";
            //}
        }else{
            //cout<<dns<<" dns "<<ans<<" ans "<<i<<endl;
            /*if(dns>ans){
                ans=dns-ans;
            }else{
                ans=ans-dns;
            }*/
            ans=max(ans,dns);
            j=c[i];
            dns=1;
        }
    }
    //cout<<dns<<" dns "<<ans<<" ans "<<endl;
    ans=max(ans,dns);
    cout<<ans;
    return 0;
}
