#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,sum;
char maap[1000][1000];
  int main(){
  freopen("explore.in","r",stdin);
  freopen("explore.out","w",stdout);
  scanf("%d",&t);
  for(int i = 0;i < t;i++){
      scanf("%d %d %d",&n,&m,&k);
      //printf("%d %d %d\n",n,m,k);
      scanf("%d %d %d",&x,&y,&d);
      //printf("%d %d %d\n",x,y,d);
      sum = 1;
      maap[1000][1000] = {};
      for(int j = 1;j <= n;j++)
        for(int uu = 1;uu <= m + 1;uu++) scanf("%c",&maap[j][uu]);
      /*printf("%d\n",i);*/
      for(int wx = 0;wx < k;wx++){
          //printf("%d %d %d\n",x,y,d);
          if(d == 0){
            if(maap[x][y + 1] == '.' && 1 <= x && x <= n && 1 <= y + 1 && y + 1 <= m){
                y += 1;
                sum++;
            }else{
                d = (d + 1) % 4;
                continue;
            }
          }else if(d == 1){
            if(maap[x + 1][y] == '.' && 1 <= x + 1 && x + 1 <= n && 1 <= y && y <= m){
                x += 1;
                sum++;
            }else{
                d = (d + 1) % 4;
                continue;
            }
          }else if(d == 2){
            if(maap[x][y - 1] == '.' && 1 <= x && x <= n && 1 <= y - 1 && y - 1 <= m){
                y -= 1;
                sum++;
            }else{
                d = (d + 1) % 4;
                continue;
            }
          }else if(d == 3){
            if(maap[x - 1][y] == '.' && 1 <= x - 1 && x - 1 <= n && 1 <= y && y <= m){
                x -= 1;
                sum++;
            }else{
                d = (d + 1) % 4;
                continue;
            }
      }
  }
  printf("%d\n", sum);
  }
  return 0;
}
