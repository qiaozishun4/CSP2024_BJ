#include<iostream>
#include<queue>
#include<algorithm>
typedef long long ll;
using namespace std;
queue<ll> q;
ll a[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++){
        if(!q.empty()&&a[i]>q.front()){
            q.pop();
        }
        q.push(a[i]);
    }
    cout<<q.size()<<endl;
    return 0;
}
