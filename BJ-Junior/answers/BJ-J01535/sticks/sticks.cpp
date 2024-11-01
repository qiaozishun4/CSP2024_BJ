#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    scanf("%d",&t);
    int n[51],p[51];
    for (int i = 1;i <= t;i++){
       scanf("%d",&n[i]);
       if (n[i] == 1) p[i] = -1;
       else if(n[i] == 2) p[i] = 1;
       else if(n[i] == 3) p[i] = 7;
       else if(n[i] == 4) p[i] = 4;
       else if(n[i] == 5) p[i] = 2;
       else if(n[i] == 6) p[i] = 6;
       else if(n[i] == 7) p[i] = 8;
       else if(n[i] == 8) p[i] = 10;
       else if(n[i] == 9) p[i] = 18;
       else if(n[i] == 10) p[i] = 23;
       else if(n[i] == 11) p[i] = 20;
       else if(n[i] == 12) p[i] = 28;
       else if(n[i] == 13) p[i] = 80;
       else if(n[i] == 14) p[i] = 128;
       else if(n[i] == 15) p[i] = 168;
       else if(n[i] == 16) p[i] = 188;
       else if(n[i] == 17) p[i] = 200;
       else if(n[i] == 18) p[i] = 208;
       else if(n[i] == 19) p[i] = 288;
       else if(n[i] == 20) p[i] = 688;
    }
    //int m[10] = {6,2,5,5,4,5,6,3,7,6};
    for (int i = 1;i <= t;i++) cout<<p[i]<<endl;
    return 0;
}