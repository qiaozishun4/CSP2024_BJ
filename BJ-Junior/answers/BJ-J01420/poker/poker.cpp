#include<bits/stdc++.h>
using namespace std;
int n,sum;
bool D[15],C[15],H[15],S[15];
char a,b;
  int main(){
  freopen("poker.in","r",stdin);
  freopen("poker.out","w",stdout);
  scanf("%d",&n);
  for(int i = 0;i < n;i++){
      scanf(" %c%c",&a,&b);
      if(a == 'D'){
          if(b >= '0'&& b <= '9'){
              D[b - 48]++;
          }else if(b == 'A'){
              D[1] = 1;
          }else if(b == 'T'){
              D[10] = 1;
          }else if(b == 'J'){
              D[11] = 1;
          }else if(b == 'Q'){
              D[12] = 1;
          }else if(b == 'K'){
              D[13] = 1;
          }
      }else if(a == 'C'){
          if(b >= '0'&& b <= '9'){
              C[b - 48]++;
          }else if(b == 'A'){
              C[1] = 1;
          }else if(b == 'T'){
              C[10] = 1;
          }else if(b == 'J'){
              C[11] = 1;
          }else if(b == 'Q'){
              C[12] = 1;
          }else if(b == 'K'){
              C[13] = 1;
          }
      }else if(a == 'H'){
          if(b >= '0'&& b <= '9'){
              H[b - 48]++;
          }else if(b == 'A'){
              H[1] = 1;
          }else if(b == 'T'){
              H[10] = 1;
          }else if(b == 'J'){
              H[11] = 1;
          }else if(b == 'Q'){
              H[12] = 1;
          }else if(b == 'K'){
              H[13] = 1;
          }
      }else if(a == 'S'){
          if(b >= '0'&& b <= '9'){
              S[b - 48] = 1;
          }else if(b == 'A'){
              S[1] = 1;
          }else if(b == 'T'){
              S[10] = 1;
          }else if(b == 'J'){
              S[11] = 1;
          }else if(b == 'Q'){
              S[12] = 1;
          }else if(b == 'K'){
              S[13] = 1;
          }
      }
  }
  for(int i = 1;i <= 13;i++){
      if(D[i] == 0) sum++;
      if(C[i] == 0) sum++;
      if(H[i] == 0) sum++;
      if(S[i] == 0) sum++;
  }
  printf("%d",sum);
  return 0;
}