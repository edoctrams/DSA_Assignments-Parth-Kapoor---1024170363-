#include <iostream>
using namespace std;
int main() {
    int arr[100], n=0, choice, pos, val, key, i, j;
    while (1) {
        cout << "\n---MENU---\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter number of elements: ";
                cin >> n;
                cout << "Enter elements: ";
                for (i=0;i<n;i++) cin >> arr[i];
                break;
            case 2:
                cout << "Array: ";
                for (i=0;i<n;i++) cout << arr[i] << " ";
                break;
            case 3:
                cout << "Enter position and value: ";
                cin >> pos >> val;
                for (i=n;i>pos;i--) arr[i]=arr[i-1];
                arr[pos]=val; n++;
                break;
            case 4:
                cout << "Enter position: ";
                cin >> pos;
                for (i=pos;i<n-1;i++) arr[i]=arr[i+1];
                n--;
                break;
            case 5:
                cout << "Enter key: ";
                cin >> key;
                for (i=0;i<n;i++) {
                    if (arr[i]==key) { cout<<"Found at "<<i; break; }
                }
                if (i==n) cout<<"Not found";
                break;
            case 6:
                return 0;
        }
    }
}
