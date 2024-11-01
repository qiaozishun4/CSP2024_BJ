#include<bits/stdc++.h>
using namespace std;
long long t,n,a[200010],b[200010],ans,col[200010],st,en;
bool f=true;
int maa(int x){
    int now=b[n-x+1];
    for(int i=n;i>=1;i--){
        if(a[i]==now&&col[i]==0) return i;
    }
    return -1;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) col[i]=0;
        f=true;
        col[n+1]=1;
        col[0]=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        int x=1;
        while(1){
            x++;
            if(x==n+1) break;
            bool f2=false;
            int ma=maa(x);
            if(ma==-1){
                continue;
            }
            for(int i=ma-1;i>=1;i--){
                if(a[i]==a[ma]&&col[i]==0){
                    if(f){
                        col[i]=1;
                        col[ma]=1;
                    }else{
                        col[i]=2;
                        col[ma]=2;
                    }
                    int y=1;
                    if(f) y=2;
                    for(int j=i+1;j<ma;j++){
                        if(col[j]==0) col[j]=y;
                    }
                    f=!f;
                    f2=true;
                    break;
                }
            }
            if(f2) continue;
            f2=false;
            for(int i=ma+1;i<=n;i++){
                if(a[i]==a[ma]){
                    col[ma]=col[i];
                    int y=1;
                    if(col[i]==1) y=2;
                    for(int j=ma+1;j<i;j++){
                        if(col[j]==0) col[j]=y;
                    }
                    f2=true;
                    break;
                }
            }
            if(f2) continue;
            f2=true;
            for(int i=1;i<=n;i++){
                if(col[i]==0){
                    f2=false;
                    break;
                }
            }
            if(f2) break;
            if(x==n) break;
        }
        int st=-1,en=-1;
        for(int i=1;i<=n+1;i++){
            if(col[i]==0&&st==-1) st=i-1;
            if(col[i+1]!=0&&en==-1&&st!=-1) en=i+1;
            if(en!=-1){
                int y=col[st];
                for(int j=st+1;j<en;j++) col[j]=y;
            }
        }
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(col[i]==col[j]){
                    if(a[i]==a[j]) ans+=a[i];
                    else break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
