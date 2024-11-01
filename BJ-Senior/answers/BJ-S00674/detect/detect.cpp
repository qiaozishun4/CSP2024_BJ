#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
const int N=1e6+10;
bool flag;
int t,n,m;
db l,k;
db s[N];
int p[N];
int ans1,ans2;
struct cars{
    int d,v,a;
}car[N];
priority_queue<pair<db,db>,vector<pair<db,db> >,greater<pair<db,db> > > q;
double prel,prer;
pair<db,db> cur;
void check1(db d,db v,db a){
    db dl,dr;
    if(a<0){
        if(v<=k) ans1--;
        else{
            a=-a;
            dl=d;
            dr=d+(v*v-k*k)/(2.0*a);
            int ddr=dr;
            if(ddr==dr) dr--;
            else dr=ddr;
            if(s[(int)dr]-s[(int)dl-1]==0) ans1--;
            else{
                q.push(make_pair(dl,dr));
            }
            //cout<<dl<<' '<<dr<<endl;
        }
    }else if(a>0){
        dl=d+(k*k-v*v)/(2*a);
        dr=l;
        if(dl>dr) ans1--;
        else if(s[(int)dr]-s[(int)dl-1]==0) ans1--;
        else{
            q.push(make_pair(dl,dr));
        }
    }else{
        if(v>k){
            if(s[(int)l]-s[(int)d-1]==0) ans1--;
            else{
                q.push(make_pair(d,l));
            }
        }else{
            ans1--;
            //q.push(make_pair(dl,dr));
        }
    }
}
void check2(){
    cur=q.top();
    q.pop();
    prel=cur.first;
    prer=cur.second;
    while(!q.empty()){
        cur=q.top();
        q.pop();
        if(cur.first>prer){
            ans2++;
            prel=cur.first;
            prer=cur.second;
        }else{
            prel=max(prel,cur.first);
            prer=min(prer,cur.second);
        }
    }
}
void init(){
    ans1=n;
    for(int i=0;i<=l;i++){
        s[i]=0;
    }
    while(!q.empty()) q.pop();
    ans2=1;
    flag=1;
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        cin>>n>>m>>l>>k;
        init();
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&car[i].d,&car[i].v,&car[i].a);
            if(car[i].a!=0) flag=0;
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&p[i]);
            s[p[i]]++;
        }
        for(int i=1;i<=l;i++){
            s[i]+=s[i-1];
        }
        for(int i=1;i<=n;i++){
            check1(car[i].d,car[i].v,car[i].a);
        }
        if(flag){
            if(ans1==0) ans2=0;
            else ans2=1;
        }
        else check2();
        printf("%d %d\n",ans1,m-ans2);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}