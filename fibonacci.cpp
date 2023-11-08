#include <iostream>
using namespace std;

int fibonacciNonRecursive(int n) {
    if (n <= 1) {
        return n;
    }
    int prev = 0, current = 1, next;
    for (int i = 2; i <= n; ++i) {
        next = prev + current;
        prev = current;
        current = next;
    }
    return current;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "Fibonacci number at position " << n << " is: " << fibonacciNonRecursive(n) << endl;
    return 0;
}
