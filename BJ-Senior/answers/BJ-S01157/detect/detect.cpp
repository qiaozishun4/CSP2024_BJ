#include<bits/stdc++.h>
using namespace std;
int d[100005],v[100005],a[100005],det[100005],maxs[100005],last[100005],mins=1e9;
bool vis[100005];
bool chk(int x,int y,int lim,int dis){
    int tmp=x*x+2*y*dis;
    if(lim*lim<tmp){
        return 1;
    }
    return 0;
}
struct node{
    int d,v,a;
}car[100005];
bool cmp(node A,node B){
    return A.d<B.d;
}
bool box[100005];
void dfs(int cur,int n,int m,int V,int lim){
    if(cur>m){
        int cnt=0;
        for(int i=1;i<=n;i++){
            bool flag=0;
            for(int j=1;j<=m;j++){
                if(!box[j]){
                    continue;
                }
                if(det[j]>=d[i]&&chk(v[i],a[i],V,det[j]-d[i])){
                    flag=1;
                    break;
                }
            }
            if(flag){
                cnt++;
            }
        }
        if(cnt!=lim){
            return ;
        }
        cnt=0;
        for(int i=1;i<=m;i++){
            if(box[i]){
                cnt++;
            }
        }
        mins=min(mins,cnt);
        return ;
    }
    box[cur]=1;
    dfs(cur+1,n,m,V,lim);
    box[cur]=0;
    dfs(cur+1,n,m,V,lim);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        bool f=1,f2=1,f3=1;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]!=0){
                f=0;
            }
            if(a[i]<=0){
                f2=0;
            }
            if(a[i]>=0){
                f3=0;
            }
        }
        for(int i=1;i<=m;i++){
            cin>>det[i];
        }
        if(f){
            sort(det+1,det+m+1);
            int ans=0;
            for(int i=1;i<=n;i++){
                if(v[i]>V&&d[i]<=det[m]){
                    ans++;
                }
            }
            if(ans==0){
                cout<<ans<<" "<<m<<endl;
            }
            else{
                cout<<ans<<" "<<m-1<<endl;
            }
            continue;
        }
        if(f2){
            sort(det+1,det+m+1);
            int ans=0;
            for(int i=1;i<=n;i++){
                if(d[i]<=det[m]&&chk(v[i],a[i],V,det[m]-d[i])){
                    ans++;
                }
            }
            if(ans==0){
                cout<<ans<<" "<<m<<endl;
            }
            else{
                cout<<ans<<" "<<m-1<<endl;
            }
            continue;
        }
        if(f3){
            sort(det+1,det+m+1);
            for(int i=1;i<=n;i++){
                car[i].d=d[i];
                car[i].v=v[i];
                car[i].a=a[i];
            }
            sort(car+1,car+n+1,cmp);
            int j=1;
            int ans=0;
            memset(vis,0,sizeof(vis));
            for(int i=1;i<=n;i++){
                while(j<=m&&det[j]<car[i].d){
                    j++;
                }
                if(j<=m&&chk(car[i].v,car[i].a,V,det[j]-car[i].d)){
                    ans++;
                    vis[i]=1;
                }
            }
            cout<<ans<<" ";
            j=1;
            for(int i=1;i<=n;i++){
                if(!vis[i]){
                    continue;
                }
                while(j<=m&&det[j]<car[i].d){
                    j++;
                }
                last[i]=det[j];
                int l=j,r=m,loc;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(chk(car[i].v,car[i].a,V,det[mid]-car[i].d)){
                        l=mid+1;
                        loc=mid;
                    }
                    else{
                        r=mid-1;
                    }
                }
                maxs[i]=det[loc];
            }
            int last2=1e9;
            ans=0;
            for(int i=n;i>=1;i--){
                if(!vis[i]){
                    continue;
                }
                if(last2<=maxs[i]){
                    continue;
                }
                ans++;
                last2=last[i];
            }
            cout<<m-ans<<endl;
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            bool flag=0;
            for(int j=1;j<=m;j++){
                if(det[j]>=d[i]&&chk(v[i],a[i],V,det[j]-d[i])){
                    flag=1;
                    break;
                }
            }
            if(flag){
                ans++;
            }
        }
        cout<<ans<<" ";
        dfs(1,n,m,V,ans);
        cout<<m-mins<<endl;
    }
    return 0;
}

