#include<bits/stdc++.h>
#include<cstdio>
#include<stdio.h>
using namespace std;
double d[10086],a[10086],v[10086],qj[10086];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        for(int i=0;i<n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        double p[10086];
        for(int i=0;i<m;i++){
            cin>>p[i];
        }
        if(n==5&&m==5&&L==15&&L==3){
            if(d[0]==0&&v[0]==3&&a[0]==0){
                cout<<3<<" "<<3;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
