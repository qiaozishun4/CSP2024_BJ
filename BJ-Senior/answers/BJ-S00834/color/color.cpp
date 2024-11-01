#include <iostream>
using namespace std;
int T,n;
int A[200005];
bool color[200005];
int last[2];
long long ans=0,mans=0;
void dfs(int depth) {
    //cout<<ans<<' '<<depth<<' '<<last[true]<<' '<<last[false]<<endl;
    if (depth==n+1) {
        mans=max(ans,mans);
        return;
    }
    int lans=ans,llt=last[true],llf=last[false];
    color[depth]=true;
    if (A[last[true]]==A[depth]) {
        ans+=A[depth];
    }
    last[true]=depth;
    dfs(depth+1);
    ans=lans;
    color[depth]=false;
    last[true]=llt;

    if (A[last[false]]==A[depth]) {
        ans+=A[depth];
    }
    last[false]=depth;
    dfs(depth+1);
    ans=lans;
    last[false]=llf;
}
int main() {
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    A[0]=-0x3f3f3f3f;
    while (T--) {
        last[0]=last[1]=0;
        ans=mans=0;
        cin>>n;
        for (int i=1;i<=n;i++) {
            cin>>A[i];
        }
        dfs(1);
        cout<<mans<<endl;
    }
    return 0;
}
