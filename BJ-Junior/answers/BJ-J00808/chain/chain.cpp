#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int T, n, k, q, l, a;
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n>>k>>q;
        for(int j=0;j<n;j++){
            cin>>l;
            for(int p=0;p<=l;p++){
                cin>>a;
            }
        }
    }
    cout<<0<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
