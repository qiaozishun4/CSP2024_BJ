#include<bits/stdc++.h>
using namespace std;

int n , m;
string s[60];

int main(){
    freopen("poker.in" , "r" , stdin);
    freopen("poker.out" , "w" , stdout);
    scanf("%d" , &n);
    m = n;
    for(int i = 1; i <= n; i++){
            /*
        scanf("%s" , s[i]);
        printf("%s/n" , s[i]);
        */
        cin >> s[i];
        for(int j = 1; j < i; j++){
            if(s[i] == s[j]){
                m--;
                break;
            }
        }
    }
    printf("%d" , 52 - m);
    return 0;
}
