#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
typedef long long ll;
int t,n,k,q,l,r,c;
bool s[100005],e[100005];
vector<int> st[200005];
vector<int> ed[200005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        for(int i=1;i<=200000;i++){
            ed[i].clear();
            st[i].clear();
        }
        scanf("%d %d %d",&n,&k,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&l);
            for(int j=1;j<=l;j++){
                int x;
                scanf("%d",&x);
                if(j>1) ed[x].push_back(i);
                if(j<l) st[x].push_back(i);
            }
        }
        while(q--){
            bool f=false;
            scanf("%lld %lld",&r,&c);
            for(int i=0;i<ed[c].size();i++){
                ll t=ed[c][i]-(r%n)+1;
                for(int j=0;j<st[1].size();j++){
                    if(st[1][j]==t){
                        printf("1\n");
                        f=true;
                        break;
                    }
                }
                if(f) break;
            }
            if(!f) printf("0\n");
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
