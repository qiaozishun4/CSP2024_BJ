#include<bits/stdc++.h>
using namespace std;
int biao[1000001];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin >> T;
    for(int I=1;I<=T;I++){
        int a;
        cin >> a;
        for(int i=1;i<=1000000;i++){
            biao[i]=0;
        }
        for(int i=1;i<=a;i++){
            int x;
            cin >> x;
            biao[x]++;
        }
        long long da=0;
        for(int i=1;i<=1000000;i++){
            da+=(max((biao[i]-1),0)*i);
        }
        cout << da << "\n";
    }
    return 0;
}
