#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int t;
int n,m,l,v;
struct node{
    int d,v,a;
    int f;
    double ps,pe;
}a[N];
int p[N];
vector<int> g[N];
int k,mi;
int f[N];

void afo(int x){
    if(a[x].a==0){
        if(a[x].v<=v){
            a[x].f=0;
        }else{
            a[x].f=3;
            a[x].ps=a[x].d;
            a[x].pe=l;
        }
        return;
    }else if(a[x].a>0){
        a[x].f=1;
        a[x].ps=a[x].d+1.0*(v*v-a[x].v*a[x].v)/(2*a[x].a);
        a[x].ps+=0.00001;
        a[x].pe=l;
    }else{
        if(a[x].v<=v){
            a[x].f=0;
            return;
        }else{
            a[x].f=2;
            a[x].ps=a[x].d;
            a[x].pe=a[x].d+1.0*(v*v-a[x].v*a[x].v)/(2*a[x].a);
            a[x].pe-=0.00001;
        }
    }
}

/*
void fn1(int x){
    int left=1,right=m;
    while(left<=right){
        int mid=left+right>>1;
        if(a[x].ps<=p[mid]){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    for(int i=left-1;i<=m;i++){
        g[i].push_back(x);
    }
}
void fn2(int x){
    int left=1,right=m;
    while(left<=right){
        int mid=left+right>>1;
        if(a[x].ps<=p[mid]){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    for(int i=left-1;i<=m;i++){
        if(a[x].ps==p[1]) continue;
        g[i].push_back(x);
    }
}

void fn3(int x){
    int left=1,right=m;
    while(left<=right){
        int mid=left+right>>1;
        if(a[x].ps<=p[mid]){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    int a1=left-1;
    left=1,right=m;
    while(left<=right){
        int mid=left+right>>1;
        if(a[x].pe<=p[mid]){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    int b1=left;
    for(int i=a1;i<=b1;i++){
        g[i].push_back(x);
    }
}
*/

void dfs(int x,int gs,int over){
    for(int j=0;j<g[x].size();j++){
        if(!f[g[x][j]]) over++;
        f[g[x][j]]++;
    }
    if(over>=k){
        mi=min(mi,gs);
        for(int j=0;j<g[x].size();j++){
            f[g[x][j]]--;
        }
        return;
    }

/*
    for(int i=1;i<=m;i++){
        cout<<f[i]<<' ';
    }
    cout<<endl;
*/


    for(int i=x+1;i<=m;i++){
        dfs(i,gs+1,over);
    }
    for(int j=0;j<g[x].size();j++){
        f[g[x][j]]--;
    }
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&m,&l,&v);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].d,&a[i].v,&a[i].a);
            afo(i);
        }
        for(int i=1;i<=m;i++){
            scanf("%d",p+i);
        }
        k=0;
        for(int i=1;i<=n;i++){
            char c=true;
            if(a[i].f==0) continue;
            for(int j=1;j<=m;j++){
                if(p[j]>=a[i].ps&&p[j]<=a[i].pe){
                    if(c){
                        c=false;
                        k++;
                    }
                    g[j].push_back(i);
                }
            }
        }
/*
        for(int i=1;i<=n;i++){
            for(int j=0;j<g[i].size();j++){
                cout<<g[i][j]<<' ';
            }
            cout<<endl;
        }
*/
        mi=INT_MAX;
        for(int i=1;i<=n;i++){
            if(!g[i].size()) continue;
            dfs(i,1,0);
            memset(f,0,sizeof(f));
        }

        cout<<k<<' '<<m-mi<<endl;
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        for(int i=1;i<=m;i++){
            g[i].clear();
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
