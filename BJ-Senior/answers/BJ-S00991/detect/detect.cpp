#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct node{
    int d,v,a;
}che[N];
int n,m,t,L,V;
int ce[N];
bool b[N];
int erfen(int d){
    //int aa=che[i].a,vv=che[i].v,dd=che[i].d;
    int l=1,r=m;
    //cout<<l<<" "<<r<<endl;
    //int k=1;
    while(l<r){
        //k++;
        int mid=(l+r)>>1;
        //cout<<"#"<<mid<<" "<<l<<" "<<r<<" ";
        if(d>ce[mid]) l=mid+1;
        else r=mid;
    }
    return l;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        memset(b,0,sizeof b);
        cin>>n>>m>>L>>V;
        V=V*V;
        int p=0;
        for(int i=1;i<=n;i++){
            //cout<<"1:"<<i<<" ";
            cin>>che[i].d>>che[i].v>>che[i].a;
            if(che[i].a!=0) p=1;
        }
        for(int i=1;i<=m;i++){
            //cout<<"2:"<<i<<" ";
            cin>>ce[i];
        }
        sort(ce+1,ce+1+n);
        //cout<<"!"<<endl;
        int ans1=0,ans2=n;
        //cout<<"!!"<<endl;
        for(int i=1;i<=n;i++){
            //cout<<i<<": ";
            //cout<<che[i].a<<endl;
            if(che[i].a>=0){
                int vx=che[i].v*che[i].v+2*che[i].a*(ce[m]-che[i].d);
                if(vx>V){
                    ans1++;
                    if(!b[m]){
                        b[m]=1;
                        ans2--;
                    }
                }
            }
            if(che[i].a<0){
                int p=erfen(che[i].d);
                int vx=che[i].v*che[i].v+2*che[i].a*(ce[p]-che[i].d);
                if(vx>V){
                    ans1++;
                    if(!b[p]){
                        b[p]=1;
                        ans2--;
                    }
                }
            }
        }
        if(p==0){
            cout<<ans1<<" "<<m-1<<endl;
            continue;
        }
        cout<<ans1<<" "<<ans2<<endl;
    }
    cout.flush();
    return 0;
}