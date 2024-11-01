#include<bits/stdc++.h>
using namespace std;
#define endl "\n";
const int N = 52 + 5;
char p[] = {'0', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
char flw[]= {'0', 'D', 'C', 'H', 'S'};
string s;
bool f[5][N];
int n;
bool flag = true;
void soloved() {
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        cin >>s;
        for(int i = 1; i <= 4 && flag; i ++) {
 //               cout << "in1" <<' ';
            for(int j = 1; j <= 13 && flag; j ++) {
 //               cout<<"in2"<<' ';
                if(s[0] == flw[i] && s[1] == p[j]) {
                    flag = false;
                    if(!f[i][j]) {
                        cnt ++;
  //                      cout<<'+'<<' ';
                    }
                    f[i][j] = true;
                }
            }
  //      cout<<endl;
        }
        flag = true;

    }
    cout << 52 - cnt;
    return ;
}
int main() {
      freopen("poker.in", "r", stdin);
      freopen("poker.out", "w", stdout);
//    ios_sync_with_stdio(false);
//    cin.tie;
//    cout.tie;
    int t = 1;
//    cin >> t;
    while(t--) {
        soloved();
    }

}

