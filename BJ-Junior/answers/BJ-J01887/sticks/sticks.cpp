#include <iostream>
using namespace std;
const int ans[]={
-1,
-1,
1,
7,
4,
5,
6,
8,
10,
18,
22,
20,
28,
68,
16,
108,
188,
200,
208,
288,
688,
888,
1208,
1288,
2008,
2088,
2888,
6888,
8888,
10888,
18888,
20088,
20888,
28888,
68888,
88888,
};
int main(){
    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        cout<<ans[t]<<endl;
    }
}
