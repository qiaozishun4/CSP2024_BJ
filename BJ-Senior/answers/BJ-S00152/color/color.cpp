#include<bits/stdc++.h>
using namespace std;
int T,n;
const int N=200010;
int a[N],pos[1000010],maxn=-1,loc[N],f[N][2];
int calc(int l,int r,int c){
    int sum=0;
    for(int i=l+1;i<=r;i++){
        if(a[i]==a[i-1]) sum+=a[i];
    }
    return sum;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i],maxn=max(maxn,a[i]);
        for(int i=1;i<=maxn;i++) pos[i]=-1;
        for(int i=1;i<=n;i++){
            loc[i]=pos[a[i]];
            pos[a[i]]=i;
        }
        for(int i=1;i<=n;i++) f[i][0]=f[i][1]=0;
        for(int i=1;i<=n;i++){
            int j=loc[i];
            if(j==-1) f[i][0]=f[i][1]=max(f[i-1][0],f[i-1][1]);
            else{
                f[i][0]=f[i][1]=max(f[i-1][0],f[i-1][1]);
                f[i][0]=max(f[i][0],max(f[j-1][0],f[j-1][1])+calc(j+1,i,1)+a[i]);
                f[i][1]=max(f[i][1],max(f[j-1][0],f[j-1][1])+calc(j+1,i,0)+a[i]);
            }
        }
        for(int i=1;i<=n;i++){
            cout<<f[i][0]<<" "<<f[i][1]<<"\n";
        }
        cout<<max(f[n][0],f[n][1]);
    }
    return 0;
}
