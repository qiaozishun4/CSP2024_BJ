#include<bits/stdc++.h>
using namespace std;
long long n,rr[100005],te[100005],q,ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;ans=n;//cout<<n<<" ";
    for(long long i=1;i<=n;i++){
        long long t=0;
        cin>>t;
        rr[t]++;//cout<<t<<" ";
    }
    for(long long i=1;i<=100005;i++){
        if(rr[i]){q++;
            te[q]=rr[i];

        }
    }
    long long m=0;
    m=te[1];
    for(long long i=2;i<=q;i++){
        if(te[i]>=m){
            ans-=m;
            m=te[i];
        }
        else{
            ans-=te[i];

        }
    }
    cout<<ans;
    return 0;
}