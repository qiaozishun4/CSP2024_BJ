#include <iostream>
using namespace std;
int main(){
      freopen("poker.in","r",stdin);
      freopen("poker.out","w",stdout);
      int n,c,d,cnt = 0;
      int e[1000]={0};
      int f[1000]={0};

      cin  >> n;
      int ans = 52-n;
      if(n == 1){
            cout << "51";
            return 0;
      }
      int i = 1;
      int t = n;
      while(n -- ){
            char a,b;
            cin >> a >>b;
            c = (int)a;
            d = (int)b;
            e[i] = c;
            f[i] = d;
            i++;

      }
      int j = 1;
      while(j < t){
      for(int i= j+1;i <= t;i++){
           if(e[j] == e[i] && f[j] == f[i]){
            cnt++;
           }
           }
           ans = ans + cnt;
           cnt = 0;
           j++;
      }
     cout << ans;
      return 0;
}