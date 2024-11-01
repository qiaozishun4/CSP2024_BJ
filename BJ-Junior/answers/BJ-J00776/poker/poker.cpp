#include<bits/stdc++.h>
using namespace std;
int n;
string s;
bool a[4][13];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i ++){
        cin >> s;
        int sum = 0;
        if(s[1] >= '2' && s[1] <= '9'){
            sum = s[1] - '0';
        }else{
            if(s[1] == 'A'){
                sum = 1;
            }else if(s[1] == 'T'){
                sum = 10;
            }else if(s[1] == 'J'){
                sum = 11;
            }else if(s[1] == 'Q'){
                sum = 12;
            }else{
                sum = 13;
            }
        }
        int f = 0;
        if(s[0] == 'D'){
            f = 1;
        }else if(s[0] == 'C'){
            f = 2;
        }else if(s[0] == 'H'){
            f = 3;
        }else{
            f = 4;
        }
        a[f - 1][sum - 1] = true;
    }
    int ans = 0;
    for(int i = 0;i < 4;i ++){
        for(int j = 0;j < 13;j ++){
            if(!a[i][j]){
                ans ++;
            }
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
