#include<bits/stdc++.h>
using namespace std;
long long n;
long long arr[15]={6,2,5,5,4,5,6,3,7,6};
int sticks(int x){
    if(x==1){
        return -1;
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(sum!=x){
            for(int j=1;j<=10;j++){
                sum+=arr[i];
                sticks(sum);
            }
        }
    }
    return sum;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> n;
    int a[n+1]={};
    for(int i=1;i<=n;i++){
        cin >> a[i];
        int str=sticks(a[i]);
        cout << str;
        cout << endl;
    }
    return 0;
}
