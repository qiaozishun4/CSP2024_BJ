#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n,m,L,V;
int tot;
struct node{
    int l,r;
}hh[100005];
struct hhh{
    int d,v,a;
}a[100005];
int qzh[1000005];
int pos[100005];
bool cmp(node a,node b){
    return a.r<b.r;
}
multiset<int>s;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        memset(qzh,0,sizeof(qzh));
        tot=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].d>>a[i].v>>a[i].a;
        }
        for(int i=1;i<=m;i++){
            cin>>pos[i];
            qzh[pos[i]]=1;
        }
        for(int i=1;i<=L;i++)qzh[i]+=qzh[i-1];
        //for(int i=1;i<=L;i++)cout<<qzh[i]<<" ";
        //cout<<endl;
        for(int i=1;i<=n;i++){
            //    cout<<tot<<"asd"<<endl;
            int d=a[i].d;
            int v=a[i].v;
            int aa=a[i].a;
            if(v>V){
                ++tot;
                hh[tot].l=d;
                if(aa>=0){
                    hh[tot].r=L;
                    //continue;
                }
                else{
                    hh[tot].r=(V*V-v*v+aa*d*2)/2/aa;
//cout<<hh[tot].r<<"sdfg"<<endl;
                    while(v*v+2*aa*(hh[tot].r+1-d)>V*V)hh[tot].r++;
//while()hh[tot].r--;
                    while(v*v+2*aa*(hh[tot].r-d)<=V*V)hh[tot].r--;
                }
               // cout<<d<<" "<<v<<" "<<aa<<" "<<hh[tot].l<<" "<<hh[tot].r<<endl;
                hh[tot].r=min(L,hh[tot].r);
                if(qzh[hh[tot].r]-qzh[hh[tot].l-1]==0)tot--;
            }
            else {
                if(aa<=0)continue;
                ++tot;
                hh[tot].l=(V*V-v*v+2*aa*d)/2/aa;
                while(v*v+aa*(hh[tot].l-1-d)>V*V)hh[tot].l--;
                //while(v+aa*(hh[tot].l-d)<=V)hh[tot].l++;
                while(v*v+aa*(hh[tot].l-d)<=V*V)hh[tot].l++;
                if(hh[tot].l>L){
                    tot--;
                    continue;
                }
                hh[tot].r=L;
                if(qzh[hh[tot].r]-qzh[hh[tot].l-1]==0)tot--;
               // cout<<d<<" "<<v<<" "<<aa<<" "<<hh[tot].l<<" "<<hh[tot].r<<endl;
            }
          //  cout<<tot<<endl;
        }
        cout<<tot<<" ";
        sort(hh+1,hh+tot+1,cmp);
        for(int i=1;i<=m;i++)s.insert(pos[i]);
        int pnt=0;
        for(int i=1;i<=tot;i++){
            int l=hh[i].l;
            int r=hh[i].r;
       //     cout<<l<<" "<<r<<endl;

            if(l>pnt){
                auto it=s.upper_bound(hh[i].r);
                it--;
               // cout<<*it<<endl;
                pnt=*it;
              //  cout<<l<<" "<<r
                s.erase(it);
            }
        }
        cout<<s.size()<<"\n";
        s.clear();
    }
}
