#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){int x=0,f=1;char c=getchar();while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();};while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();return x*f;}
const int MAXN=100010;
int n,a[MAXN];
void slv(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    int lst=0,num=0;
    for(int i=1;i<=n;i++){
        if(i==n||a[i]!=a[i+1]){
            int sum=i-lst;
            if(sum>num)num=sum;
            lst=i;
        }
    }
    printf("%lld",num);
}
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}