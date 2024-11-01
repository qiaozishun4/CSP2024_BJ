#include<iostream>
#include<cstdio>
using namespace std;
long long t,n,tn,tm,stp;
long long wx,wy,ansx;
char mp[1005][1005];
struct ct{
    int x,y;
};
ct ans[1000010];
int mx[] = {0,1,0,-1};
int my[] = {1,0,-1,0};
void dfs(long long stp){
    if(stp == 0){
        return ;
    }

    if(wy + my[d] >= 1 &&wy + my[d] <= tm && wx + mx[d] >= 1 &&wx + mx[d] <= tn && mp[wy + my[d]][wy + my[d]] == '.'){
        ans[ansx].x = wx + mx[d];
        ans[ansx++].y = wy + my[d];
        wx = wx + mx[d];
        wy = wy + my[d];
        dfs(stp-1);
    }
    else{
        if(d == 3){
            d = 0;
        }
        else{
            d = d+1;
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%lld",&t);
    for(int i=0;i<t;i++){
        scanf("%lld",&n);
        cin>>tn>>tm>>stp;
        cin>>wx>>wy>>d;
        for(int i=0;i<tn;i++){
            for(int j=0;j<tm;j++){
                cin>>mp[i][j];
            }
        }
        dfs(stp);
        for(i=0;i<ansx;i++){
            cout<<ans[ansx]<<endl;
        }
        ansx = 0;
    }
    return 0;
}
