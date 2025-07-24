#include <iostream>
using namespace std;

/*
🔁 Recursive Sum Function (fun1)
--------------------------------
Returns the sum of first 'n' natural numbers using pure recursion.
Example: sumOfNaturalNumbers(5) = 5 + 4 + 3 + 2 + 1 = 15
*/
int sumOfNaturalNumbers(int n)
{
    if (n > 0)
    {
        return sumOfNaturalNumbers(n - 1) + n;
    }
    return 0;
}

/*
🧠 Static Counter Sum (fun2)
-----------------------------
Uses a static variable `counter` which increments only AFTER it's added.
⚠️ Because of post-increment (counter++), the first added value is 0.
Result is: 0 + 1 + 2 + 3 + 4 = 10
*/
int sumUsingStaticPostIncrement(int n)
{
    static int counter = 0; // persists across recursive calls
    if (n > 0)
    {
        return sumUsingStaticPostIncrement(n - 1) + counter++;
    }
    return 0;
}

/*
🚀 Static Counter Sum with Pre-Increment (fun3)
-----------------------------------------------
Uses a static variable `counter` which is incremented BEFORE it's added.
So we start adding from 1 instead of 0.
Result is: 1 + 2 + 3 + 4 + 5 = 15
*/
int sumUsingStaticPreIncrement(int n)
{
    static int counter = 0; // persists across recursive calls
    if (n > 0)
    {
        ++counter; // pre-increment
        return sumUsingStaticPreIncrement(n - 1) + counter;
    }
    return 0;
}

int main()
{
    cout << "🔁 Sum of first 5 natural numbers (Pure Recursion): " << sumOfNaturalNumbers(5) << endl;
    cout << "🧠 Sum using static variable (Post-Increment): " << sumUsingStaticPostIncrement(5) << endl;
    cout << "🚀 Sum using static variable (Pre-Increment): " << sumUsingStaticPreIncrement(5) << endl;

    return 0;
}

/*
OUTPUT
------

🔁 Sum of first 5 natural numbers (Pure Recursion): 15
🧠 Sum using static variable (Post-Increment): 10
🚀 Sum using static variable (Pre-Increment): 15


*/