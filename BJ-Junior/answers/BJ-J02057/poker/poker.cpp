#include<iostream>
using namespace std;
int main(){
    freeopen("poker.in","r",stdin);
    freeopen("poker.out","w",stdout);
    int n;
    cin >> n;
    int cnt=52;
    string str;
    for(int i=1; i<=n; i++){
        cin >> str;
    }
    for(int i=1; i<=n; i++){
        for(int j=n; j>1; j--){
            if(str[i]==str[j]){
                cnt--;
            }
        }
    }
    cout << cnt;

    return 0;
}
