#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int a[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int check(int x){
    int num=0;
    while(x>0){
        num+=a[x%10];
        x/=10;
    }
    return num;
}
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        bool f=0;
        int n;
        cin>>n;
        for(int i=1;i<=100005;i++){
            if(check(i)==n){
                cout<<i<<"\n";
                f=1;
                break;
            }
        }
        if(f==0)cout<<"-1\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
