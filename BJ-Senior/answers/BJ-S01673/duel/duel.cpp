#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int n;
int a[100005];
int ass[100005];
int cnt=0;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int p=0;
    for(int i=0;i<n;i++){
        ass[p]++;
        if(a[i]!=a[i+1]){
            p++;
            ass[p]=ass[p-1];
        }
    }
    p--;

    for(int i=1;i<=p;i++){
        int cur=ass[i]-ass[i-1];
        for(int j=i;j<=p;j++)
            ass[j]-=min(ass[i-1],cur);
    }
    cout<<ass[p];

    fclose(stdin);
    fclose(stdout);
    return 0;
}