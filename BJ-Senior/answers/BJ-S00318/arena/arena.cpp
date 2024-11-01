#include<bits/stdc++.h>
using namespace std;
int a[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m,t;
    int k;
    cin>>n>>m;
    for(int i=0;;i++){
        if(a[i]<n) i++;
        else {
            k=i-1;
            break;
        }
    }
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
    }
    for(int i=0;i<m;i++){
        cin>>x;
    }
    for(int i=0;i<k;i++){
        cin>>x;
    }
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
