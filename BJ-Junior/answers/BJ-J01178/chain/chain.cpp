#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,k,q;
struct people{
    int l;
    vector<int>s;
}p[N];
struct have{
    vector<int>pe;
    int ser=0;
}num[N];
int dfs(int r,int c,int last){
    if(!num[c].ser){
        for(int i=1;i<=n;i++){
            for(int j=0;j<p[i].l;j++){
                if(p[i].s[j]==c){
                    num[c].pe.push_back(i);
                    break;
                }
            }
        }
        num[c].ser=1;
    }
    int size1=num[c].pe.size(),ans=0;
    for(int i=0;i<size1;i++){
        int u=num[c].pe[i];
        if(u==last){
            continue;
        }
        for(int j=0;j<p[u].l;j++){
            if(p[u].s[j]==c){
                for(int w=j-1;w>=max(0,j-k+1);w--){
                    if(r==1){
                        if(p[u].s[w]==1){
                            return 1;
                        }
                    }
                    else{
                        ans|=dfs(r-1,p[u].s[w],u);
                    }
                }
            }
        }
    }
    return ans;
}
int main(){
    FILE* f1=freopen("chain.in","r",stdin);
    FILE* f2=freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<N;i++){
            num[i].ser=0;
            num[i].pe.clear();
            p[i].s.clear();
            p[i].l=0;
        }
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&p[i].l);
            for(int j=1;j<=p[i].l;j++){
                int a;
                scanf("%d",&a);
                p[i].s.push_back(a);
            }
        }
        while(q--){
            int r,c;
            scanf("%d%d",&r,&c);
            cout<<dfs(r,c,0)<<endl;
        }
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
