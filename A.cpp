#include <iostream>
using namespace std;
int T=0,x,y,z;
int main() {
    cin>>T;
    while(T--) {
        cin>>x>>y>>z;
        x=x/2;
        int n=min(x,y);
        cout<<min(n,z)<<endl;
    }
    return 0;
}