#include<bits/stdc++.h>
using namespace std;
long long n,a[100004],mx=0,last,p=1,lpos,dic[100003];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    last = a[1],lpos=1;
    for(int i=1;i<=n+1;i++){
        if(last != a[i]){
            dic[p++]=i-lpos;
            last = a[i],lpos = i;
        }
    }
    mx=-0x7fffffff;
    for(int i=1;i<=p;i++)if(dic[i]>mx)mx=dic[i];
    cout<<mx;
    fclose(stdin);fclose(stdout);
    return 0;
}
