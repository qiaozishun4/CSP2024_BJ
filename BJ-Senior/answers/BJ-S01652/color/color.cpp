#include <bits/stdc++.h>

using namespace std;
const int N=1e6+5;
long long M;
int n,a[N];
int s[N];//1表示红色，0表示蓝色，-2表示没有颜色
int ans;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&M);
    for(int aa=0;aa<M;aa++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(int i=0;i<n;i++){
            if(a[i]==a[i+1]) ans+=a[i];
        }
        printf("%d\n",ans);
        ans=0;
    }
    return 0;
}
