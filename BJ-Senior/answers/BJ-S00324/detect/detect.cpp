#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const double eps=1e-8;
pair<int,int> q[100005];
pair<int,int> q2[100005];
int cnt=0;
int pos[100005],dp[100005],st[100005][21],lg[100005];
deque<int> dq;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    lg[1]=0;
    for(int i=2;i<=100000;i++){
        lg[i]=lg[i>>1]+1;
    }
    while(t--){
        memset(st,0x3f,sizeof(st));
        cnt=0;
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        int ok=0;
        for(int i=1;i<=n;i++){
            int d,v,a;
            cin>>d>>v>>a;
            q[i]=make_pair(0,0);
            if(a==0&&v>V){
                q[i]=make_pair(d,L);
                continue;
            }else if(a==0){
                continue;
            }
            double p=d+1.0*(V-v)/a*(v+V)/2;
            if(a<0&&p-d>eps){
                q[i]=make_pair(d,min((int)floor(p-eps),L));
            }else if(a>0&&L-p>eps){
                q[i]=make_pair(max((int)ceil(p+eps),d),L);
            }
        }
        pos[0]=-1;
        for(int i=1;i<=m;i++){
            cin>>pos[i];
            dp[i]=0x3f3f3f3f;
        }
        pos[m+1]=L+1;
        for(int i=1;i<=n;i++){
            q[i]=make_pair(lower_bound(pos,pos+m+2,q[i].first)-pos,upper_bound(pos,pos+m+2,q[i].second)-pos-1);
            if(q[i].first>=1&&q[i].first<=m&&q[i].second>=1&&q[i].second<=m&&q[i].first<=q[i].second){
                q2[++cnt]=q[i];
            }
        }
        sort(q2+1,q2+cnt+1);
        for(int i=1;i<=cnt;i++){
            st[i][0]=q2[i].second;
            assert(q2[i].first<=q2[i].second);
        }
        for(int i=1;i<=20&&(1<<(i-1))<=cnt;i++){
            for(int j=1;j<=cnt;j++){
                st[j][i]=min(st[j][i-1],st[min(j+(1<<(i-1)),cnt-(1<<(i-1)))][i-1]);
            }
        }
        dq.push_back(0);
        dp[0]=0;
        int ans=m;
        if(cnt==0){
            ans=0;
        }
        for(int i=1;i<=m;i++){
            int r=upper_bound(q2+1,q2+cnt+1,make_pair(i,0x3f3f3f3f))-q2;
            while(!dq.empty()){
                int l=upper_bound(q2+1,q2+cnt+1,make_pair(dq.front(),0x3f3f3f3f))-q2;
                if(min(st[l][lg[r-l]],st[r-(1<<lg[r-l])][lg[r-l]])<i){
                    dq.pop_front();
                }else{
                    break;
                }
            }
            if(!dq.empty()){
                dp[i]=dp[dq.front()]+1;
            }else if(q2[1].first==i+1){
                dp[i]=1;
            }else{
                dp[i]=dp[i-1];
            }
            if(q2[cnt].first<=i){
                ans=min(ans,dp[i]);
                break;
            }
            while(!dq.empty()&&dp[dq.back()]>=dp[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        cout<<cnt<<" "<<m-ans<<endl;
        while(!dq.empty()){
            dq.pop_back();
        }
        for(int i=1;i<=m;i++){
            dp[i]=0;
        }
    }
    return 0;
}
