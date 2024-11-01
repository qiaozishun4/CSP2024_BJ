#include<bits/stdc++.h>
using namespace std;
int t,n;
int s[10] = {6,2,5,5,4,5,6,3,7,6};
char p[5];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while(t --){
        cin >> n;
        if(n == 1){
            cout << -1 << endl;
            continue;
        }
        for(int i = 1;i <= 20000;i ++){
            int len = 0,j = i;
            while(j){
                p[len] = (j % 10) + '0';
                len ++;
                j /= 10;
            }
            int sum = 0;
            for(int k = 0;k <= len;k ++){
                sum += s[p[k] - '0'];
            }
            if(sum == n){
                cout << i << endl;
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
