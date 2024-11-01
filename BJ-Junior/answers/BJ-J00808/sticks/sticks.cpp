#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int T, n;
int s[7]={6, 2, 5, 4, 6, 3, 7};
int l[7]={0, 1, 2, 4, 6, 7, 8};

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin>>T;
    for(int q=0;q<T;q++){
        cin>>n;
        if(n<=1){
            cout<<"-1"<<endl;
            continue;
        }
        int m=n;
        if(n<=7){
            for(int i=1;i<=7;i++){
                if(s[i]==n){
                    cout<<l[i]<<endl;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
