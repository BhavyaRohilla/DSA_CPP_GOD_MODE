#include <iostream>
using namespace std;

/*
🌳 TREE RECURSION - Complete Explanation
----------------------------------------

🧠 Definition:
Tree recursion occurs when a function calls itself **more than once** inside its body.
It creates a tree-like structure of recursive calls.

💡 Example: Fibonacci Sequence
    fibonacci(n) = fibonacci(n - 1) + fibonacci(n - 2)
    Base cases:
        fibonacci(0) = 0
        fibonacci(1) = 1

🎯 Characteristics:
- Each call creates 2 more calls → forming a binary tree structure 🌲
- Many overlapping subproblems (e.g., fibonacci(3) calculated multiple times)

🧾 Example Output for n = 5:
    fib(0) = 0
    fib(1) = 1
    fib(2) = 1
    fib(3) = 2
    fib(4) = 3
    fib(5) = 5

⏱ Time Complexity:
    ❌ O(2^n) - Exponential due to repeated calls

🧠 Space Complexity:
    ✅ O(n) - Maximum depth of recursive stack is 'n' in worst case

📍 Note:
Tree recursion is **not efficient** without optimization (like memoization or DP),
but it's great to understand recursion structure!
*/

// 🌿 Tree Recursive Fibonacci Function
int fibonacci(int n)
{
    if (n <= 1)
        return n;

    // Two recursive calls = Tree Recursion 🌳
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 🚀 Main function
int main()
{
    int n = 5;

    cout << "🌳 TREE RECURSION DEMO - Fibonacci Series up to " << n << ":\n";
    cout << "----------------------------------------------\n";

    for (int i = 0; i <= n; i++)
    {
        cout << "📦 fib(" << i << ") = " << fibonacci(i) << endl;
    }

    return 0;
}

/*
OUTPUT:
======

🌳 TREE RECURSION DEMO - Fibonacci Series up to 5:
----------------------------------------------
📦 fib(0) = 0
📦 fib(1) = 1
📦 fib(2) = 1
📦 fib(3) = 2
📦 fib(4) = 3
📦 fib(5) = 5


*/