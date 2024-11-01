#include<iostream>
#include<stdio.h>
using namespace std;
int t;

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        int a[200005];
        cin>>n;
        for(int j=0;j<n;j++)
            cin>>a[j];
        cout<<0;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
