#include<bits/stdc++.h>
using namespace std;
int a[100000][2];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    for(int o=0;o<T;o++){
        long long n;
        long long ans = 0;
        long long max = 0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i][0];
            a[i][1] = 0;
        }
        if(n>=45){
            cout<<a[n-1][0]*(n-1)<<endl;
        }
        else{
            for(;a[n-1][1]!=2;){
            ans = 0;
            for(int i=1;i<n;i++){
                for(int j=i-1;j>=0;j--){
                    if(a[j][1]==a[i][1]){
                        if(a[j][0]==a[i][0]){
                            ans += a[i][0];
                        }
                        j = -1;
                    }
                }
            }
            if(max<ans){
                max = ans;
            }
            a[0][1]++;
            for(int i=0;i<n-1;i++){
                if(a[i][1]==2){
                    a[i][1] = 0;
                    a[i+1][1] ++;
                }
            }
        }
        cout<<max<<endl;
        }
        
    }
    return 0;
}