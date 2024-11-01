#include <iostream>
#include <algorithm>
#define For(v,s,e) for(int v=s;v<=e;v++)
using namespace std;
struct car{
    int d,v,a;
}cars[1000038];
inline bool cmp(car p1,car p2){
    return p1.d<p2.d;
}
int test[1000038],out[1000038];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	for(;T--;){
        int n,m,l,v;
        cin>>n>>m>>l>>v;
        For(i,1,n)cin>>cars[i].d>>cars[i].v>>cars[i].a;
        For(i,1,m){
            int tmp1;
            cin>>tmp1;
            out[tmp1]=1203;
        }
        sort(cars+1,cars+n+1,cmp);
        int c=0;
        For(i,1,n){
            if(cars[i].v>v){
                For(j,cars[i].d,l){
                    if(out[j]==1203){
                        c++;
                        break;
                    }
                }
            }
        }
        if(c==0)m++;
        cout<<endl<<c<<' '<<m-1<<endl;
	}
	return 0;
}

