#include<bits/stdc++.h>
#define ll long long

using namespace std;

//TO NAME
int s[20] = {108, 188, 200, 208, 288, 688, 888}, n, l[20] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88};

int main(){

    //TO DO
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(n < 15){
            printf("%d\n", l[n]);
            continue;
        }
        else{
            int e = (n - 15) / 7;
            int u = (n - 15) % 7;
            printf("%d", s[u]);
            for(int i = 1;i <= e;i++){
                printf("8");
            }
            printf("\n");
        }
    }

    return 0;
}
