#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
map<int,int> m;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        m[tmp]++;
        ans=max(ans,m[tmp]);
    }
    cout<<ans<<endl;
    return 0;
}
