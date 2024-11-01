#include <bits/stdc++.h>
using namespace std;
long long n;
vector<int> v;
queue<int> q;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    v.resize(n,0);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    long long t=1;
    if(n)q.push(v[0]);
    long long ans=1;
    while(t<n){
        if(v[t]>q.front()){
            q.pop();
            ans--;
        }
        q.push(v[t]);
        t++;
        ans++;
    }
    cout<<ans<<'\n';
    return 0;
}
