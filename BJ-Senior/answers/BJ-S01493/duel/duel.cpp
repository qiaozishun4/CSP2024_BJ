#include <bits/stdc++.h>
using namespace std;
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
int mp[200010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>> n;
    fr(i,1,n)cin >> mp[i];
    sort(mp+1,mp+1+n);
    int ans=0,l=1;
    fr(i,2,n){
        if(mp[i]>mp[l])ans++,l++;
    }
    cout << n-ans << endl;
    return 0;
}
