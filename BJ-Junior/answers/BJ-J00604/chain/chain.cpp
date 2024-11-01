#include <iostream>
#include <vector>
using namespace std;
int T,n,k,q;
vector<int> S[10005];
vector<int> tmp;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&k,&q);
        int l,tmp;
        for(int i = 1; i <= n; i++){
            scanf("%d",&l);
            for(int j = 1; j <= l; j++){
                scanf("%d",&tmp);
                S[i].push_back(tmp);
            }
            //printf("NOWDOING18\n");
        }
        int r,c;
        while(q--){
            scanf("%d%d",&r,&c);
            //printf("NOWDOING22\n");
            if(r == 1){
                int nxt_open = -114514,part_ans = 0;
                for(int i = 1; i <= n; i++){
                    for(int j = 0; j < S[i].size(); j++){
                        if(S[i][j] == 1){
                            nxt_open = j;
                        }
                        if(S[i][j] == c){
                            if(nxt_open != -114514 && j - nxt_open+1 <= k && j >= nxt_open){
                                part_ans = 1;break;
                            }
                        }
                    }
                    if(part_ans == 1){
                        break;
                    }
                }
                if(part_ans){
                    printf("1");
                }else{
                    printf("0");
                }
            }else{
                printf("0");
            }
            printf("\n");
        }
    }
    return 0;
}
/*
xxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxx
          xxxxxxx
        xxxxxxxx
    xxxxxxxxx
  xxxxxxxx   xxx
xxxxxxxx     xxx  xx
            xxx   xxx
            xxx    xxx
            xxx
            xxx
            xxx

xxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxx
                   xx
                   xx
                   xx
       xxxxxxxxx   xx
       x       x   xx
       x       x   xx
       xxxxxxxxx   xx
                   xx
                   xx
                   xx
               xx  xx
                xxxxx

xx       xx       xxx
xx       xx      xxxx
xx        xx      xxx
xx                xxx
xx                xxx
xx                xxx
xx                xxx
xxx               xxx
xx    xx         xxx xxx
xx   xx        xxx    xxx
xx  xx        xxx      xxx
xxxx         xxx       xxx


     xx         xx
      xx       xx
xxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxx
xx                   xx
xx                   xx
xx                   xx
xx                   xx
xx                   xx
xx                   xx
xx                   xx
xxxxxxxxxxxxxxxxxxxxxxx

   x
xx  x      xxxxxx       xx
xx  x                    xx
     x               x    x
     xxxxxxxxxxxxxxxxx


xxxxxxxxxxxxxxxxxxxxxx
                    xx
 xxxxxxxxxxxxxxxx   xx
                    xx
                    xx
  xxxxxxxxxxxxx     xx
   x          x     xx
   x          x     xx
    x         x     xx
   xxxxxxxxxxxx     xx
                    xx
                xx  xx
                 xx xx
                  xxxx



        xxx
    xxxx   xxxx
  xxxx       xxxx
xxxx           xxxx
       xxx
        xxx
    xxxxxxxxxxxx
               xx
       xxx    xx
        xx   xx
            xx
       xx  xx
      xxxxxxx
     x   xx

*/
