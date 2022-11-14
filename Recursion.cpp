
#include <iostream>
#include <vector>

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


bool iterIsPalindrome(string w){

    for (int i=0; i<w.size()/2; i++) {
        if (w[i] != w[w.size() - i - 1]) return false;
    }
    return true;
}


bool recIsPalindrome(string w) {

    if (w.size() <= 1) return true;
    return ((w[0] == w[w.size() - 1]) && recIsPalindrome(w.substr(1,w.size()-2)));

}

vector<string> genPermutations(string w) {

    vector<string> result;
    if (w.size() <=1) {
        result.push_back(w);
        return result;
    }
    for (int i=0; i<w.size(); i++) {
        string letterRemoved = w.substr(i,1);
        string shorterWord = w.substr(0,i) + w.substr(i+1,w.size()-i-1);
        vector<string> shorterPerms = genPermutations(shorterWord);
        for (int j=0; j<shorterPerms.size(); j++) {
            result.push_back(letterRemoved + shorterPerms[j]);
        }

    }
    return result;

}



int maze[6][6] =
    {
        {2, 2, 2, 0, 3, 0},
        {0, 0, 2, 0, 0, 2},
        {0, 0, 2, 2, 2, 2},
        {0, 0, 0, 0, 0, 2},
        {0, 2, 2, 2, 2, 2},
        {0, 0, 0, 2, 0, 0}};

bool findCheese(int row, int col)
{
    if ((row < 0) || (row > 5)) {
        // Mouse outside the maze
        return false;
    }
    if ((col < 0) || (col > 5)) {
        // Mouse outside the maze 
        return false;
    }
    if (maze[row][col] == 0) {
        // Mouse hit a wall
        return false;
    }
    if (maze[row][col] == 3) {
        // Mouse found cheese
        return true;
    }
    if (maze[row][col] == -1) {
        // Mouse revisited a space
        return false;
    }

    maze[row][col] = -1; // Mark the spot

    if (findCheese(row,col+1)) return true; // Search right
    if (findCheese(row+1,col)) return true; // Search down
    if (findCheese(row,col-1)) return true; // Search left
    if (findCheese(row-1,col)) return true; // Search up

    return false;

}

int main() {

    // for (int i = 0; i < 10; i++)
    //     cout << "iterFactorial(" << i << ") = " << iterFactorial(i) << endl;

    // for (int i = 0; i < 10; i++)
    //     cout << "recFactorial(" << i << ") = " << recFactorial(i) << endl;

    // for (int i = 0; i <= 50; i++)
    //     cout << "iterFibo(" << i << ") = " << iterFibo(i) << endl;

    // for (int i = 0; i <= 50; i++)
    //     cout << "recFibo2(" << i << ") = " << recFibo2(i) << endl;

    // for (int i = 0; i <= 50; i++)
    //     cout << "recFibo(" << i << ") = " << recFibo(i) << endl;

    // cout << iterIsPalindrome("radar") << endl;

    // vector<string> eatPerms = genPermutations("Bienvenido");

    // for (int i=0; i<eatPerms.size(); i++) {
    //     cout << "Next word is: " << eatPerms[i] << endl;
    // }

    cout << findCheese(0,0) << endl;

    exit(0);
}