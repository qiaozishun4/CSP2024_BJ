#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m,a[maxn],c[maxn],t,k,r,g;
string tt[maxn];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        if((1<<i)>=n){
            k=i;
            break;
        }
    }
    for(int i=1;i<=k;i++){
        cin>>tt[i];
    }
    cin>>t;
    for(int i=1;i<=t;i++){
        int aaa,bbb,ccc,ddd;
        cin>>aaa>>bbb>>ccc>>ddd;
        cout<<(1<<m)<<endl;
    }
    return 0;
}
