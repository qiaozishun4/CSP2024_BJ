#include <bits/stdc++.h>
using namespace std;
int n,a[52],ans;
char x,y;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    while(n--){
        cin >> x >> y;
        if(x == 'S'){
            if(y == 'A'){
                a[13]++;
            }else if(y == 'T'){
                a[22]++;
            }else if(y == 'J'){
                a[23]++;
            }else if(y == 'Q'){
                a[24]++;
            }else if(y == 'K'){
                a[25]++;
            }else{
                a[13 + (y - '0') - 1]++;
            }
        }
        if(x == 'C'){
            if(y == 'A'){
                a[0]++;
            }else if(y == 'T'){
                a[9]++;
            }else if(y == 'J'){
                a[10]++;
            }else if(y == 'Q'){
                a[11]++;
            }else if(y == 'K'){
                a[12]++;
            }else{
                a[(y - '0') - 1]++;
            }
        }
        if(x == 'D'){
            if(y == 'A'){
                a[26]++;
            }else if(y == 'T'){
                a[35]++;
            }else if(y == 'J'){
                a[36]++;
            }else if(y == 'Q'){
                a[37]++;
            }else if(y == 'K'){
                a[38]++;
            }else{
                a[26 + (y - '0') - 1]++;
            }
        }
        if(x == 'H'){
            if(y == 'A'){
                a[39]++;
            }else if(y == 'T'){
                a[48]++;
            }else if(y == 'J'){
                a[49]++;
            }else if(y == 'Q'){
                a[50]++;
            }else if(y == 'K'){
                a[51]++;
            }else{
                a[39 + (y - '0') - 1]++;
            }
        }
    }
    for(int i = 0;i < 52;i++){
        if(!a[i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
