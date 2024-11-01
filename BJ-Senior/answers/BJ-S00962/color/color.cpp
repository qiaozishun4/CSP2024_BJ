#include<bits/stdc++.h>
using namespace std;

int a[200005],cr[200005];
bool iss(int a[],n){
    int b[200005];
    for(int i=1;i<=n;i++){
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        if(b[i]!=a[i]) return false;
    }
    return true;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;      
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>> a[i];
        }
        if(iss(a,n)){
            cout<<0<<endl;
            continue;
        }
        int maxcnt=0;
        for(int i=0;i<(1<<n);i++){
            int cnt=0;
            int i1=i;
            int count=1;
            while(i1){
                cr[count]=i1%2;
                i1>>=1;
                count++;
            }
            for(int i=1;i<=n;i++){
                for(int j=i-1;j>=1;j--){
                    if(cr[j]==cr[i] && a[j]==a[i]){
                        cnt+=a[j];
                    }
                }
            }
            maxcnt=max(maxcnt,cnt);
        }
        cout<<maxcnt<<endl;
    }
    fclose(stdin);
    fclose(stdout); 
    return 0;
}