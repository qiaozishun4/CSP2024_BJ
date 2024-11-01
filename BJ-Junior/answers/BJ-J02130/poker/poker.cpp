#include<iostream>
#include<algorithm>
using namespace std;
string a[60];int n;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int cnt=unique(a+1,a+n+1)-a-1;
    printf("%d",52-cnt);return 0;
}
