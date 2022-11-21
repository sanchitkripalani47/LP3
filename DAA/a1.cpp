#include<iostream>
using namespace std;

// Recursive Function to return nth fibonacci number
int fibRec(int n) {
    if (n <= 1) return n;
    return fibRec(n-1) + fibRec(n-2);
}

// Iterative Function to return nth fibonacci number
int fibIter(int n) {
    int first = 0, second = 1, third = 1;
    for (int i=2; i<=n; i++) {
        third = first + second;
        first = second;
        second = third;
        // cout << second << " " << third << endl;
    }

    return second;
}

int main() {

    cout << fibRec(2);
    cout << "\n" << fibIter(2);

    return 0;
}