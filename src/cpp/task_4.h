#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

string restoreGenome(vector<string>& fragments) {
    unordered_set<char> allLetters;
    for (const string& fragment : fragments) {
        for (char c : fragment) {
            allLetters.insert(c);
        }
    }
    string genome;
    for (char letter : allLetters) {
        genome.push_back(letter);
    }
    return genome;
}

int main() {
    int n;
    cin >> n;

    vector<string> fragments(n);
    for (int i = 0; i < n; i++) {
        cin >> fragments[i];
    }

    string genome = restoreGenome(fragments);
    cout << genome << endl;

    return 0;
}
