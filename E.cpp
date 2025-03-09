#include <iostream>
#include <string>
using namespace std;
int T;
int main() {
    cin>>T;
    while(T--) {
        int n;
        string s;
        cin>>n;
        cin>>s;
        if (s.length()==1) {
            if (s[0]=='0')cout<<"Bob"<<endl;
            else if (s[0]=='1')cout<<"Alice"<<endl;
        }
        else {
            if (s[0]=='0'&&s.back()=='0')cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }
    }

    return 0;
}