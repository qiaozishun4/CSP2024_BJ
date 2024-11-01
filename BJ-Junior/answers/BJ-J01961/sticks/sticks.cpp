

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

char stin[19] = {'6', '2', '5', '5', '4', '5', '6', '3', '7', '6'};

bool cmp (string a, string b) {
    if (a[0] >= '9') {
        return 1;

    }
    if (a.size() > b.size()) {
        return 1;
        
    }
    return a > b;

}
string ans  = "-1";
int n;
void dfs (string num, int laststi) {
    
    if (laststi == 0) {
        if (ans == "-1") {
            ans = num;
            return ;

        }
        if (cmp(ans, num)) {
            ans = num;
            return ;
        }

    }
    
    for (int i = 0; i < 9; i++) {
        if (num == "" && i == 0) {
            continue;

        }
        if (laststi >= int(stin[i] - '0')) {
            dfs(num + char(i + 48), laststi - int(stin[i] - '0'));
        }
        
    }
}

void ParseIn () {
    ifstream inFile("sticks.in");
    ofstream outFile("sticks.out");
    inFile >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        inFile >> x;
        if (x == 1) {
            outFile << -1 << endl;
            continue;

        }
        if (x == 2) {
            outFile << 1 << endl;
            continue;

        }
        if (x == 3) {
            outFile << 7 << endl;
            continue;
        }
        if (x == 4) {
            outFile << 4 << endl;
            continue;
            
        }
        if (x == 5) {
            outFile << 2 << endl;
            continue;
        }
        if (x == 6) {
            outFile << 6 << endl;
            continue;
        }
        if (x == 7) {
            outFile << 8 << endl;
            continue;
        }
        dfs("", x);
        outFile << ans << endl;
        /*for (int m = 8; m <= x; m++) {
            for (int k = 0; k < 9; k++) {
                if (int(_stin[k] - '0') > m) {
                    continue;

                }
                string solo = dp[m - int(_stin[k - '0'])] + char(k + 48);
                if (solo[0]  == '-') {
                    continue;

                }
                if (dp[m] == ""){
                    if (solo[0] != '0') {
                        dp[m] = dp[m - int(_stin[k - '0'])] + char(k + 48);

                    }
                    
                }
                if (cmp(dp[m], dp[m - int(_stin[k - '0'])] + char(k + 48))) {
                    
                    if (solo[0] != '0') {
                        dp[m] = dp[m - int(_stin[k - '0'])] + char(k + 48);

                    }
                }
                
            }

        }
        for (int i = 0; i < 100001; i++) {
            dp[i] = "";

        }*/
        ans = "error";
    }
    inFile.close();
    outFile.close();
}

int main () {
    ParseIn();
    //Core();
    return 0;
}