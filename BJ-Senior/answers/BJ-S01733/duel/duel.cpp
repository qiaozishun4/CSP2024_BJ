#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int n,r[100005],m[100005],k,l;
long long ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.in","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1,r+n+1);
    k=1;
    l=r[1];
    for (int i=1;i<=n;i++){
        if (r[i]==l){
            m[k]++;
        }
        else{
            k++;
            l=m[i];
        }

    }
    for (int i=2;i<=k;i++){
        if (m[i]>=m[i-1]){
            m[i]=m[i];
            m[i-1]=0;
        }
        else{
            m[i]=m[i-1];
            m[i-1]=0;
        }
    }
    for (int i=1;i<=k;i++){
        ans+=m[i];
    }
    cout<<ans;
    return 0;
}
