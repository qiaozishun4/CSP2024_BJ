#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T,n,c[N],u[N];
struct node{
    int v,id;
};
node a[N];
bool cmp(node a,node b){
    if(a.v==b.v) return a.id<b.id;
    return a.v<b.v;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].v;
            a[i].id=i;
            c[i]=-1;
            u[i]=a[i].v;
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(a[i].v==a[i-1].v&&a[i].v!=a[i+1].v){
                //cout<<a[i-1].id<<" "<<a[i].id<<endl;
                int s1=0,s0=0;
                for(int j=a[i-1].id+1;j<a[i].id;j++){
                    if(c[j]==1){
                        s1+=u[j];
                    }
                    else if(c[j]==0){
                        s0+=u[j];
                    }
                }
                if(s1>=s0){
                    for(int j=a[i-1].id+1;j<a[i].id;j++){
                        c[j]=1;
                    }
                    c[a[i-1].id]=c[a[i].id]=0;
                }
                else{
                    for(int j=a[i-1].id+1;j<a[i].id;j++){
                        c[j]=0;
                    }
                    c[a[i-1].id]=c[a[i].id]=1;
                }
            }
            
        }int ans=0;
        for(int i=1;i<=n;i++){
            int j=i-1;
            while(c[i]!=c[j]) j--;
            if(u[i]==u[j]) ans+=u[j];
        }
        cout<<ans<<endl;
    }
    return 0;
}