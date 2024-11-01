#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int n;
int a[N];
int b[N];
int c[N];

void solve(){
    for(int i=1;i<=n;i++)
        b[a[i]]++;

    int cnt=0;
    for(int i=1;i<=100000;i++)
        if(b[i]!=0)
            c[++cnt]=b[i];

    int maxx=-1;
    for(int i=1;i<=cnt;i++)
        if(c[i]>maxx)
            maxx=c[i];

    cout<<maxx;
}

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    solve();
    return 0;
}