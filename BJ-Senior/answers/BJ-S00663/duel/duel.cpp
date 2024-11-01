#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int N=100000+10;
int a[N],n;

priority_queue<int,vector<int>,greater<int> >que;

void test(){
    cin>>n;for(int i=1;i<=n;i++)cin>>a[i];sort(a+1,a+1+n);
    que.push(a[1]);
    for(int i=2;i<=n;i++){
        if(a[i]>que.top())que.pop();
        que.push(a[i]);
    }
    cout<<que.size();
}

signed main(){
    /****************************************************************************************************************/
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    test();
    return 0;
}
