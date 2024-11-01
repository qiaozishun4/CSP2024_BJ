#include <bits/stdc++.h>
using namespace std;
int n,num[100005],a,least=100005,most=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    memset(num,0,sizeof(num));
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a<least) least =a;
        if(a>most) most=a;
        num[a]+=1;
    }
    if(most==least){
        cout<<n;
        return 0;
    }

    int ans=n,w=num[least];
    //cout<<ans<<" ";
    //cout<<least<<" "<<num[least]<<endl;
    for(int i=least+1;i<=most;i++){
        if(num[i]>0){
            int now=num[i]-w;
            if(now<0)
                ans-=num[i];
            else{
                ans-=w;
                w=num[i];
            }
            //cout<<i<<" "<<num[i]<<endl;
        }
    }
    cout<<ans;
    return 0;
}