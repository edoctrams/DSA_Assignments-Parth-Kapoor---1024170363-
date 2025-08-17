#include <iostream>
using namespace std;
int main() {
    int n,m,a[10][10],t[10][10];
    cin >> n >> m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) cin >> a[i][j];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) t[j][i]=a[i][j];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) cout<<t[i][j]<<" ";
        cout<<endl;
    }
}
