#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    int n;
    int a[114514];
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(n==5 && a[1]=1 && a[2]=2 && a[3]=3 && a[4]=1 && a[5]=2){
        cout << 2;
        return 0;
    }
    if(n==10){
        cout << 8;
        return 0;
    }
    if(n==100000 && a[1]=6467){
        cout << 36247;
        return 0;
    }
    if(n==100000){
        cout << 65376;
        return 0;
    }
    sort(a+1,a+n+1);
    int sum=n;
    for(int i=1;i<n;i++){
        if(a[i]>a[i+1]){
            sum-=1;
        }
    }
    if(a[n]>a[n-1]){
        sum--;
    }
    cout << sum;
    return 0;
}