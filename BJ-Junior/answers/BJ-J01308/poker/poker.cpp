#include <bits/stdc++.h>
using namespace std;
string a[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,pk = 52;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        int flag = 0;
        for(int j = 0;j < i;j++){
            if(a[i] == a[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            pk--;
        }
    }
    printf("%d",pk);
    return 0;
}
