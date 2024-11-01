#include <iostream>
using namespace std;
long long t,n,s,m[1000005],tmp;
bool a[1000005];
struct{
    int pos,fre;
}z[1000005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for(int qw=0;qw<t;++qw){
        for(int i=0;i<1000005;++i){
            a[i]=false;
            z[i].pos=0;
            z[i].fre=0;
        }
        s=0;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>m[i];
            tmp=m[i];
            if(a[tmp]){
                s+=tmp;
            }
            a[tmp]=true;
            ++z[tmp].fre;
            z[tmp].pos=i;
        }
        cout<<s<<endl;
    }
    return 0;
}
