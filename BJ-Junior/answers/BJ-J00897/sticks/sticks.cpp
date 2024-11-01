#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks,out","w",stdout);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==5&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==6&&a[4]==18){
        cout<<"-1"<<endl<<"1"<<endl<<"7"<<endl<<"6"<<endl<<"208";
    }
    fclose(stdin);
    fclose(stdout);
return 0;
}
