#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define sc second
#define fr first
#define mk make_pair
int read(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();return x*f;}
const int MAXN=100010,N=10,MAXM=110;
int n,m,k,a[MAXN],p[MAXN];
int as,ans[MAXN];
void check(int sum){
    if((n-sum)%7||(n-sum)/7+k!=m)return;
    for(int i=1;i<=k;i++){
        if(a[i]==2)p[i]=1;
        if(a[i]==5)p[i]=2;
        if(a[i]==4)p[i]=4;
        if(a[i]==3)p[i]=7;
        if(a[i]==6)p[i]=0;
        if(a[i]==7)p[i]=8;
    }
    sort(p+1,p+k+1);
    for(int i=1;i<=k;i++)if(p[i]){
        if(p[i]==8){
            if(!p[1])p[1]=6;
        }
        else if(p[i]==7){
            if(!p[1])p[1]=6;
        }
        else swap(p[1],p[i]);
        break;
    }
    if(!p[1])p[1]=6;
    if(!as){
        for(int i=1;i<=k;i++)ans[i]=p[i];
        as=1;
        return;
    }
    for(int i=1;i<=k;i++)if(ans[i]>p[i]){
        for(int i=1;i<=k;i++)ans[i]=p[i];
    }
    else if(ans[i]<p[i])break;
}
void dfs(int now,int sum,int mn){
    if(sum>n)return;
    if(now==k+1){
        check(sum);
        return;
    }
    for(int i=2;i<=mn;i++){
        a[now]=i;
        dfs(now+1,sum+i,i);
        a[now]=0;
    }
}
void slv(){
    n=read();
    m=(n-1)/7+1,k=min(m,7ll);
    as=0;
    dfs(1,0,7);
    if(!as)printf("-1\n");
    else{
        for(int i=1;i<=k;i++)printf("%lld",ans[i]);
        for(int i=k+1;i<=m;i++)printf("8");
        printf("\n");
    }
}
signed main(){
    freopen("sticks.in","r",stdin);freopen("sticks.out","w",stdout);
    int _=read();while(_--)
    slv();
    fclose(stdin);fclose(stdout);
    return 0;
}