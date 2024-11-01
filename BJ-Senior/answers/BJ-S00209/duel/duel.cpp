#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
#define int long long
const int maxn=1e5+10,inf=1e17;
int n,a[maxn];
multiset<int>st,ans;
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    // cout<<a[i]<<'\n';
        st.insert(a[i]);
    }
    while(st.size()){
        auto itr=st.begin();
        int cnt=0;
        while(itr!=st.end()){
            int x=*itr;
            st.erase(itr);
            itr=st.upper_bound(x);
            if(itr==st.end()){
                ans.insert(x);
            }
            cnt++;
        }
    }
    cout<<ans.size()<<'\n';
}
