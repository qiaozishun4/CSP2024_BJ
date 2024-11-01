#include <bits/stdc++.h>
using namespace std;

int t;

void dfs(){
    int n;
    int a[100005]={0};
    cin>>n;
    int i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int j;
    int num=0;
    for(i=0,j=1;i<n,j<n;i++,j++){
        if(a[i]>a[j]){
            num++;
        }
    }
    cout<<num<<endl;
}

int main(){
    int i;
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for(i=0;i<t;i++){
        dfs();
    }
    return 0;
}
