#include<bits/stdc++.h>
using namespace std;
int T,n,m,l,lim,p[100005],ans1,ans2;
struct TT{
    int d,v,a;
}h[100005];
struct TTT{
    int l,r;
};
struct cmp{
    bool operator()(TTT a,TTT b){
        if(a.l!=b.l){
            return a.l<b.l;
        }
        return a.r<b.r;
    }
};
priority_queue<TTT,vector<TTT>,cmp>now;
bool pp[1000005],yes[1000005];
void init(){
    memset(pp,false,sizeof(pp));
    memset(yes,false,sizeof(yes));
    ans1=ans2=0;
    for(int i=1;i<=n;i++){
        if(h[i].v>lim&&h[i].a>=0){
            now.push(TTT{h[i].d,l});
        }else if(h[i].v<=lim&&h[i].a>0){
            double s=1.0*(lim*lim-h[i].v*h[i].v)/2/h[i].a;
            int s1=s;
            if(s1!=s){
                s1++;
            }
            if(h[i].d+s1<=l){
                now.push(TTT{h[i].d+s1,l});
            }
        }else if(h[i].v>lim&&h[i].a<0){
            double s=1.0*(lim*lim-h[i].v*h[i].v)/2/h[i].a;
            int s1=s;
            if(h[i].d+s1<=l){
                now.push(TTT{h[i].d,h[i].d+s1});
            }else{
                now.push(TTT{h[i].d,l});
            }
        }
    }
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>l>>lim;
        for(int i=1;i<=n;i++){
            cin>>h[i].d>>h[i].v>>h[i].a;
        }
        init();
        for(int i=1;i<=m;i++){
            cin>>p[i];
            pp[p[i]]=true;
        }
        ans1=now.size();
        int last=-1;
        while(!now.empty()){
            TTT h=now.top();
            now.pop();
            if(last<h.l){
                for(int i=h.r;i>=h.l;i--){
                    if(pp[i]==true){
                        last=i;
                        break;
                    }
                }
                if(last<h.l){
                    ans1--;
                }else{
                    if(!yes[last]){
                        ans2++;
                    }
                }
            }else if(last>h.r){
                for(int i=h.l;i<=h.r;i++){
                    if(pp[i]==true){
                        last=i;
                        break;
                    }
                }
                if(last>h.r){
                    ans1--;
                }else{
                    if(!yes[last]){
                        ans2++;
                    }
                }
            }
            if(last!=-1){
                yes[last]=true;
            }
        }
        cout<<ans1<<" "<<m-ans2<<endl;
    }
}
