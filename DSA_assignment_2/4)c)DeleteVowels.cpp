#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char s[100];
    cin.getline(s,100);
    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];
        if (c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u'&&
            c!='A'&&c!='E'&&c!='I'&&c!='O'&&c!='U')
            cout << c;
    }
}
