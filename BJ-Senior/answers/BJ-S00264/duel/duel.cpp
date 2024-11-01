#include<iostream>
#include<cstdio>

using namespace std;
int n;
int a[101010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    int m=-1;
    for(int i=1;i<=n;i++){
        int p;
        cin >> p;
        a[p]++;
        m=max(m,p);
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        ans=max(a[i],ans);
    }
    cout << ans;
    return 0;
}
