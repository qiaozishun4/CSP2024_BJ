#include<bits/stdc++.h>
using namespace std;
int num[100001][200001];
int cnt = 0;
int find_num(int j,int l,int k,int n){
    for(int i = 2;i <= k;i ++){
        int number = num[j][l - i];
        for(int a = 0;a < n;i ++){
            if(a != j){
                for(int b = 1;b <= num[j][0];b ++){
                    if(num[a][b] == number){
                            cnt += find_num(a,b,k,n);
                    }
                }
            }
        }
    }

}
int main(){
    int T;
    cin >> T;
    while(T --){
        int n,k,q;
        cin >> n >> k >> q;
        for(int i = 0;i < n;i ++){
            int number;
            cin >> number
            num[i][0] = number;
            for(int j = 1;j <= number;j ++) cin >> num[i][j];
        }
        for(int i = 0;i < q;i ++){
            int r,c;
            cin >> r >> c;
            for(int j = 0;j < n;j ++) for(int l = 1;l < num[j][0];l ++) if(num[j][l] == c) find_num(j,l,k,n);
        }
    }
}
