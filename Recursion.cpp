
#include <iostream>

using namespace std;

long iterFact(int n) {

    long result =1;
    for (int i=1; i<=n; i++) {
        result *= i;
    }
    return result;

}

long recFact(int n) {
    if (n == 1) return 1;
    return (n * recFact(n-1));
}

int main() {

    cout << "Factorial(4) = " << recFact(4) << endl;

}