include<bits/stdc++.h>
using namespace std;
int n;
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("arene.in","r","in.txt");
    freopen("arene.out","w","out.txt");
    cin>>n;
    int a[10005];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n,cmp);
    int ans=n;
    for(int j=0;j<n;j++){
        if(a[j]<a[j+1]){
            n--;
        }

    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
