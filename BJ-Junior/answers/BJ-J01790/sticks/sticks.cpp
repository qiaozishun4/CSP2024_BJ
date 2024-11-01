#include<bits/stdc++.h>
using namespace std;
int t,n,sum,a[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks1.in","r",stdin);
    freopen("sticks1.out","w",stdout);
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> n;
        if(n==1){
            cout << -1;
            continue;
        }int x,m=1,y;
        while(true){
            y=m;
            while(m>=10){
                x=m/10;
                m%=10;
                sum+=a[x];
            }
            if(sum==n){
                cout << m;
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
