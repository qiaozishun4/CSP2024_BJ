#include<bits/stdc++.h>
using namespace std;
#define ls pos<<1
#define rs pos<<1|1
#define int long long
const int N=100010,L=1000010;
int T,n,m,l,V,p[N],a[N],b[N],cnt;
int pl[L],pre[L],lt[N],nx[N];
struct Car{int d,v,A;}c[N];
vector<int>f[N];
int up(int a,int b){
    int ans=a/b;
    if(a%b==0){return ans;}
    return ans+1;
}
int down(int a,int b){int ans=a/b;return ans;}
struct Tree{int x,w,lz;}t[N<<2];
void pushup(int pos){
    if(t[ls].x>t[rs].x){t[pos].x=t[ls].x;t[pos].w=t[ls].w;}
    else{t[pos].x=t[rs].x;t[pos].w=t[rs].w;}
}
void pushdown(int pos,int l,int r){
    if(!t[pos].lz)return;
    t[ls].x+=t[pos].lz;t[ls].lz+=t[pos].lz;
    t[rs].x+=t[pos].lz;t[rs].lz+=t[pos].lz;
    t[pos].lz=0;
}
void update(int pos,int l,int r,int ql,int qr,int k){
    if(l>=ql&&r<=qr){
        t[pos].x+=k;t[pos].lz+=k;
        return;
    }
    pushdown(pos,l,r);
    int mid=(l+r)>>1;
    if(ql<=mid)update(ls,l,mid,ql,qr,k);
    if(qr>mid)update(rs,mid+1,r,ql,qr,k);
    pushup(pos);
}
int query(int pos,int l,int r,int y){
    if(l==r)return t[pos].x;
    pushdown(pos,l,r);
    int mid=(l+r)>>1;
    if(y<=mid)return query(ls,l,mid,y);
    else return query(rs,mid+1,r,y);
}
int slv(){
    for(int i=1;i<=cnt;i++){
        for(int j=a[i];j<=b[i];j++)f[j].push_back(i);
        update(1,1,m,nx[a[i]],lt[b[i]],1);

    }
    int CNT=cnt,ans=0;
    while(CNT>0){
        int pos=t[1].w;ans++;
        CNT-=query(1,1,m,pos);
        for(auto i:f[pos]){
            update(1,1,m,nx[a[i]],lt[b[i]],-1);
        }
    }
    return ans;
}
inline void init(){
    cnt=0;
    for(int i=0;i<=L-5;i++)pl[i]=0;
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;//cout<<T<<endl;
    while(T--){
        bool flag=0;
        cin>>n>>m>>l>>V;
        //cout<<n<<" "<<m<<" "<<l<<" "<<V<<endl;
        l++;
        for(int i=1;i<=n;i++){
            int aa,bb,dd;cin>>aa>>bb>>dd;
            c[i].d=aa;c[i].v=bb;c[i].A=dd;
            //cout<<aa<<" "<<bb<<" "<<dd<<endl;
            //cout<<c[i].d<<" "<<c[i].v<<" "<<c[i].A<<endl;
            c[i].d++;
            if(c[i].A!=0)flag=1;
        }
        //cout<<m<<endl;
        for(int i=1;i<=m;i++){
            cin>>p[i];p[i]++;pl[p[i]]=i;cout<<p[i]<<endl;
        }
        int lst=0;
        for(int i=1;i<=l;i++){
            if(pl[i]>0){lst=i;lt[i]=lst;pre[i]=pre[i-1]+1;}
            else{lt[i]=lst;pre[i]=pre[i-1];}
        }
        //for(int i=1;i<=l;i++)cout<<pl[i]<<" ";
        //cout<<endl;
        //for(int i=1;i<=l;i++)cout<<pre[i]<<" ";
        //cout<<endl;
        int nxt=m+1;
        for(int i=l;i>=1;i--){
            if(pl[i]>0){nxt=i;nx[i]=nxt;}
            else {nx[i]=nxt;}
        }
        for(int i=1;i<=n;i++){
            //cout<<"!"<<i<<" "<<cnt<<endl;
            if(c[i].A==0){
                int s=c[i].d;
                //cout<<s<<endl;
                if(pre[l]-pre[s-1]>0&&c[i].v>V){
                    //cout<<"s;hgdgh;"<<endl;
                   cnt++;
                   a[cnt]=s;b[cnt]=l;
                }
                continue;
            }
            if(c[i].A>0){
                int s=c[i].d;
                if(c[i].v<=V)s+=up((V-c[i].v)*(3*V-c[i].v),c[i].A*2);
                //cout<<s<<endl;
                if(s<=l&&pre[l]-pre[s-1]>0){
                    cnt++;a[cnt]=s;b[cnt]=l;
                    //cout<<i<<" "<<"sd;hg;shklg"<<endl;
                }
            }
            else{
                int s=c[i].d;
                if(c[i].v>V)s+=down((3*c[i].v-V)*(c[i].v-V),2*c[i].A);
                s=min(s,l);
                //cout<<s<<endl;
                if(pre[s]-pre[c[i].d-1]>0){
                    cnt++;a[cnt]=c[i].d;b[cnt]=s;
                    //cout<<i<<"1204611261064"<<endl;
                }
            }
        }
        //cout<<cnt<<" ";
        if(!flag){cout<<1<<endl;}
        else cout<<slv()<<endl;
        fclose(stdin);
        fclose(stdout);
    }
    return 0;
}