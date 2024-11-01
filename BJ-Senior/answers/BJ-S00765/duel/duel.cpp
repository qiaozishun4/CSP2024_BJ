#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=1e5+7;
queue<int>q;
int a[N],n;
main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    rep(i,n)cin>>a[i];
    sort(a+1,a+1+n);
    rep(i,n){
        if(q.empty()){
            q.push(a[i]);continue;
        }
        if(q.front()<a[i])q.pop(),q.push(a[i]);
        else q.push(a[i]);
    }
    cout<<q.size();
    return 0;
}