#include<iostream>
#include<cstdio>
using namespace std;
int n,a[200001],c[200001]={},cnt=0,ma=0,t;
bool findm(int j){
    for(int i=j-1;i>=0;i--){
        if(c[i]==c[j]&&a[i]==a[j]){
                return 1;
        }

    }
    return 0;
}
int s(int j){
    int ans=0;
    for(int i=j;i>0;i--)
        if(findm(i))
            ans+=a[i];
    return ans;
}
void m(int i){
    if(i==n){
        if(s(n)>ma){
            ma=s(n);
        }
        c[i]=!c[i];
        if(s(n)>ma){
            ma=s(n);
        }
        return;
    }
    m(i+1);
    c[i]=!c[i];
    m(i+1);
    return;

}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        ma=0;
        for(int j=0;j<n;j++){
            c[j]=0;
        }
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        m(0);
        cout<<ma<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;

}
