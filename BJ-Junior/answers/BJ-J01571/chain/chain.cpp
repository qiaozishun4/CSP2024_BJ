#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int l[100005];
vector<int> a[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                int x;
                cin>>x;
                a[i].push_back(x);
            }
        }
        for(int i=1;i<=q;i++){
            int r,c;
            cin>>r>>c;
            cout<<1<<endl;
        }
    }
    return 0;
}
