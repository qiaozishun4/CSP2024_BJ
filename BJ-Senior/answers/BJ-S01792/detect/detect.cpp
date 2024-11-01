#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,L,V;
struct car{
    double d,v,a;
}c[100005];
struct cs{
    int isc;
    int l,r;
}csc[100005];
double p[100005];
int arr[100005],tong[100005];
bool check(int x,int lf){
    if(x==0){
        for(int i=1;i<=m;i++){
            if(arr[i]==0){
                for(int j=1;j<=n;j++){
                    if(tong[i]==0&&csc[j].l<=i&&i<=csc[j].r){
                        tong[j]=1;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(tong[i]==0)return false;
        }
        return true;
    }
    for(int i=lf+1;i<=m-x+1;i++){
        arr[i]=1;
        return check(x-1,lf+1);
    }
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        int ans1=0,ans2;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int i=1;i<=n;i++){
            int t=lower_bound(p+1,p+1+m,c[i].d)-p;
            if(c[i].a==0){
                if(c[i].v>V){
                    csc[i].isc=1;
                    ans1++;
                    csc[i].l=t;
                    csc[i].r=m;
                }else{
                    csc[i].isc=0;
                }
            } else{
                double s=c[i].d+(V*V-c[i].v*c[i].v)/(double(2*c[i].a));
                if(c[i].a>0){
                    if(s<=p[m]){
                        csc[i].isc=1;
                        ans1++;
                        csc[i].l=lower_bound(p+1,p+1+m,s)-p;
                        csc[i].r=m;
                    }else{
                        csc[i].isc=0;
                    }
                }else{
                    if(s<=c[i].d){
                        csc[i].isc=0;
                    }else{
                        if(p[t]<=s){
                            csc[i].isc=1;
                            ans1++;
                            csc[i].l=t;
                            csc[i].r=lower_bound(p+1,p+1+m,s)-p-1;
                        }else{
                            csc[i].isc=0;
                        }
                    }
                }
            }
        }
        cout<<ans1<<" ";
        int ll=0,rr=m,mm;
        while(ll<rr){
            mm=(ll+rr)/2;
            memset(arr,0,sizeof(arr));
            memset(tong,0,sizeof(tong));
            if(check(mm,0)){
                ll=mm+1;
            }else{
                rr=mm;
            }
        }
        cout<<ll-1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
