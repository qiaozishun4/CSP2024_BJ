#include<bits/stdc++.h>
#include<cstdio>
#include<stdio.h>
using namespace std;
int main(){
   freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int a[10086];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,greater<int>());
    bool flag[10086]={false};
    int cnt=n;
    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            if(a[j]==a[i]||flag[j]==true){
                continue;
            }
            else{
                flag[j]=true;
                cnt--;
                for(int k=n;k>i;k--){
                    a[j]=a[j-1];
                }
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
