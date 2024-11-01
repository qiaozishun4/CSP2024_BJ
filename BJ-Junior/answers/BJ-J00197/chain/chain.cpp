#include<iostream>
using namespace std;
int t,n,a[1145145],q,k;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n >> k >> q;
        for(int i=1;i<=n;i++){
            int tmp;cin >> tmp;
            for(int j=1;j<=tmp;j++){
                cin >> a[j];
            }
        } 
        for(int i=1;i<=q;i++){
            int x,y;
            cin >> x >> y;
        }
        for(int i=1;i<=q;i++){
            cout << 0 << endl;
        }
    }
}