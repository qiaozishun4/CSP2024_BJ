#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int s[N],t[N],k[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k[i];
    }
    sort(k+1,k+1+n);
    for(int i=1;i<=n;i++){
        if(k[i]!=k[i-1]){
            cnt++;
        }
        s[i]=cnt;
        t[cnt]++;
    }
    int p=n;
    for(int i=1;i<cnt;i++){
        p-=min(t[i+1],t[i]);
    }
    cout<<p;
    return 0;
}
