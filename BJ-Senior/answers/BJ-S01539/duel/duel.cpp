#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],k,kk[1000000],c[10000];
int main()

{
    freopen("duel.in","r",stdin);
   freopen("duel.out","w",stdout);
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int t=1;
    kk[1]=1;
    c[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1]){
            t++;
            kk[t]++;
            c[t]++;
        }
        else{
            kk[t]++;
            c[t]++;
        }

    }
 //   for(int i=1;i<=t;i++){
  //      cout<<kk[i]<<' '<<c[i]<<'\n';
//
  //  }
    int s=2;
    for(int i=1;i<=t;i++){
        s=max(s,i+1);
        while(s<=t){
            if(kk[i]>c[s]){
                c[i]-=c[s];
                kk[i]=kk[i]-c[s];
                c[s]=0;
            }
            else{
                kk[i]=0;

                c[s]=c[s]-c[i],c[i]=0;
                break;
            }
            s++;
        }
   //     cout<<kk[i]<<' '<<c[i]<<'\n';
    }
    for(int i=1;i<=t;i++){
        if(kk[i]>=1){
          k+=kk[i];
        }
    }
    cout<<k;
    return 0;
}
