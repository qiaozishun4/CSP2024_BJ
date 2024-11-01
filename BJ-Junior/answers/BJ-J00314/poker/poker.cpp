#include<bits/stdc++.h>
using namespace std;

bool collect_[4][13];
int n;
string in_;
char pat, num;
int code_pat;
int code_num;
int ans = 52;

int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> in_;
        pat = in_[0];
        num = in_[1];

        if (pat == 'D') {
            code_pat = 0;
        } else if (pat == 'C'){
            code_pat = 1;
        } else if (pat == 'H'){
            code_pat = 2;
        } else {
            code_pat = 3;
        }

        if (num == 'A') {
            code_num = 0;
        } else if (num == 'T') {
            code_num = 9;
        } else if (num == 'J') {
            code_num = 10;
        } else if (num == 'Q') {
            code_num = 11;
        } else if (num == 'K') {
            code_num = 12;
        } else {
            code_num = num-'0'-1;
        }

        if (!collect_[code_pat][code_num]) {
            collect_[code_pat][code_num] = 1;
            ans --;
        }
    }

    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);


    return 0;
}
