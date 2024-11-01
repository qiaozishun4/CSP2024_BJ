#include <iostream>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    int all = 52;
    char s[2],a[n][n];
    int f = 1;
    for(int i = 0;i < n;i++){
        cin >> s[0] >> s[1];
        int cnt = 0;
        for(int j = 0;j < n;j++){
            if(s[0] == a[j][0]){
                if(s[1] == a[j][1]){
                    cnt++;
                }
            }
        }
        if(!cnt){
            a[i][0] = s[0];
            a[i][1] = s[1];
            all--;
        }
    }
    cout << all << endl;
    return 0;
}
