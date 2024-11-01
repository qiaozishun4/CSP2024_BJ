#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,t,a[20] = {-1,-1,1,7,4,2,6,8,10,18,22,20,28,68};
    cin>> t;
    while(t--){
        cin>> n;
        int x = n/7,y = n%7;
        if(x == 0){
            cout<< a[y];
        }
        else{
            y += 7;
            x--;
            cout<< a[y];
            for(int i=1;i<=x;i++){
                cout<< 8;
            }
        }
        cout<< endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
