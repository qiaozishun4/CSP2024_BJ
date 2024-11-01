#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){
        int d[N],v[N],a[N],p[N];
        bool flag[N],flag1[N];
        memset(flag,true,sizeof(flag));
        memset(flag1,false,sizeof(flag1));
        int n,m,L,V,cnt=0,cnt1=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        sort(p+1,p+n+1);
        for(int i=1;i<=n;i++){
            if(v[i]<=V&&a[i]<=0)flag[i]=true;
            else if(v[i]>V&&a[i]==0&&d[i]<p[m])flag[i]=false;
            else if(v[i]>V&&a[i]==0&&d[i]>p[m])flag[i]=true;
            else{
                double c=V*V-v[i]*v[i];
                double o=2*a[i];
                double s=c/o;
                if(a[i]>0){
                    if(p[m]>d[i]+s)flag[i]=false;
                    else flag[i]=true;
                    for(int j=1;j>=m;j++){
                        if(p[j]>d[i])flag1[i]=true;
                    }
                }
                if(a[i]<0){
                    for(int j=1;j<=m;j++){
                        if(p[j]>=d[i]&&p[j]<=d[i]+s){
                            flag[i]=false;
                            break;
                        }
                    }
                    for(int j=1;j<=m;j++){
                        if(p[j]>=d[i]){
                            flag1[i]=true;
                        }
                    }
                }
                // cout<<i<<" "<<s<<endl;
            }
            // if(flag[i]==true)cout<<"true"<<endl;
            // else cout<<"false"<<endl;
        }
        for(int i=1;i<=n;i++){
            if(flag[i]==false)cnt++;
            if(flag1[i]==false)cnt1++;
        }
        cout<<cnt<<" "<<cnt1;
    }
    return 0;
}