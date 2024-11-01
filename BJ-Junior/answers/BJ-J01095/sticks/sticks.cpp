#include<bits/stdc++.h>
using namespace std;
int s,n,num;
int a[10] = {6,2,5,5,4,5,6,3,7,6};
int b[110],c,z[1010];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s;
        if(s == a[i]){
            c= min(c,i);
            z[i] = c;
        }
        if(s > 10){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    num+=a[k];
                    b[k] == i;;
                    if(num == s){
                        c += min(b[k],b[k-1]);
                        if(c == 0){
                            z[i] = -1;
                        }
                        else z[i] = c;
                    }
                }
            }
        }
        num = 0;
        c = 0;
    }
    for(int i=1;i<=n;i++){
        cout << z[i];
    }
    return 0;
}
