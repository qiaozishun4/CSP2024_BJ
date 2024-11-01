#include<bits/stdc++.h>
#include<fstream>

using namespace std;

//check your file cin!!!!!!!!!!!!!!!
//ifstream ofstream!!!!

ifstream fin("poker.in");
ofstream fout("poker.out");

const int N = 60;
int n,ans;
string s;
bool f[10][20];
int main(){
    fin >> n;
    for(int i = 1;i <= n;i ++){
        fin >> s;
        if(s[0] == 'D'){
            if(s[1] == 'A'){
                f[1][1] = true;
            } else if(s[1] == 'T'){
                f[1][10] = true;
            } else if(s[1] == 'J'){
                f[1][11] = true;
            } else if(s[1] == 'Q'){
                f[1][12] = true;
            } else if(s[1] == 'K'){
                f[1][13] = true;
            } else {
                f[1][(s[1] - '0')] = true;
            }
        } else if(s[0] == 'C'){
             if(s[1] == 'A'){
                f[2][1] = true;
            } else if(s[1] == 'T'){
                f[2][10] = true;
            } else if(s[1] == 'J'){
                f[2][11] = true;
            } else if(s[1] == 'Q'){
                f[2][12] = true;
            } else if(s[1] == 'K'){
                f[2][13] = true;
            } else {
                f[2][(s[1] - '0')] = true;
            }
        } else if(s[0] == 'H'){
            if(s[1] == 'A'){
                f[3][1] = true;
            } else if(s[1] == 'T'){
                f[3][10] = true;
            } else if(s[1] == 'J'){
                f[3][11] = true;
            } else if(s[1] == 'Q'){
                f[3][12] = true;
            } else if(s[1] == 'K'){
                f[3][13] = true;
            } else {
                f[3][(s[1] - '0')] = true;
            }
        } else if(s[0] == 'S'){
            if(s[1] == 'A'){
                f[4][1] = true;
            } else if(s[1] == 'T'){
                f[4][10] = true;
            } else if(s[1] == 'J'){
                f[4][11] = true;
            } else if(s[1] == 'Q'){
                f[4][12] = true;
            } else if(s[1] == 'K'){
                f[4][13] = true;
            } else {
                f[4][(s[1] - '0')] = true;
            }
        }
    }
    for(int i = 1;i <= 4;i ++){
        for(int j = 1;j <= 13;j ++){
            if(f[i][j] == false){
                ans ++;
            }
        }
    }
    fout << ans << endl;
    return 0;
}