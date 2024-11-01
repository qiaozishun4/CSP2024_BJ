#include <bits/stdc++.h>
using namespace std;
int num[10]  = {6,2,5,5,4,5,6,3,7,6};
int T;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    int ans[T];
    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        for(int j=ceil(n/7.0);j>=1;j--){
            if(n ==1){
                ans[T] = -1;
                break;
            }
            int x = n - (ceil(n/7.0)-1) * 7;
            if(x == 1) {
                ans[T] = -1;
                break;
            }
            for(int k=0;k<=9;k++){
                if(x == num[k])
                {
                    ans[T] = k * pow(10,ceil(n/7.0)-1);
                    break;
                }
            }
        }
    }
    for(int i=0;i<T;i++)
    {
        cout<<ans[T]<<endl;
    }
    return 0;
}

