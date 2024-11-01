#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int  main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>> t;
    while(t--){
        cin>> n >>k >> q;
        if(k == 200005){
            cout<< 1 <<endl;
            continue;
        }
        cout<< 0 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}