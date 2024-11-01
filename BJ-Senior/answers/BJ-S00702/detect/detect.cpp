#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct stu{
    long long d;
    long long a;
    long long v;
}x[1000050];
long long n,m,l,v;
long long mth(stu a,int l){
    //if(a.v>v)return v+1;
    double qwq=2.0*(double)a.a*((double)l-(double)a.d);
    //cout<<qwq<<endl;
    if(qwq>v+1000)return v+1;
    return a.v+2*a.a*(l-a.d);
}
int p[1000050];
int nxt[1000050];
vector<int>ln;
vector<pair<int,int>>pr;
bool cmp(pair<int,int>x,pair<int,int>y){
    return x.second<y.second;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;cin>>t;while(t--){
        cin>>n>>m>>l>>v;
        v*=v;
        ln.clear();
        pr.clear();
        for(int i=1;i<=n;i++){
            cin>>x[i].d>>x[i].v>>x[i].a;
            x[i].v*=x[i].v;
        }
        for(int i=0;i<=l+1;i++){
            nxt[i]=-1;
        }
        int mx=0;
        for(int i=1;i<=m;i++){
            cin>>p[i];
            mx=max(p[i],mx);
            nxt[p[i]]=p[i];
        }
        for(int i=l;i>=0;i--){
            if(nxt[i]==-1)nxt[i]=nxt[i+1];
        }
        for(int i=1;i<=n;i++){
            if(x[i].d>mx){
                continue;
            }
            if(x[i].a>=0){
                if(mth(x[i],mx)>v){
                    //cout<<i<<endl;
                    ln.push_back(i);
                    if(x[i].a==0)pr.push_back(make_pair(x[i].d,l));
                    else pr.push_back(make_pair(x[i].d+(-x[i].v+v)/(2*x[i].a)+1,l));
                }
            }else{
                if(mth(x[i],nxt[x[i].d])>v){
                    //cout<<i<<endl;
                    ln.push_back(i);
                    if(((v-x[i].v)%(2*x[i].a))==0)pr.push_back(make_pair(x[i].d,min(l,x[i].d+(-x[i].v+v)/(2*x[i].a)-1)));
                    else pr.push_back( make_pair(x[i].d,
                                                 min(l,x[i].d+(-x[i].v+v)/(2*x[i].a) )));
                }
            }
        }
        cout<<ln.size()<<" ";
        //for(auto x:pr)cout<<x.second<<endl;
        sort(pr.begin(),pr.end(),cmp);
        for(int i=0;i<=l+1;i++){
            nxt[i]=-1;
        }
        for(int i=1;i<=m;i++)nxt[p[i]]=p[i];
        for(int i=1;i<=l;i++){
            if(nxt[i]==-1)nxt[i]=nxt[i-1];
            //cout<<nxt[i]<<"/";
        }
        int lst=-1;
        int ans=0;
        for(auto x:pr){
            //cout<<x.first<<","<<x.second<<endl;
            //cout<<lst<<"?";
            if(lst>=x.first)continue;
            else{
                ans++;
                lst=nxt[x.second];
                if(lst==-1)cout<<"error"<<endl;
            }
        }
        cout<<m-ans<<endl;
    }
}
