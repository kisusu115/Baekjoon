#include <iostream>
#include <string>

using namespace std;

string a;
int arr[26];

int main() {
    int max = 0;
    int size;
    char ans;

    cin >> a;
    size = a.length();

    for (int i = 0; i < size; i++)
        if (a[i] >= 'a') arr[a[i] - 'a']++;
        else arr[a[i] - 'A']++;

    for (int i = 0; i < 26; i++)
        if (arr[i] == max) {
            ans = '?';
        }
        else if (arr[i] > max) {
            max = arr[i];
            ans = 'A' + i;
        }

    cout << ans;

    return 0;
}