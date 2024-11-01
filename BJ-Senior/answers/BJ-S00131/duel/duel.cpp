#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
int c[100300];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        c[x]++;
    }
    int s=0;
    for(int i=1;i<=1e5;i++){
        int t=min(c[i],s);
        s-=t;
        n-=t;
        s+=c[i];
    }
    cout<<n<<endl;

    cout.flush();
    fflush(stdout);
    fclose(stdout);
    return 0;
}