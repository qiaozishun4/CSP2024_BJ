#include <bits/stdc++.h>
using namespace std;
int ha[]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int t,n;
int cnt(int num){
    if(num%8)
        return (num/8+1);
    return num/8;
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        if(n<2){
            cout << "-1\n";
            continue;
        }
        int num = max(0,cnt(n)-2);
        cout << ha[n-num*7];
        while(num--){
            cout << 8;
        }
        cout << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
