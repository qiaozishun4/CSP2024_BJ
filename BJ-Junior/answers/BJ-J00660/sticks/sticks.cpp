#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    for(int nt=1;nt<=t;nt++){
        int n;
        cin >> n;
        if(n%7==0){
            int l=n/7;
            for(int i=1;i<=l;i++){
                printf("8");
            }
            printf("\n");
        }else if(n%7==1){
            int l=(n-8)/7;
            printf("10");
            for(int i=1;i<=l;i++){
                printf("8");
            }
            printf("\n");
        }

    }
    return 0;
}
