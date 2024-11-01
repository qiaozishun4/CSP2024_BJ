#include <bits/stdc++.h>

using namespace std;
int a[100000];
bool ok[100000];
int main()
{

    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    memset(ok,1,sizeof(ok));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int j=0,ans=0;
    for(int i=0;i<n;i++){

        while(a[j]<=a[i]){
            j++;
            if(j==n){
                cout<<n-i;
                return 0;
            }
        }
        j++;
        if(j==n){
            cout<<n-i-1;
            return 0;
        }

    }
    fclose(stdin);
    fclose(stdout);
}
