#include<bits/stdc++.h>
using namespace std;
int n,a[500000],cnt,b[500000];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=0;
    }
    sort(1+a,1+n+a);
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]>a[i]&&a[j]>0&&a[i]>0){
                if(b[j]==1) continue;
                a[i]=0;
                b[j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=0) cnt++;
    }
    cout<<cnt;
    return 0;
}
