#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
// HF#24THMC Z*L#LH%9
int r[N];
int n;
int ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans=n;
    for(int i=1;i<=n;++i){
        cin>>r[i];
    }
    sort(r+1,r+n+1);
    int j=1;
    for(int i=1;i<=n;++i){
        while(r[j]<=r[i]&&j<=n) ++j;
        if(j<=n){
            j++;
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
