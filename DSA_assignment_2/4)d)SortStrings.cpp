#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int n; cin >> n;
    char a[10][100], t[100];
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
            if (strcmp(a[i],a[j])>0) {
                strcpy(t,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],t);
            }
    for (int i=0;i<n;i++) cout<<a[i]<<" ";
}
