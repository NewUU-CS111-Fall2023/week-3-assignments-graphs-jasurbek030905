#include <iostream>
#include <queue>
#include <map>
#include <stack>

using namespace std;

void printTransformationSequence(int a, int b, map<int, int> &previous) {
    stack<int> sequence;
    int current = b;

    while (current != a) {
        sequence.push(current);
        current = previous[current];
    }

    sequence.push(a);

    cout << "YES" << endl;
    cout << sequence.size() << endl;

    while (!sequence.empty()) {
        cout << sequence.top() << " ";
        sequence.pop();
    }
}

void transformNumber(int a, int b) {
    queue<int> numbers;
    map<int, int> previous;

    numbers.push(a);
    previous[a] = -1;

    while (!numbers.empty()) {
        int current = numbers.front();
        numbers.pop();

        if (current == b) {
            printTransformationSequence(a, b, previous);
            return;
        }

        int next1 = current * 2;
        int next2 = current * 10 + 1;

        if (next1 <= b && previous.find(next1) == previous.end()) {
            numbers.push(next1);
            previous[next1] = current;
        }

        if (next2 <= b && previous.find(next2) == previous.end()) {
            numbers.push(next2);
            previous[next2] = current;
        }
    }

    cout << "NO" << endl;
}

int main() {
    int a, b;
    cin >> a >> b;

    transformNumber(a, b);

    return 0;
}
