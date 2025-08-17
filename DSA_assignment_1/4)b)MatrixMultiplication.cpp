#include <iostream>
using namespace std;
int main() {
    int a[10][10], b[10][10], c[10][10];
    int n,m,p,q;
    cin >> n >> m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) cin >> a[i][j];
    cin >> p >> q;
    for (int i=0;i<p;i++)
        for (int j=0;j<q;j++) cin >> b[i][j];
    if (m!=p) { cout<<"Not possible"; return 0; }
    for (int i=0;i<n;i++)
        for (int j=0;j<q;j++) {
            c[i][j]=0;
            for (int k=0;k<m;k++) c[i][j]+=a[i][k]*b[k][j];
        }
    for (int i=0;i<n;i++) {
        for (int j=0;j<q;j++) cout<<c[i][j]<<" ";
        cout<<endl;
    }
}
