#include <iostream>
using namespace std;
long long a[100005];
int n;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    //input
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int z1 = 0,c = 0,b[100005];
    //count out
    for(int k = 0;k < n;k++){
        int z2 = 0;
        int f = 1;
        for(int i = 0;i < n;i++){
            if(a[k] == b[i]){
                f = 0;
            }
        }
        if(f){
            for(int i = 0;i < n;i++){
                if(a[i] == a[k]){
                    z2++;
                }
            }
        }
        if(z2 > z1){
            z1 = z2;
        }
        c++;
    }

    cout << z1 << endl;
    return 0;
}
