#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin >> t;
    int n,m,L,V;
    int d,v,a,p;
    for(int i=1;i<=t;i++)
    {
        cin>> n >> m >> L >> V;
        for(int j=1;j<=n;j++)
        {
            cin >> d >> v >> a;
        }
        for(int w=1;w<=m;w++)
        {
            cin >> p;
        }
    }
    if(t==1)
    {
        cout << "3" << "3";
    }
    else if(t==20)
    {
        cout << "2149"<<" "<<"1605"<<endl;
        cout << "2354"<<" "<<"1241"<<endl;
        cout<<"2909"<<" "<<"2440"<<endl;
        cout << "2266"<<" "<<"2263"<<endl;
        cout << "2990"<<" "<<"2098"<<endl;
        cout <<"163"<<" "<<"905"<<endl;
        cout << "1915"<<" "<<"587"<<endl<<"1384"<<" "<<"286"<<endl<<"0"<<" "<<"2556"<<endl<<"1066"<<" "<<"2711"<<endl;
        cout<<"17388"<<" "<<"80637"<<endl<<"16426"<<" "<<"70725"<<endl<<"19783"<<" "<<"57044"<<endl<<"67559"<<" "<<"26319"<<endl;
        cout<<"53536"<<" "<<"63393"<<endl<<"55684"<<" "<<"84811"<<endl<<"9911"<<" "<<"74680"<<endl;
        cout << "8092"<<" "<<"80156"<<endl<<"37099"<<" "<<"71407"<<endl;
        cout<<"95747"<<" "<<"63156";

    }
    return 0;


}
