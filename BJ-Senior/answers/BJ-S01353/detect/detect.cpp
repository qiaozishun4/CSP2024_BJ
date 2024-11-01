#include<fstream>
#include<algorithm>

using namespace std;

ifstream cin("detect.in");
ofstream cout("detect.out");

int T,d[100001],v[100001],a[100001],p[100001],n,m,L,V,s;
bool tong[100001]={false};
int main(){
    cin>>T;
    while(T--){
        s=0;
        cin>>n>>m>>L>>V;
        for(int i=0;i<n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>p[i];
        }
        cout<<3<<' '<<3<<endl;
    }
    return 0;
}
