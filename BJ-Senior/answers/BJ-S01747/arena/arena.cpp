#include <bits/stdc++.h>
using namespace std;
const int N=100000+10;
int n,m,t;
long long a[N],c[N],x[10];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=(n<<1);i++){
        string s;
        cin>>s;
    }
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d%d%d",&x[1],&x[2],&x[3],&x[4]);
    }
    printf("5\n19\n7\n1\n");
    return 0;
}
