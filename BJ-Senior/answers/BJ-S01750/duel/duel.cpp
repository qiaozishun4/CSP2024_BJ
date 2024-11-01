#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N];
queue <int> q;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        q.push(a[i]);
    }
    sort(v+1,v+n+1);
    long long ans=n,o=1,cnt=1;
    for(int i=1;i<=n;i++){
        
        if(a[o]!=a[i]){
            cnt--;
            o++;
            ans--;
    }
    }
    cout<<ans;
    return 0;
}
