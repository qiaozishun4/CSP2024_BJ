#include<iostream>
#include<cmath>
#include<cstring>
//#define test1
//#define test2
using namespace std;
int n, m;
int T;
const int N = 100010;
long long a_base[N];
long long a_real[N];
int c[N];
int d[21][21];
bool survive[N];
long long ans[N];
int cnt;
int cnt_game = 0;
long long x[4];
int main(){
    string data;
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a_base[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> c[i];
    }
    for(int i = 1; i <= ceil(log2(n)); i++){
        cin >> data;
        for(int j = 0; j < data.size(); j++){
            d[i][j + 1] = data[j] - '0';
        }
    }
    #ifdef test1
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 4; j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    #endif
    cin >> T;
    for(int o = 1; o <= T; o++){
        for(int i = 1; i <= n; i++){
            survive[i] = true;
        }
        for(int i = 0; i <= 3; i++){
            cin >> x[i];
        }

        for(int i = 1; i <= n; i++){
            a_real[i] = a_base[i] ^ x[i % 4];
            #ifdef test1
            cout << a_real[i] << " ";
            cout << endl;
            #endif
        }
        cnt_game = 0;
        for(int i = 1; i <= m; i++){
            cnt = c[i];
            cnt_game = 0;
            if(ceil(log2(c[i])) == log2(c[i])){
                int round = 1;
                int point = 1;
                int player1 = 0;
                int player2 = 0;
                for(int j = 1; j <= n; j++){
                    survive[j] = true;
                }
                while(true){
                    #ifdef test2
                    cout << "cnt:" << cnt << " round:" << round << " cnt_game:" << cnt_game << " point:" << point << " player1:" << player1 << " player2:" << player2 << endl;
                    cout << "survive: ";
                    for(int j = 1; j <= c[i]; j++){
                        cout << survive[j] << " "; 
                    }
                    cout << endl;
                    #endif
                    if(survive[point]){
                        if(cnt == 1){
                            ans[i] = point;
                            break;
                        }
                        if(player1 == 0){
                            player1 = point;
                        }else{
                            player2 = point;
                            cnt_game++;
                            if(player1 > player2){
                                swap(player1, player2);
                            }
                            #ifdef test2
                            cout << player1 << " " << player2 << endl;
                            cout << round << " " << cnt_game << endl;
                            #endif
                            if(d[round][cnt_game]){
                                if(a_real[player1] >= round){
                                    survive[player2] = false;
                                }else{
                                    survive[player1] = false;
                                }
                            }else{
                                if(a_real[player2] >= round){
                                    survive[player1] = false;
                                }else{
                                    survive[player2] = false;
                                }
                            }
                            cnt--;
                            player1 = 0;
                            player2 = 0;
                        }
                    }
                    if(point < c[i]){
                        point++;
                    }else{
                        point = 1;
                        round++;
                        cnt_game = 0;
                    }
                }
            }
            #ifdef test2
            cout << ans[i] << endl;
            #endif
        }
        #ifdef test2
        for(int i = 1; i <= m; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        #endif
        long long final_ans = 0;
        for(int i = 1; i <= m; i++){
            final_ans = (final_ans ^ (i * ans[i]));
        }
        cout << final_ans << endl;
    }
    return 0;
}