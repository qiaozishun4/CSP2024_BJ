#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("sticks.in","r",stdin);
freopen("sticks.out","w",stdout);
int a,b[100],xq[8] = {-1,1,7,4,2,6,8},anx[9] = {0,10,18,22,26,28,68};
long long ans = 0;
cin >> a;
for(int i = 1;i <+ a;i++){
cin >> b[i];
if(b[i]<=7){
    cout << xq[b[i]];
}
else{
    for(int j = 0;j <= 6;j++){
        if(b[i] % 7 == j){
        ans = anx[j];
        b[i] = b[i] - j - 7;
            while(b[i] != 0){
                ans = ans *10 + 8;
                b[i] = b[i]-7;
            }

        }
    }
    cout << ans;

}
}
return 0;
}
