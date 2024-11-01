#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,d;
int t[N][3],a[N];
int ans=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[a[i]][1]++;
    }
    ans=n;
    for(int i=2;i<=N;i++){
        t[1][2]+=t[i][1];
    }
    for(int i=2;i<=N;i++){
        t[i][2]=t[i-1][2]-t[i][1];
    }
    for(int i=1;i<=N;i++){
        if(t[i][1]>=t[i][2]){
            d=min(t[i-1][2]-t[i-1][1],t[i][2]);
            cout<<i<<"  ";
            cout<<max(t[i][1],d);
            return 0;
        }
        else if(t[i][1]<t[i][2]){
            d=min(t[i][2]-t[i][1],t[i+1][2]);
            t[i][1]=0;
        }
    }
    return 0;
}
