#include<bits/stdc++.h>
using namespace std;
int t;
int n,ans;
int a[200005],c[200005],d[200005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ans=0;
        int m=pow(2,n);
        for(int i=0;i<m;i++){
            int j=i,k=1;
            int r=0,b=0,cnt=0;
            while(k<=n){
                if(j&1){
                    if(a[k]==a[r]){
                        cnt+=a[k];
                    }
                    r=k;
                }else{
                    if(a[k]==a[b]){
                        cnt+=a[k];
                    }
                    b=k;
                }
                k++;
                j>>=1;
            }
            ans=max(ans,cnt);
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
