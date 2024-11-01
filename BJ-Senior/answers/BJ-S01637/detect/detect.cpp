/* Copyright 2022-2024  getfa(R) industries.
 * All Rights Reserved.
 *
 * See license in my(01999) code of CSP-J 2024 Problem 3&4
 */

#include <bits/stdc++.h>
#define int long long
using namespace std;
int d[1000005],v[1000005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,l,V;
        cin>>n>>m>>l>>V;
        for(int i=0;i<n;++i){
            int t;
            cin>>d[i]>>v[i]>>t;
        }
        int maxp=0;
        for(int i=0;i<m;++i){
            int t;
            cin>>t;
            maxp=max(maxp,t);
        }
        int ans=0;
        for(int i=0;i<n;++i)if(d[i]<=maxp&&v[i]>V)ans++;
        if(ans!=0)cout<<ans<<" "<<m-1<<"\n";
        else cout<<"0 "<<m<<"\n";
    }
    return 0;
}