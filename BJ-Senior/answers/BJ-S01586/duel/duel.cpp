#include<bits/stdc++.h>
#define _for(i,x,y) for(int i=x;i<=y;++i)
#define _rep(i,x,y) for(int i=x;i<y;++i)
#define _forp(i,x,y,z) for(int i=x;i<=y;i+=z)
using namespace std;
int n,r[100005];
multiset<int> s;//还可以攻击的
multiset<int> S;//还剩下的
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    _for(i,1,n){
        cin>>r[i];
        s.insert(r[i]);
        S.insert(r[i]);
    }
    int cnt=n;
    while(S.size()>=1){
        int Min=*((S.begin()));
        auto it=s.upper_bound(Min);
        if(it==s.end()){
            break;
        }
        int X=*it;
        cnt--;
        //cout<<Min<<' '<<X<<'\n';
        if(s.find(Min)!=s.end()) s.erase(s.find(Min));
        s.erase(s.find(X));

        S.erase(S.find(Min));
    }
    cout<<cnt<<'\n';
    return 0;
}
