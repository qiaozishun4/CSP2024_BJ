#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m,L,V;
int T;
pair<int,int> cf[N];
int p[N],d[N],v[N],a[N],cnt;
int s[1000005];//[l,r]之间有没有测速仪
int ans;
inline bool cmp(pair<int,int> p1,pair<int,int> p2){
    if(p1.first==p2.first)return p1.second>p2.second;
    return p1.first<p2.first;
}
bool used[N];
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        cnt=ans=0;
        memset(s,0,sizeof s);
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i=1;i<=n;i++)scanf("%d%d%d",&d[i],&v[i],&a[i]);
        for(int i=1;i<=m;i++){
            scanf("%d",&p[i]);
            s[p[i]+1]++;
        }
        for(int i=1;i<=(L+2);i++)s[i]+=s[i-1];
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(v[i]>V){
                    if(s[L+1]-s[d[i]]>0){
                        cnt++;
                        cf[cnt]=make_pair(d[i],L+1);
                    }
                }
            }
            else if(a[i]>0){
                if(v[i]>V){
                    if(s[L+1]-s[d[i]]>0){
                        cnt++;
                        cf[cnt]=make_pair(d[i],L+1);
                    }
                }
                else{
                    long double S=((long long)V*1ll*V-((long long)v[i]*1ll*v[i]))*1.0f/(long double)(2.0*a[i])+d[i];
                    if(S>L)continue;
                    S=ceil(S+0.00000001f);
                    if(S<=L){
                        if(s[L+1]-s[(int)S]>0){
                            cnt++;
                            cf[cnt]=make_pair(S,L+1);
                        }
                    }
                }
            }
            else{
                if(v[i]>V){
                    double S=((long long)V*1ll*V-((long long)v[i]*1ll*v[i]))*1.0f/(2.0*a[i])+d[i];
                    S=floor(S-0.000001f);
                    if(s[min(L,(int)S)+1]-s[d[i]]>0){
                        cnt++;
                        cf[cnt]=make_pair(d[i],min(L,(int)S)+1);
                    }
                }
            }
        }
        printf("%d ",cnt);
        //问题2
        sort(cf+1,cf+1+cnt,cmp);
        priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > q;
        int lst=0,arr=0;
        for(int i=1;i<=cnt;i++){
            // cerr<<cf[i].first<<" "<<cf[i].second<<endl;
            //q:[结束，[开始,编号] ]
            while(q.size() and q.top().second.second<=arr)q.pop();
            if(q.size()){
                int t1=lower_bound(p+1,p+1+m,cf[i].first)-p,t2=upper_bound(p+1,p+1+m,q.top().first-1)-p-1;
                // cerr<<i<<" "<<t1<<" "<<t2<<endl;
                if(t1>t2){
                    lst=t2;
                    // cerr<<i<<":::"<<lst<<" "<<q.top().first<<endl;
                    lst=p[lst];
                    
                    ans++;
                    while(arr<=cnt and cf[arr+1].first<=lst)arr++;
                    // cerr<<arr<<endl;
                }
            }
            q.push(make_pair(cf[i].second,make_pair(cf[i].first,i)));
        }
        if(arr!=cnt)ans++;
        printf("%d\n",m-ans);
        
    }
    return 0;
}