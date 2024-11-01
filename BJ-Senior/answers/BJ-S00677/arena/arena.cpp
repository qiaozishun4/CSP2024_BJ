#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1050
#define MAXM 12
#define ls (id<<1)
#define rs (id<<1|1)
int n,m,k,t;
int A[MAXN];
bool q[MAXM][MAXN];
int pw[MAXM];
int x[4];
struct node{
    int val;
    int sum;
    bool operator<(const node &nd)const{
        return val<nd.val;
    }
}a[MAXM][MAXN],c[MAXN];
int work(){
    for(int i=1;i<=k;i++){
        for(int j=1;j<=pw[k-i];j++){
            // printf("a[%d][%d].sum=%d\n",i,j,a[i][j].sum);    
            if(a[i][j].sum)continue;
            if(a[i-1][j*2].val){
                if(a[i-1][j*2+1].val){
                    node e=a[i-1][j*2+q[i][j]];
                    if(e.val>=i){
                        a[i][j]=e;
                    }else{
                        a[i][j]=a[i-1][j*2+(!q[i][j])];
                    }
                }else{
                    if(q[i][j]==1){
                        a[i][j]=(node){0,a[i-1][j*2].sum+a[i-1][j*2+1].sum};
                    }else{
                        if(a[i-1][j*2].val>=i){
                            a[i][j]=a[i-1][j*2];
                        }else{
                            a[i][j]=a[i-1][j*2+1];
                        }
                    }
                }
            }else{
                a[i][j]=(node){0,a[i-1][j*2].sum+a[i-1][j*2+1].sum};
            }
        }
    }
    //cout<<a[k][1].sum<<endl;
    return a[k][1].sum;
}
void init(){
    for(int i=0,pw2=1;i<MAXM;i++){
        pw[i]=pw2;
        pw2*=2;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    for(int i=1;i<=m;i++){
        cin>>c[i].val;
        c[i].sum=i;
    }
    sort(c+1,c+m+1);
    k=log2(n);
    if(pw[k]!=n)k++;
    for(int i=1;i<=k;i++){
        string str;
        cin>>str;
        for(int j=1;j<=pw[k-i];j++)
            q[i][j]=str[j-1];
    }
    cin>>t;
    while(t--){
        ll ans=0;
        memset(a,0,sizeof(a));
        for(int i=0;i<4;i++)
            cin>>x[i];
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++)
                a[0][j].sum=j;
            for(int j=c[i-1].val+1;j<=c[i].val;j++)
                a[0][j].val=A[j]^(x[j%4]);
            // for(int j=1;j<=c[i].val;j++)
            //     cout<<a[0][j].val<<' ';
            // cout<<endl;
            ans=ans^(work()*c[i].sum);
        }
        cout<<ans<<endl;
    }
    return ;
}
int main(){
        freopen("arena.in","r",stdin);
        freopen("arena.out","w",stdout);
    init();
    return 0;
}