#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100],r[100],c[100];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        int maxn=0;
        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=pow(2,n)-1;i>-1;i--){
            int I=i;
            int tot=1;
            while(I){
                if(I&1) r[tot]=1;
                else r[tot]=0;
                I=I>>1;
                tot++;
            }
            int pos=0;
            c[1]=0;
            for(int j=2;j<=n;j++){
                for(int k=j-1;k;k--){
                    if(r[j]==r[k]){
                        pos=k;
                        break;
                    }
                }
                if(a[j]==a[pos]){
                    c[j]=a[j];
                }else c[j]=0;
            }
            int sum=0;
            for(int j=1;j<=n;j++){
                sum+=c[j];
            }
            maxn=max(maxn,sum);
        }
        cout<<maxn<<"\n";
    }
    return 0;
}
