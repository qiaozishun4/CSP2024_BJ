#include <iostream>
using namespace std;
char a[55][5];
long long n,ans;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i][1]=a[j][1]&&a[i][2]==a[j][2]){
                ans++;
            }
        }
    }
    cout<<52-n+ans;
    return 0;
}