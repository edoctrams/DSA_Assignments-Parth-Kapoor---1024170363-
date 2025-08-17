#include <iostream>
using namespace std;
struct Triplet { int r,c,v; };
int main() {
    int r,c,n;
    cin >> r >> c >> n;
    Triplet a[100], t[100];
    for (int i=0;i<n;i++) cin >> a[i].r >> a[i].c >> a[i].v;
    for (int i=0;i<n;i++) {
        t[i].r = a[i].c;
        t[i].c = a[i].r;
        t[i].v = a[i].v;
    }
    for (int i=0;i<n;i++)
        cout<<t[i].r<<" "<<t[i].c<<" "<<t[i].v<<endl;
}
