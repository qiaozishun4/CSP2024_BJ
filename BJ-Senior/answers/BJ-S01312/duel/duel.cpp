#include<bits/stdc++.h>
using namespace std;
int n,a[100002],ma=-1,mi=100002,cnt;
int b[100002];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[x]++;
        b[x]++;
        ma=max(ma,x);
        mi=min(mi,x);
    }
    for(int k=0;k<ma-mi;k++){
        for(int i=mi;i<ma-k;i++){
                int t=a[i];
            a[i]=max(0,a[i]-b[i+k+1]);
            b[i+k+1]-=t-a[i];
        }
    }
    for(int i=mi;i<=ma;i++) cnt+=a[i];
    cout<<cnt;
    return 0;
}
