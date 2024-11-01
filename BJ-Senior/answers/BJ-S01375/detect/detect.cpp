#include<bits/stdc++.h>
using namespace std;
int d[100005],v[100005],aa[100005],p[1000005]={0},x[1000005],a[1000005],b[1000005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t,n,m,l,V,p1,w,s=0,ans=0,f,c=0,flag=0,k=1;
    cin>>t;
    while(t--){
        c=0;
        ans=0;
        scanf("%d%d%d%d",&n,&m,&l,&V);
        for(int i=1;i<=n;i++){
            a[i]=-1;
            b[i]=-1;
        }
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&d[i],&v[i],&aa[i]);
            if(aa[i]>0){
                if(v[i]>V){
                    a[i]=d[i];
                    b[i]=l;
                }
                else {
                    w=(V*V-v[i]*v[i])/aa[i]/2;
                    a[i]=d[i]+w;
                    b[i]=l;
                }
            }
            if(aa[i]==0){
                if(v[i]>V){
                    a[i]=d[i];
                    b[i]=l;
                }
            }
            if(aa[i]<0){
                if(v[i]>V){
                    w=(V*V-v[i]*v[i])/aa[i]/2;
                    a[i]=d[i];
                    b[i]=d[i]+w;
                }
            }
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&p1);
            p[p1]=1;
        }
        for(int i=1;i<=n;i++){
            if(a[i]==-1){
                continue;
            }
            for(int j=a[i];j<=b[i];j++){
                if(p[j]==0){
                    continue;
                }
                if(p[j]==2){
                    a[i]=-1;
                    b[i]=-1;
                    flag=1;
                    continue;
                }
                s++;
                f=j;
                flag=1;
            }
            c+=flag;
            flag=0;
            if(s==1){
                ans++;
                s=0;
                a[i]=-1;
                b[i]=-1;
                p[f]=2;
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]!=-1 && b[i]<a[i+1]){
                ans++;
            }
            else if(a[i]!=-1 && b[i]>a[i+1]){
                for(int j=a[i+1];j<=b[j];j++){
                    if(p[j]==0){
                        ans++;
                        break;
                    }
                }
            }
        }
        cout<<c<<" "<<m-ans<<endl;
    }
    return 0;
}
