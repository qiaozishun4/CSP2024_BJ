include<bits/stdc++.h>
#define maxn 100001
using namespace std;
int a[maxn],n,k,im,ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >>n;
    for(int i=0;i<n;i++){
        cin >>k;
        a[k]++;
        if(k>im)im=k;
    }
    for(int i=1;i<=im;i++){
        if(a[i]>ans)ans=a[i];
    }
    cout <<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
