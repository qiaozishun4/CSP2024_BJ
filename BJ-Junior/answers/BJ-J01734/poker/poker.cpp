#include <bits/stdc++.h>
using namespace std;
int n,sum=0;
char a[62];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    sum=52-n;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(a[i]==a[j])
                sum++;
        }
    }
    cout<<sum;
    return 0;
}
