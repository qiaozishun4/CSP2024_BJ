#include<iostream>
#include<vector>
using namespace std;
bool check(std::vector<std::vector<int>>v,int k){
    for(int i=0;i<v.size();i++)for(int j=0;j<v[i].size();j++)if(v[i][j]==k)return 0;
    return 1;
}
void f(std::vector<std::vector<int>>v,int x,int y,int k,bool fl){
    for(int i=0;i<y;i++)if(v[x][i]==1&&y-i<=k){
        fl=1;
        return ;
    }
    bool dx=false;
    for(int i=2;i<=k;i++)if(y-i>=0)for(int j=0;j<v.size();j++){
        f(v,j,y-i,k,dx);
        if(dx){
            fl=1;
            return ;
        }
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n,k,q;
        scanf("%d%d%d",&n,&k,&q);
        std::vector<std::vector<int>>S;
        for(int j=0;j<n;j++){
            int l,d;
            scanf("%d",&l);
            for(int df=0;df<l;df++){
                scanf("%d",&d);
                S[j].push_back(d);
            }
        }
        for(int j=0;j<q;j++){
            int r,c;
            string snw,spr;
            scanf("%d%d",&r,&c);
            if(check(S,c)){
                printf("0");
                break;
            }
            bool fl=false;
            for(int df=0;df<r;df++){
                for(int dg=0;dg<S.size();dg++)for(int dh=0;dh<S[dg].size();dh++){
                    if(S[dg][dh]==c){
                        f(S,dg,dh,k,fl);
                        if(fl)printf("1\n");
                    }
                }
                if(!fl)printf("0");
            }
        }
    }
    return 0;
}