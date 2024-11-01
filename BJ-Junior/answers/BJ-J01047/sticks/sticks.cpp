#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int c[11] = {1,5,2,2,3,2,1,4,0,1};
int t,n;
int num[N];
bool pas = 1;
int cel(int x,int y){
    return (x % y == 0 ? x / y : (x / y) + 1);
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        pas = 1;
        int len = cel(n, 7);
        int sum = (len * 7) - n;
        for(int i = 1;i <= len;i++){
            num[i] = 8;
        }
        for(int i = 1;i <= len;i++){
            if(i == 1 && i != len){
                for(int j = 1;j <= 9;j++){
                    if(sum >= c[j] && sum - c[j] < (len - 1) * 5){
                        sum -= c[j];
                        num[i] = j;
                        break;
                    }
                }
            }else if(i > 1 && i < len){
                for(int j = 0;j <= 9;j++){
                    if(sum >= c[j] && sum - c[j] < (len - 1) * 5){
                        sum -= c[j];
                        num[i] = j;
                        break;
                    }
                }
            }else{
                if(sum == 0){continue;}
                else{
                    bool flag = 1;
                    if(len == 1){
                        for(int j = 1;j <= 9;j++){
                            if(c[j] == sum){
                                sum -= c[j];
                                num[i] = j;
                                flag = 0;
                                break;
                            }
                        }
                    }else{
                        for(int j = 0;j <= 9;j++){
                            if(c[j] == sum){
                                sum -= c[j];
                                num[i] = j;
                                flag = 0;
                                break;
                            }
                        }
                    }
                    if(flag){
                        pas = 0;
                    }
                }
            }
        }
        if(pas){
            for(int i = 1;i <= len;i++){
            printf("%d",num[i]);
        }
        }else{
            printf("-1");
        }

        printf("\n");
    }
    return 0;
}