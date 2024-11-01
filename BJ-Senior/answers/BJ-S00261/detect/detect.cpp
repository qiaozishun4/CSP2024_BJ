#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=1e5+5;
ull a[N],d[N],v[N],p[N];
bool f1,f2,f3,k[N],c[N];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m,l,V;
        cin>>n>>m>>l>>V;
        int sum=0,num=0;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]>=0) f1=1;
            else if(a[i]!=0) f2=1;
            else if(a[i]<=0) f3=1;
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        sort(p+1,p+m+1);
        if(f2==0){
            for(int i=1;i<=n;i++){
                if(v[i]>V) sum++;
            }
            cout<<sum<<" "<<m-1<<endl;
        }
        if(f2!=0){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    if((p[i]-d[j])>0){
                        if(sqrt((p[i]-d[j])*2*a[i]+v[i]*v[i])>V&&c[j]==0){
                            sum++;
                            k[i]=1;
                            c[j]=1;
                        }
                    }
                    else{
                        continue;
                    }
                }
            }
            for(int i=1;i<=m;i++){
                cout<<k[i];
            }
            for(int i=1;i<=m;i++){
                if(k[i]==0){
                    num++;
                }
            }
            cout<<sum<<" "<<num;
        }
    }
    return 0;
}
//s*2*a+v0的二次方=v1;
