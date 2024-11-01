#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(int a,int b){
    return a<b;
}int T,n,m,L,V,pos[200100],aimtoget,dp[200010],beyondcarcnt;
struct node{
    int d,v,a;
}car[200010];
struct node2{
    int l,r;
}truecar[200010];
bool cmp2(node2 a,node2 b){
    return a.l<b.l;
}int needtodel[200010];
inline int bs_tofindbehind(long double nowpos){
    int l=1,r=m+1,mid;
    while(l<r){
        mid=(l+r)>>1;
        if((long double)pos[mid]<=nowpos){
            l=mid+1;
        }else{
            r=mid;
        }
    }return l;
}inline int bs_tofindfront(long double nowpos){
    int l=0,r=m,mid;
    while(l<r){
        mid=(l+r+1)>>1;
        if((long double)pos[mid]>=(long double)nowpos){
            r=mid-1;
        }else{
            l=mid;
        }
    }return l;
}signed main(){
    ios::sync_with_stdio(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        beyondcarcnt=0;
        //build(1,1,m);
        for(int i=1;i<=n;i++){
            cin>>car[i].d>>car[i].v>>car[i].a;
        }for(int i=1;i<=m;i++){
            cin>>pos[i];
        }sort(pos+1,pos+m+1,cmp);
        pos[m+1]=1e12;
        //cout<<"?\n";
        for(int i=1;i<=n;i++){
            //cout<<i<<' ';
            if(car[i].a==0){
                //cout<<"NO\n";
                if(car[i].v>V){
                    int now=bs_tofindbehind(car[i].d-0.5);
                    if(now!=m+1){
                        beyondcarcnt++;
                        truecar[beyondcarcnt].l=now;
                        truecar[beyondcarcnt].r=m;
                    }
                }
            }else{
                if(car[i].a>0){
                    //cout<<"YES\n";
                    long double begindis=max((long double)(V*V-car[i].v*car[i].v)/(long double)(2*car[i].a),(long double)0);
                    begindis=begindis+(long double)car[i].d;
                    int now=bs_tofindbehind(begindis);
                    if(V<car[i].v) now=bs_tofindbehind(car[i].d-0.5);
                    if(now!=m+1){
                        beyondcarcnt++;
                        truecar[beyondcarcnt].l=now;
                        truecar[beyondcarcnt].r=m;
                    }
                }else{
                    if(car[i].v>V){
                        //cout<<"ISYOU?\n";
                        long double enddis=(long double)(V*V-car[i].v*car[i].v)/(long double)(2*car[i].a);
                        //cout<<enddis+(long double)(car[i].d)<<'\n';
                        int nowr=bs_tofindfront(enddis+(long double)(car[i].d));
                        int nowl=bs_tofindbehind((long double)car[i].d-0.5);
                        //cout<<nowl<<" "<<nowr<<'\n';
                        //cout<<"ISYOU!\n";
                        if(nowr!=m+1&&nowl<=nowr){
                            //cout<<i<<' ';
                            beyondcarcnt++;
                            truecar[beyondcarcnt].l=nowl;
                            truecar[beyondcarcnt].r=nowr;
                        }
                    }
                }
            }
        }cout<<beyondcarcnt<<' ';
        sort(truecar+1,truecar+beyondcarcnt+1,cmp2);
        dp[0]=0;
        aimtoget=0;
        deque<pair<int,int> > q;
        q.push_back(make_pair(0,dp[0]));
        memset(needtodel,0,sizeof(needtodel));
        for(int i=1;i<=beyondcarcnt;i++){
            needtodel[truecar[i].r]=max(needtodel[truecar[i].r],truecar[i].l);
        }for(int i=1;i<=m;i++){
            if(needtodel[i]!=0) aimtoget++;
        }int cnt=0,ans=0;
        for(int i=1;i<=m;i++){
            //cout<<q.front().first<<' '<<q.front().second<<'\n';
            dp[i]=q.front().second+1;
            while(q.size()&&q.back().second>=dp[i]){
                q.pop_back();
            }q.push_back(make_pair(i,dp[i]));
            if(needtodel[i]!=0){
                cnt++;
            }while(q.size()&&q.front().first<needtodel[i]){
                q.pop_front();
            }
        }ans=1e9;
        for(int i=truecar[beyondcarcnt].l;i<=truecar[beyondcarcnt].r;i++){
            ans=min(ans,dp[i]);
        }cout<<m-ans<<'\n';
        // for(int i=1;i<=n;i++){
        //     cout<<dp[i]<<' ';
        // }
    }
    //fclose(stdin);
    //fclose(stdout);
}