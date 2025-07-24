#include <iostream>
using namespace std;

/*
🔁 HEAD RECURSION
-----------------------
🧠 Definition:
In Head Recursion, the function calls itself first,
and then performs the remaining operations **after** the recursive call.

💡 So processing happens during the **return phase**.
🧾 Example: To print 1 to N using head recursion,
the output will be printed in reverse order (1 to N).
*/
void headRecursion(int n)
{
    if (n > 0)
    {
        headRecursion(n - 1);             // 🔁 Recursive call happens first
        cout << "🔁 Head: " << n << endl; // 📤 Processing after recursion
    }
}

/*
🔂 TAIL RECURSION
-----------------------
🧠 Definition:
In Tail Recursion, the function performs the necessary operations first,
and then calls itself at the **end** of the function.

💡 So processing happens during the **call phase** itself.
🧾 Example: To print N to 1 using tail recursion,
the output will be printed in same order (N to 1).
*/
void tailRecursion(int n)
{
    if (n > 0)
    {
        cout << "🔂 Tail: " << n << endl; // 📤 Processing before recursion
        tailRecursion(n - 1);             // 🔂 Recursive call at the end
    }
}

/*
🚀 MAIN FUNCTION
-----------------------
Calls both headRecursion() and tailRecursion() with n = 5
and demonstrates the difference.
*/
int main()
{
    int n = 5;

    cout << "\n🔁 HEAD RECURSION OUTPUT (1 to " << n << "):\n";
    headRecursion(n);

    cout << "\n🔂 TAIL RECURSION OUTPUT (" << n << " to 1):\n";
    tailRecursion(n);

    return 0;
}

/*

🔁 HEAD RECURSION OUTPUT (1 to 5):
🔁 Head: 1
🔁 Head: 2
🔁 Head: 3
🔁 Head: 4
🔁 Head: 5

🔂 TAIL RECURSION OUTPUT (5 to 1):
🔂 Tail: 5
🔂 Tail: 4
🔂 Tail: 3
🔂 Tail: 2
🔂 Tail: 1


*/