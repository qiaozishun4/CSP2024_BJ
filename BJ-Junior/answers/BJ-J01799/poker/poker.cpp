#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    int sum=0;
    cin>>n;
    char a[156]={};
    char x,y;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        for(int j=1;j<=3*i;j++){
            if(a[j]==x&&a[j+1]==y){
                if(a[j+2]!='M'){
                    sum++;
                }
                a[j+2]='M';
            }
        }
        a[3*i-2]=x;
        a[3*i-1]=y;
    }
    cout<<52-n+sum;
    return 0;
}
