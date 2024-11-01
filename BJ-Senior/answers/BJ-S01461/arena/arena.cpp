#include <bits/stdc++.h>
using namespace std;
#define LL long long

#define N 100007
int n,m,_a[N],c[N],a[N],w[18][N];
char d[18][N];

mt19937 rnd(time(0));

int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr),cout.tie(nullptr);

	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>_a[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    for(int i=1;;i++){
        cin>>d[i];
        if(strlen(d[i])==1) break;
    }
    int T;
    cin>>T;
    while(T--){
        cout<<rnd()*1ll*rnd()%1000000000000<<'\n';
    }

    return 0;
}
