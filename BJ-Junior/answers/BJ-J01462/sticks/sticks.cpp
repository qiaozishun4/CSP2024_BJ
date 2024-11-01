#include<bits/stdc++.h>
#define i(x,y) if(n==x) cout<<y;
using namespace std;
int n,t,k,d,x,y,ans;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        i(1, -1);
        i(2,  1);
        i(3,  7);
        i(4,  4);
        i(5,  2);
        i(6,  6);
        i(7,  8);
        i(8, 10);
        i(9, 18);
        i(10,22);
        i(11,20);
        i(12,28);
        i(13,68);
        i(14,88);
        if(n>=15){
            int nn=(n-1)/7-2;
            n=n%7;
            i(1,168);
            i(2,188);
            i(3,200);
            i(4,208);
            i(5,288);
            i(6,688);
            i(0,888);
            while(nn--){
                cout<<'8';
            }
        }
        cout<<endl;
    }
    return 0;
}
