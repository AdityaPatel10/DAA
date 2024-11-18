#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> computeLPS(const string &pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int length = 0; 
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1]; 
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
void KMPsearch(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = computeLPS(pattern);
    int i = 0;
    int j = 0; 
    vector<int> occurrences; 
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) { 
            occurrences.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1]; 
            } else {
                i++;
            }
        }
    }
    if (occurrences.empty()) {
        cout << "Pattern not found in the text." << endl;
    } else {
        cout << "Pattern found at indices: ";
        for (int index : occurrences) {
            cout << index << " ";
        }
        cout << endl;
    }
}
int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);
    KMPsearch(text, pattern);
    return 0;
}