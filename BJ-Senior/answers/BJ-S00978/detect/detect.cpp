#include<bits/stdc++.h>
#define N 1000001
#define int long long
using namespace std;
map<int,int>mp;
struct car{
    int d,v,a,fa;
    int l,r;
    int isfast;
}c[N];
int cmp(car x,car y){
    return x.l<y.l;
}
int fast(int d,int v,int v0,int a){
    return d+ceil(((double)v*(double)v-(double)v0*(double)v0)/(2.0*double(a)));
}
int fast2(int d,int v,int v0,int a){
    return d+floor(((double)v*(double)v-(double)v0*(double)v0)/(2.0*double(a)));
}
int detecher[N];
int find1(int x,int n){
    int l=0,r=n,mid;
    while(l<r){
        mid=(l+r+1)>>1;
        if(detecher[mid]>x){
            r=mid-1;
        }
        else{
            l=mid;
        }
    }
    return l;
}
int ans1=0,ans2=0;
struct decatch{
    vector<int>cars;
    int realNum,num;
}d[N];
signed main(){
    FILE* f1=freopen("detect.in","r",stdin);
    FILE* f2=freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        ans1=ans2=0;
        int n,m,l,v;
        cin>>n>>m>>l>>v;
        for(int i=0;i<N;i++){
            d[i].realNum=d[i].num=0;
            d[i].cars.clear();
            c[i].d=c[i].v=c[i].a=c[i].l=c[i].r=c[i].fa=0;
        }
        for(int i=1;i<=n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
        }
        for(int i=1;i<=m;i++){
            cin>>detecher[i];
        }
        for(int i=1;i<=n;i++){
            if(c[i].a==0){
                if(c[i].v>v){
                    c[i].fa=detecher[m];
                }
                else{
                    c[i].fa=l+1;
                }
            }
            else if(c[i].a>0){
                c[i].fa=fast(c[i].d,v,c[i].v,c[i].a);
            }
            else{
                c[i].fa=fast2(c[i].d,v,c[i].v,c[i].a);
            }
            if((c[i].a>=0&&c[i].fa>detecher[m])||(c[i].a<0&&c[i].fa<c[i].d)){
                c[i].isfast=0;
                continue;
            }
            if(c[i].a<0&&c[i].fa>detecher[m]){
                c[i].fa=detecher[m];
            }
            c[i].isfast=1;
            if(c[i].a>=0){
                c[i].l=find1(c[i].fa,m);
                c[i].r=m;
            }
            else{
                int y=find1(c[i].d,m);
                if(detecher[y]==c[i].d){
                    c[i].l=y;
                }
                else{
                    c[i].l=y+1;
                }
                c[i].r=find1(c[i].fa,m);
            }
        }
        for(int i=1;i<=m;i++){
            d[i].realNum=detecher[i];
            d[i].num=i;
            mp[detecher[i]]=i;
        }
        sort(c+1,c+1+n,cmp);
        for(int i=1;i<=n;i++){
            if(c[i].isfast){
                if(c[i].r-c[i].l>=0){
                    ans1++;
                    d[c[i].l].cars.push_back(i);
                    d[c[i].r].cars.push_back(i+n);
                }
            }
        }
        int lianxu=0,lianxucars=0,starting=1;
        for(int i=1;i<=m;i++){
            if(!d[i].cars.empty()){
                ans2++;
                lianxu=1;
                starting=i;
                break;
            }
        }
        for(int i=starting+1;i<=m;i++){
            if(d[i].cars.empty()){
                continue;
            }
            int yes=0;
            for(int j=0;j<d[i].cars.size();j++){
                if(d[i].cars[j]<=n){
                    yes=1;
                    break;
                }
            }
            if(!yes){
                lianxu=0;
            }
            else{
                if(!lianxu){
                    ans2++;
                }
            }
        }
        cout<<ans1<<' '<<m-ans2<<endl;
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
