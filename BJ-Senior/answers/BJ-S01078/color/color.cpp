#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int c[N];
int n;
int s[N];
long long cnt;
int dfs(int k){
    if(k>1){
        for(int i=0;i<=1;i++){
            s[k]=i;
            dfs(k-1);
        }
    }else{
        for(int i=0;i<=1;i++){
            s[k]=i;
            for(int j=1;j<=n;j++){
                int o=1;
                for(int l=j-1;l>0;l--){
                    if(s[l]==s[j]){
                        o=0;
                    }else{
                        if(a[l]==a[j]){
                            c[j]=a[j];
                        }else{
                            c[j]=0;
                        }
                        break;
                    }
                }
                if(o==0){
                    c[j]=0;
                    break;
                }
            }
            long long sum=0;
            for(int j=1;j<=n;j++){
                sum+=c[j];
            }
            cnt=max(cnt,sum);
        }
    }
    return 0;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(n);
        cout<<cnt;
    }
    return 0;
}