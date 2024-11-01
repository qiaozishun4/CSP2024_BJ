#include<bits/stdc++.h>
using namespace std;

inline void read(int &x){
    int n=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        n=(n<<3)+(n<<1)+(c^48);
        c=getchar();
    }
    x=n*f;
    return;
}

inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar((x%10)|48);
    return;
}

int p[100005],d[100005],a[100005],u[100005];
vector<int>yj[100005],cnt;//cnt 车被记了几次 yj测速仪业绩
int m,n,l,v,ans; //ans 答案一

bool cmp(vector<int>g,vector<int>h){
    return g.size()<h.size();
}

void js(int left,int r,int x){
    for(int i=left;i<=r;++i){
        yj[i].push_back(x);
    }
    return;
}

void mian(){
    memset(p,0,sizeof(p));
    memset(d,0,sizeof(d));
    memset(a,0,sizeof(a));
    memset(u,0,sizeof(u));
    cnt.clear();
    for(int i=0;i<=m;++i){
        yj[i].clear();
    }
    read(n);
    read(m);
    read(l);
    read(v);
    ans=0;
    for(int i=0;i<n;++i){
        int x;
        read(x);
        d[i]=x;
        read(x);
        u[i]=x;
        read(x);
        a[i]=x;
    }
    for(int i=0;i<m;++i){
        int x;
        read(x);
        p[i]=x;
    }
    for(int i=0;i<n;++i){
        if(u[i]>v&&a[i]>=0){
            int y=(lower_bound(p,p+m,d[i])-p);
            if(y!=-1) {cnt.push_back(m-y);ans++;js(y,m-1,i);}
            else cnt.push_back(0);
        }
        else if(u[i]<v&&a[i]<=0){cnt.push_back(0);}
        else if(u[i]>v&&a[i]<0){
            int x=(ceil(1.0*(v*v-u[i]*u[i])/2/a[i])+d[i]);
            int upx=(lower_bound(p,p+m,x)-p),y=(lower_bound(p,p+m,d[i])-p);
            if(upx-y){cnt.push_back(upx-y);ans++;js(y,upx-1,i);}
            else cnt.push_back(0);
        }
        else if(u[i]<v&&a[i]>0){
            int x=(ceil(1.0*(v*v-u[i]*u[i])/2/a[i])+d[i]);
            int y=(lower_bound(p,p+m,x)-p);
            if(y!=-1) {cnt.push_back(m-y);ans++;js(y,m-1,i);}
            else cnt.push_back(0);
        }
    }
    write(ans);
    ans=0;
    sort(yj,yj+m,cmp);
    for(int i=0;i<m;++i){
        bool x=1;
        for(int j=0;j<yj[i].size();++j){
            if(1>=cnt[yj[i][j]]){
                x=0;
                break;
            }
        }
        if(x){
            ans++;
            for(int j=0;j<yj[i].size();++j){
                --cnt[yj[i][j]];
            }
        }
    }
    putchar(' ');
    write(ans);
    putchar('\n');
    return;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    read(T);
    while(T--){
        mian();
    }
    return 0;
}
