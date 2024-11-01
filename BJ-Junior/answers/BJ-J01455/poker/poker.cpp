#include<bits/stdc++.h>
using namespace std;
int n,sum = 52,flag;
string t;
string a[55];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> t;
        for(int j = 0;j <= i;j++){
            if(t == a[j]) flag = 1;
        }
        a[i] = t;
        if(flag == 0) sum -= 1;
        flag = 0;
    }
    cout << sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}