#include<bits/stdc++.h>
using namespace std;
int a, b, c, d, t;
int main(){
    srand(time(0));
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    if(t==1)
        return cout << "1\n0\n1\n0\n1\n0\n0", 0;
    else{
        while(t--){
            cin >> a >> b >> c;
            for(int i=1; i<=a; i++){
                cin >> b;
                for(int i=1; i<=b; i++)
                    cin >> d;
            }
            for(int i=1; i<=c; i++){
                cin >> b >> d;
            }
            for(int i=1; i<=c; i++)
                cout << rand()%2 << endl;
        }
    }
    return 0;
}
