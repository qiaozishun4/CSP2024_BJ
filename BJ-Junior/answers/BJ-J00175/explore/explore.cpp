#include <iostream>
using namespace std;
int main(){
      freopen("explore.in","r",stdin);
      freopen("explore.out","w",stdout);
      int t;
      cin >> t;
      while(t--){
            int ans = 0;
            int m[100][100];
            int a,b,c,d,e,f;
            scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
            int k;
            for(int i = 1;i <= a;i++){
                  for(int j = 1;i <= b;j++){
                        char q;
                        cin >> q;
                        k = (int)q;
                        m[i][j] = k;
                  }
		}
           while(c--){
               if(f == 0){
                 if(e+1 <= b){
                  if(m[d][e+1] == 46){
                        e++;
                        ans++;
                  }else{
                        f = (f+1)%3;
                  }
                 }else{
                 f = (f+1)%3;
                 }
               }
               if(f == 1){
                 if(d+1 <= a){
                  if(m[d][e-1] == 46){
                        d++;
                        ans++;
                  }else{
                        f = (f+1)%3;
                  }
                 }else{
                 f = (f+1)%3;
                 }
               }
               if(f == 2){
                 if(e-1 >= 1){
                  if(m[d][e+1] == 46){
                        e--;
                        ans++;
                  }
                  else{
                        f = (f+1)%3;
                  }
                 }else{
                       f = (f+1)%3;
                 }
               }
               if(f == 3){
                 if(d-1 >= 1){
                  if(m[d-1][e] == 46){
                        d--;
                        ans++;
                  }else{
                        f = (f+1)%3;
                  }
                 }else{
                       f = (f+1)%3;
                 }
               }
            }
      cout << ans << endl;
      }


  return 0;
}