#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=1e5+5;
int t[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        t[x]++;
    }
    int maxx=0;
    for(int i=1;i<N;i++){
        maxx=max(maxx,t[i]);
    }
    cout<<maxx<<'\n';
    return 0;
}
