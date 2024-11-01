#include<bits/stdc++.h>
using namespace std;
struct car
{
    int d,v0,a;
    bool overspeed;
};
struct dete
{
    int det;
    bool used;
};
int main(void)
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    for(cin>>T;T;T--)
    {
        int n,m,L,V,ans=0,ans2=0;
        vector<car> cars;
        vector<dete> detectors;
        cin>>n>>m>>L>>V;
        cars.resize(n);
        detectors.resize(m);
        for(car& temp:cars)cin>>temp.d>>temp.v0>>temp.a;
        for(dete& temp:detectors)cin>>temp.det;
        for(car& temp:cars)for(dete& det:detectors)if(det.det>=temp.d&&sqrt(temp.v0*temp.v0+2*temp.a*(det.det-temp.d))>V)
        {
            if(!temp.overspeed)det.used=true;
            temp.overspeed=true;
        }
        for(car temp:cars)ans+=temp.overspeed;
        for(dete det:detectors)ans2+=!det.used;
        cout<<ans<<' '<<ans2<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
