#include<bits/stdc++.h>
using namespace std;
long long t, n, m, k, x, y, d, c[1010][1010], u = 1;
char o;
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin>>t;
    for(int i = 1; i <= t; i++){
        cin>>n>>m>>k>>x>>y>>d;
        for(int j = 1; j <= n; j++){
            for(int k1 = 1; k1 <= m; k1++){
                cin>>o;
                if(o == 'x'){
                    c[j][k1] = 1;
                }
            }
        }
        if(k == 1){
            if(d == 0){
                if(c[x][y + 1] == 0&&y + 1 <= m){
                    cout<<"2"<<endl;
                }else{
                    cout<<"1"<<endl;
                }
            }else if(d == 1){
                if(c[x + 1][y] == 0&&x + 1 <= n){
                    cout<<"2"<<endl;
                }else{
                    cout<<"1"<<endl;
                }
            }else if(d == 2){
                if(c[x][y - 1] == 0&&y - 1 >= 1){
                    cout<<"2"<<endl;
                }else{
                    cout<<"1"<<endl;
                }
            }else{
                if(c[x - 1][y] == 0&&x - 1 >= 1){
                    cout<<"2"<<endl;
                }else{
                    cout<<"1"<<endl;
                }
            }
        }else{
            c[x][y] = 2;
            for(int j = 1; j <= k; j++){
                if(d == 0){
                    if(c[x][y + 1] == 0){
                        if(y + 1 <= m){
                            u++;
                            c[x][y + 1] = 2;
                            y = y + 1;
                       }else{
                            d = 1;
                        }
                    }else if(c[x][y + 1] == 2){
                        y = y + 1;
                    }else{
                        d = 1;
                    }
                }else if(d == 1){
                    if(c[x + 1][y] == 0){
                        if(x + 1 <= n){
                            u++;
                            c[x + 1][y] = 2;
                            x = x + 1;
                        }else{
                            d = 2;
                        }
                    }else if(c[x + 1][y] == 2){
                        x = x + 1;
                    }else{
                        d = 2;
                    }
                }else if(d == 2){
                    if(c[x][y - 1] == 0){
                        if(y - 1 >= 1){
                            u++;
                            c[x][y - 1] = 2;
                            y = y - 1;
                        }else{
                            d = 3;
                        }
                    }else if(c[x][y - 1] == 2){
                        y = y - 1;
                    }else{
                        d = 3;
                    }
                }else{
                    if(c[x - 1][y] == 0){
                        if(x - 1 >= 1){
                            u++;
                            c[x - 1][y] = 2;
                            x = x - 1;
                        }else{
                            d = 0;
                        }
                    }else if(c[x - 1][y] == 2){
                        x = x - 1;
                    }else{
                        d = 0;
                    }
                }
            }
            cout<<u<<endl;
        }
        for(int j = 1; j <= n; j++){
            for(int k1 = 1; k1 <= m; k1++){
                c[j][k1] = 0;
            }
        }
        u = 1;
    }
    return 0;
}
