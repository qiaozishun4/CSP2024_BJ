#include<bits/stdc++.h>
using namespace std;
int num[100010];
int s[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int ai;
        cin>>ai;
        num[ai]++;
    }
    for(int i=1;i<=100000;i++){
        s[i]=s[i-1]+num[i];
    }
    int deled=0;
    for(int i=2;i<=100000;i++){
        assert(s[i-1]-deled>=0);
        deled+=min(num[i],s[i-1]-deled);
    }cout<<n-deled;
    return 0;
}
