#include<bits/stdc++.h>
using namespace std;
int sn[50] = {6,2,5,5,4,5,6,3,7,6};
int qian[50] = {0,10,1,200,20,2,6};
int dabiao[50] = {0,-1,1,7,4,2,6};
int getnum(int x){
    int sum = 0;
    while(x){
        sum += sn[x%10];
        x /= 10;
    }
    return sum;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(n <= 6) cout << dabiao[n] << endl;
        else if(n%7 == 0){
            for(int i = 1;i <= n/7;i++) cout << 8;
            cout << endl;
        }else{
            cout << qian[n%7];
            int num = getnum(qian[n%7]);
            for(int i = 1;i <= (n-num)/7;i++) cout << 8;
            cout << endl;
        }
    }

    return 0;
}