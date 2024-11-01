#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.in","r",stdout);
    int n;
    cin>>n;
    int a[10000];
    int b[10000];
    b[0]=6;
    b[1]=2;
    b[2]=5;
    b[3]=5;
    b[4]=4;
    b[5]=5;
    b[6]=6;
    b[7]=3;
    b[8]=7;
    b[9]=6;
    int one,sum=0;
    int two=0;
    int ans[10000];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<=9){
            for(int j=0;j<9;j++){
                if(a[i]==b[j]){
                    ans[i]=j;
                    sum++;
                    continue;
                }
            }
            if(sum==0){
                ans[i]=-1;
                continue;
            }
        }
        else{
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i];
    }
    fclose(stdin);
    fclose(stdout);
}