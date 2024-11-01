#include <stdio.h>
#include <vector>
#include <map>
#include <bitset>
using namespace std;

vector<int> ns;
bitset<100001> color;
inline int max(int a, int b){
    return a>b?a:b;
}
map<int,int> ld;
int pre[100001];
// int nxt[100001];
int dfs(int l){// [l,n)
    if(l>=ns.size()){
        return 0;
    }
    int s, c, bouns = 0;
    // map<int, int> t;
    // register int i;
    // int max1, max2;
    // for(i=l;i<r;i++){
    //     t[ns[i]]+=ns[i];
    // }
    // max1=0;
    // max2=0;
    // for(const pair<int,int>& i:t){
    //     if(i.second>t[max1]){
    //         max2=max1;
    //         max1=i.first;
    //     }else if(i.second>t[max2]){
    //         max2=i.first;
    //     }
    // }
    if(pre[l]!=0){
        c=color[pre[l]-1];
        for(s=l-1;s>=pre[l];s--){
            if(color[s]==c){
                break;
            }
        }
        if(s==pre[l]-1){
            bouns = ns[l];
            // for(int i=0;i<l;i++){
            //     printf("%d ",(int)color[i]);
            // }
            // printf("%d ", pre[l]-1);
            // printf("bouns at %d (%d)\n", l, bouns);
        }
    }else c=0;
    color[l]=c;
    s=dfs(l+1);
    s+=bouns;
    color[l]=1^c;
    return max(s,dfs(l+1));
}
// int dp[100001][2];
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T, n;
    register int i,j,k;
    scanf("%d", &T);
    while(T>0){
        scanf("%d", &n);
        ns.resize(n);
        ld.clear();
        for(i=0;i<n;i++){
            scanf("%d", &ns[i]);
            if(ld[ns[i]]!=0){
                pre[i]=ld[ns[i]]; // i+1
                // nxt[prev[i]]=i;
            }else pre[i]=0;
            // printf("DBG:\tgot: %d\tld: %d\n", ns[i], ld[ns[i]]);
            ld[ns[i]]=i+1;
        }
        // dp[0][0]=0;
        // dp[0][1]=0;
        // for(i=0;i<n;i++){
        //     for(k=0;k<2;k++){
        //         for(j=i-1;j>=0;j--){
        //             if(dp[j][k])
        //         }
        //     }
        // }
        printf("%d\n", dfs(0));

        T--;
    }
    return 0;
}
