#include<bits/stdc++.h>
using namespace std;
int t;
int n[55];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> n[i];
        if(n[i] == 1) cout << -1 << endl;
        else if(n[i] == 2) cout << 1 << endl;
        else if(n[i] == 4) cout << 4 << endl;
        else if(n[i] == 3) cout << 7 << endl;
        else if(n[i] == 7) cout << 8 << endl;
        else if(n[i] == 5) cout << 2 << endl;
        else if(n[i] == 6) cout << 6 << endl;
        else {
            int d = n[i] / 6;
            if(n[i]%6 == 0){
                if(d == 2) cout << 28 << endl;
                else {
                    cout << 2;
                    for(int i=1;i<=d-2;i++) cout << 0;
                    cout << 8 << endl;
                }
            }else if(n[i]%6 == 1){
                if(d == 3) cout << 288 << endl;
                else {
                    cout << 2;
                    for(int i=1;i<=d-3;i++) cout << 0;
                    cout << 88 << endl;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
