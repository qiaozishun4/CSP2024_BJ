#include<bits/stdc++.h>
using namespace std;
int ca[10005]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("stilcks.in","r",stdin);
    freopen("stilcks.out","w",stdout);
    int n,t;
    cin >> t;
    while(t--){
        cin >> n;
        if(!(n%7)){
            int w=n/7;
            while (w--) putchar('8');
            putchar('\n');
            continue;
        }
    }
}
