#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	for (int i=1;i<=t;i++){
        int n,m,l,v,cnt=0;
        cin>>n>>m>>l>>v;
        int a[n][2];
        for (int j=0;j<n;j++){
            int d,v0,a0;
            cin>>d>>v0>>a0;
            double s=(pow(v,2)-pow(v0,2))/(a0*2);
            if (v0<=v&&(a0<=0||s>=l-d)) a[j][0]=a[j][1]=0;
            else if (v0<=v&&a0>0&&s<l-d){
                a[j][0]=floor(s)+d+1;
                a[j][1]=l+1;
            }
            else if (v0>v&&a0<0&&s>0){
                a[j][0]=d;
                a[j][1]=ceil(s)+d;
            }
            else{
                a[j][0]=d;
                a[j][1]=l+1;
            }
        }
        vector<int> r[n];
        for (int j=0;j<m;j++){
            int x;
            cin>>x;
            for (int k=0;k<n;k++){
                if (a[k][0]<=x&&a[k][1]>x) r[k].push_back(j);
                cout<<j<<k;
            }
        }
        for (int j=0;j<n;j++) if (r[j].size()) cnt++;
        cout<<cnt<<" "<<cnt<<endl;
	}
	return 0;
}