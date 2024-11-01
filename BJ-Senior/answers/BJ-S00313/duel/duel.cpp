#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
typedef long long ll;
int n,r,c[100005],mxr;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r;
        c[r]++;
        mxr=max(mxr,r);
    }
    for(int i=2;i<=mxr;i++){
        n-=min(c[i],c[i-1]);
        c[i-1]=max(0,c[i-1]-c[i]);
        c[i]+=c[i-1];
        //cout<<n<<" "<<c[i]<<endl;
    }
    cout<<n;
    return 0;
}
