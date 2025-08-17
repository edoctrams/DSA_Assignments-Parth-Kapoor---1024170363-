#include <iostream>
using namespace std;
long long mergeCount(int a[], int l, int r) {
    if (l >= r) return 0;
    int m = (l+r)/2;
    long long inv = mergeCount(a,l,m) + mergeCount(a,m+1,r);
    int n1 = m-l+1, n2 = r-m;
    int L[100], R[100];
    for (int i=0;i<n1;i++) L[i] = a[l+i];
    for (int j=0;j<n2;j++) R[j] = a[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else { a[k++] = R[j++]; inv += n1-i; }
    }
    while(i<n1) a[k++] = L[i++];
    while(j<n2) a[k++] = R[j++];
    return inv;
}
int main() {
    int n; cin >> n;
    int a[100];
    for (int i=0;i<n;i++) cin >> a[i];
    cout << mergeCount(a,0,n-1);
}
