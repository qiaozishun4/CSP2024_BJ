#include <bits/stdc++.h>

using namespace std;

struct car{
    int d,v,a;
} c[100005];
int dect[100005];
pair<int,int> seg[100005];
queue<int> type1;

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,l,V;
        cin>>n>>m>>l>>V;
        int cnt=0;
        int ccar=0;
        for(int i=0;i<n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
        }
        for(int i=0;i<m;i++){
            cin>>dect[i];
        }
        for(int i=0;i<n;i++){
            if(c[i].d>dect[m-1])continue;
            if(c[i].a==0){
                if(c[i].v>V){
                    type1.push(i);
                    ccar++;
                }
                continue;
            }
            if(c[i].a>0){
                if(1ll*c[i].v*c[i].v+2ll*c[i].a*(dect[m-1]-c[i].d)>1ll*V*V){
                    type1.push(i);
                    ccar++;
                }
                continue;
            }
            if(c[i].v<=V)continue;
            int w1=lower_bound(dect,dect+m,c[i].d)-dect;
            if(1ll*c[i].v*c[i].v+2ll*c[i].a*(dect[w1]-c[i].d)<=1ll*V*V)continue;
            ccar++;
            int w2=lower_bound(dect,dect+m,c[i].d+(V*V-c[i].v*c[i].v)/2/c[i].a)-dect-1;
            seg[cnt++]=make_pair(w2,w1);
        }
        cout<<ccar<<" ";
        int lst=-1;
        int ans=0;
        sort(seg,seg+cnt);
        for(int i=0;i<cnt;i++){
            if(seg[i].second<=lst&&lst<=seg[i].first){
                continue;
            }
            lst=seg[i].first;
            ans++;
        }
        if(lst==-1){
            cout<<m-1<<endl;
            continue;
        }
        bool flag=false;
        while(!type1.empty()){
            int i=type1.front();
            type1.pop();
            if(dect[lst]<c[i].d||1ll*c[i].v*c[i].v+2ll*c[i].a*(dect[lst]-c[i].d)<=1ll*V*V){
                flag=true;
                break;
            }
        }
        if(flag)ans++;
        cout<<m-ans<<endl;
    }
    return 0;
}
