#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=1e6+5;
int n,m,L,V,T,a[N],d[N],v[N],p[N],all[M],arr[M],st[N],lt[N],safe[N];
vector <int> cars[N],charts[N];
double endd[N];
struct node{
    int id,num;
}sz[N];
bool cmp(node x,node y){
    return x.num>y.num;
}
bool check(double first,double last,int t){//[first,last)
    if(first>last) return false;
    int s1=max(ceil(first),ceil(d[t])),s2=min(floor(last),floor(endd[t]));
    if(2*a[t]*(s1-d[t])==V*V-v[t]*v[t]) s1++;
    if(2*a[t]*(s2-d[t])==V*V-v[t]*v[t]) s2--;
    st[t]=s1,lt[t]=s2;
       // cout<<endd[t]<<' '<<s1<<' '<<s2<<' '<<first<<' '<<last<<' '<<arr[s2]<<' '<<arr[s1-1]<<endl;
    if(arr[s2]-arr[s1-1]) return true;
    else return false;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        memset(safe,0,sizeof(safe));
        int ans=0;
        for(int i=1;i<=m;i++) all[p[i]]=0;
        for(int i=1;i<=L;i++) arr[i]=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]>=0) endd[i]=double(L);
            else{
                endd[i]=double(d[i])+double(double(-v[i]*v[i])/double(2*a[i]));
                if(endd[i]>double(L)) endd[i]=double(L);
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
            all[p[i]]=1;
        }
        for(int i=1;i<=L;i++){
            arr[i]=arr[i-1]+all[i];
        }
        for(int i=1;i<=n;i++){
            if(a[i]>0){
                if(v[i]>V) ans+=check(double(d[i]),endd[i],i);
                else ans+=check(double(d[i])+double(double(V*V-v[i]*v[i])/double(2*a[i])),endd[i],i);
            }
            else if(a[i]<0){
                if(v[i]>V){
               // cout<<i<<' '<<check(double(d[i]),double(d[i])+double(double(V*V-v[i]*v[i])/double(2*a[i])),i)<<endl;
                ans+=check(double(d[i]),double(d[i])+double(double(V*V-v[i]*v[i])/double(2*a[i])),i);
                }
            }
            else{
                if(v[i]>V) ans+=check(double(d[i]),endd[i],i);
            }
        }
        cout<<ans<<' ';
        int tmp=0;
        for(int j=1;j<=m;j++){
            sz[j].id=j,sz[j].num=0;
            for(int i=1;i<=n;i++){
                if(p[j]>=st[i]&&p[j]<=lt[i]){
                    sz[j].num++;
                    charts[j].push_back(i);
                }
            }
        }
        sort(sz+1,sz+m+1,cmp);
        for(int i=1;i<=m;i++){
            bool flag=0;
            for(int j=0;j<sz[i].num;j++){
                if(!safe[charts[i][j]]){
                    flag=1;
                    safe[charts[i][j]]=1;
                }
            }
            if(!flag) tmp++;
        }
        cout<<tmp<<endl;
    }
    return 0;
}