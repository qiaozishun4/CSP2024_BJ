#include<bits/stdc++.h>
using namespace std;
string pok[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,sum = 0,sum2 = 0;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> pok[i];
    for(int i = 1;i <= n;i++){
        string tmp = pok[i];
        sum = 1;
        for(int j = i+1;j <= n;j++){
            if(pok[j] == tmp){
                sum++;
                break;
            } 
        }
        sum2 += (sum-1);
    }
    cout << 52-n+sum2 << endl;

    return 0;
}