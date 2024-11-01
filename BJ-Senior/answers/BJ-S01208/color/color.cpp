#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005],c[200005],flag,cnt = -1,sum;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> t;
    c[0] = 0;
    while(t--){
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(a[i] == a[j]) flag = 1;
            }
        }
        if(flag == 0){
            cout << 0;
        }
        else{
            for(int i = 0;i < n;i++){
                for(int j = 0;j < n;j++){
                    if(a[i] == a[j]) cnt++;
                }
                if(cnt > 0) sum += (cnt-1)*a[i];
            }
            cout << sum << endl;
        }
        sum = 0;
        cnt = 0;
        flag = 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
