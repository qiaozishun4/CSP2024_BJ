#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
vector <int> l[N];
int a[N];
int n,k,q,r,c;
void init(){
    for(int i=0;i<N;i++){
        l[i].clear();
        a[i]=0;
    }

}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d%d%d",&n,&k,&q);
        for(int i=0;i<n;i++){
            int len,x;
            cin>>len;
            int flag=0;
            for(int j=0;j<len;j++){
                cin>>x;
                l[i].push_back(x);
                if(flag){
                    a[x]=1;
                    flag--;
                }
                if(x==1)flag=k-1;
            }
        }
        while(q--){
            scanf("%d%d",&r,&c);
            if(r==1){
                if(a[c])printf("1\n");
                else printf("0\n");
                continue;
            }
            printf("0\n");
        }
    }
    return 0;
}
