#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    freopen("detect.in" ,  "r" , stdin);
    freopen("detect.out" , "w" ,stdout);
    double t , n , m , l , V;
    double d[100005], v[100005] , a[100005]  ;
    double check[100005] = {0}, time , sum = 0 , sum1 = 0 , p[100005] , s , speed , speed2[100005] = {1};
    bool flag = 1;
    cin>> t;
    for (int i = 1; i <= t; i++){
        cin>> n >> m >> l >> V;
        for (int j = 1; j <= n; j++){
            cin>> d[j] >> v[j] >> a[j];
            s = d[j];
            speed = v[j];
            if (speed > V){
                sum++;
                speed2[j] == 0;
                continue;
            }else if (speed == V && a[j] > 0){
                sum++;
                speed2[j] == 0;
                continue;
            }else{
                time = 0;
                s = d[j];
                flag = 0;
                while(s < l){
                    speed = v[j] + a[j] * time;
                    s += speed;
                    if (speed > V){
                        sum++;
                        speed2[j] = 0;
                        break;
                    }
                    time++;
                }
                continue;
            }
        }
        for (int j = 0; j < m; j++){
            cin>> p[j];
        }
        for (int j = 1; j <= n; j++){
            if (speed2[j] == 1){
                continue;
            }else{
                time = 0;
                s = d[j];
                flag = 0;
                while(s < l){
                    speed += v[j];
                    speed = speed + a[j] * time;
                    s += speed;
                    for (int k = 0; k < m; k++){
                        if (s == p[k] && speed > V){
                            check[k] = 1;
                            flag = 1;
                            break;
                        }
                    }
                    time++;
                    if (flag == 1){
                        break;
                    }
                }
            }
        }
        cout<< sum << " ";
        for (int j = 0; j < m; j++){
            if (check[j] == 0){
                sum1++;
            }
        }
        cout<< sum1 << endl;
    }
}