
#include <iostream>

using namespace std;

long iterFactorial(int n) {

    long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

long recFactorial(int n) {
    if (n == 0 || n == 1) return 1;
    return (n * recFactorial(n - 1));
}

long iterFibo(unsigned int n) {

    long f0 = 0;
    long f1 = 1;

    long f2 = f0 + f1;

    for (int i = 2; i <= n; i++) {

        f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
    }

    return f2;
}

long recFibo(unsigned int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    return recFibo(n - 1) + recFibo(n - 2);
}

long recFibo2Helper(unsigned int n, long f0, long f1) {
    if (n == 0) return f0;
    return recFibo2Helper(n - 1, f1, f0 + f1);
}

long recFibo2(unsigned int n) {
    return recFibo2Helper(n, 0, 1);
}

int main() {

    for (int i = 0; i < 10; i++)
        cout << "iterFactorial(" << i << ") = " << iterFactorial(i) << endl;

    for (int i = 0; i < 10; i++)
        cout << "recFactorial(" << i << ") = " << recFactorial(i) << endl;

    for (int i = 0; i <= 50; i++)
        cout << "iterFibo(" << i << ") = " << iterFibo(i) << endl;

    for (int i = 0; i <= 50; i++)
        cout << "recFibo2(" << i << ") = " << recFibo2(i) << endl;

    for (int i = 0; i <= 50; i++)
        cout << "recFibo(" << i << ") = " << recFibo(i) << endl;
}