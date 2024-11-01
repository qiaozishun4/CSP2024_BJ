#include<bits/stdc++.h>
using namespace std;
bool D[13]={0};
bool C[13]={0};
bool H[13]={0};
bool S[13]={0};
vector<vector<char>> temp;
vector<char> t;
char tc;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out", "w",stdout);

    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<2;j++){
            cin >> tc;
            t.push_back(tc);
        }

        temp.push_back(t);
        t.clear();
    }
    for(int i=0;i<temp.size();i++){
        if(temp[i][1] == 'A'){
            temp[i][1] = '1';
        if(temp[i][1] == 'T'){
        }
            temp[i][1] = '0'+10;
        }
        if(temp[i][1] == 'J'){
            temp[i][1] = '0'+11;
        }
        if(temp[i][1] == 'Q'){
            temp[i][1] = '0'+12;
        }
        if(temp[i][1] == 'K'){
            temp[i][1] = '0'+13;
        }

        int tint;
        tint = temp[i][1] - '0';
        if(temp[i][0] == 'D'){
            D[tint] = 1;
        }
        if(temp[i][0] == 'C'){
            C[tint] = 1;
        }
        if(temp[i][0] == 'H'){
            H[tint] = 1;
        }
        if(temp[i][0] == 'S'){
            S[tint] = 1;
        }
    }
    int cnt = 0;
    for(int i = 0;i<13;i++){
        if(!D[i]){
            cnt++;
        }
        if(!C[i]){
            cnt++;
        }
        if(!H[i]){
            cnt++;
        }
        if(!S[i]){
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}
