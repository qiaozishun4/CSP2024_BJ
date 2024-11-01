#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 1;i <= n / 7;i++)
            cout<<8;
        cout<<endl;
    }
    /*
    int n;
    cin>>n;
    if(n <= 1){
        cout<<-1;
        return 0;
    }
    if(n == 6){
        cout<<6;
        return 0;
    }
    stick(n);
    sort(ans, ans + t);
    int mm = 0x7f7f7f7f, ind = 123321;
    for(int i = 0;i < t;i++){
        if(ans[i] != 0 && ans[i] < mm){
            mm = ans[i];
            ind = i;
        }
        cout<<mm<<" ";
        cout<<ind<<endl;
    }
    cout<<mm;
    ans[ind] = -1;
    for(int i = 0;i < t;i++)
        if(ans[i] != -1)
            cout<<ans[i];
    */
    return 0;
}
