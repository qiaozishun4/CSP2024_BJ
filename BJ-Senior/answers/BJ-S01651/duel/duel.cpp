#include<bits/stdc++.h>
using namespace std;
int r[100000];
int v[100000];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,ans=0; cin >> n;
    for(int i=1;i<=n;i++) cin >> r[i];
    for(int i=1;i<=n;i++) v[i]=0;
    for(int i=1;i<=n;i++){
        sort(v+1,v+ans+1);
        for(int j=1;j<=n;j++){
            if(i-j>=0) v[i]=v[i]+r[i]-r[j];
            else       v[i]=0;
        }cout << v[i] <<  ' ';
        cout  << endl;
        if(v[i]==0) ans++;
        for(int j=1;j<=ans;j++) v[j-1]=v[j];
        sort(v+1,v+ans+1);
        v[2]=0;
    }cout << n-ans+1;
}