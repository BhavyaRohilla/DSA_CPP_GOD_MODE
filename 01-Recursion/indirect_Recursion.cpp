/*
🔁 INDIRECT RECURSION
------------------------

🧠 Definition:
Indirect recursion occurs when **two or more functions call each other in a circular way**.

📦 Example:
    funcA() → funcB() → funcA() → ...

🔥 Real-world analogy:
    🔁 Manager assigns to Assistant → Assistant sends back to Manager → Loop continues

📍 Used in state machines, grammars, alternating logic, etc.

🧠 Example Code:
We'll print all even and odd numbers from `n` down to 1 using indirect recursion.
- evenPrinter(n): prints if even, then calls oddPrinter(n - 1)
- oddPrinter(n): prints if odd, then calls evenPrinter(n - 1)
*/

#include <iostream>
using namespace std;

// 🔁 Function Declarations for mutual calling
void printEven(int n);
void printOdd(int n);

/*
🔷 EVEN NUMBER PRINTER
If n is even, it prints n and calls printOdd(n - 1)
*/
void printEven(int n)
{
    if (n <= 0)
        return;

    if (n % 2 == 0)
        cout << "🔷 Even: " << n << endl;

    printOdd(n - 1); // 🔁 Indirect recursive call
}

/*
🔶 ODD NUMBER PRINTER
If n is odd, it prints n and calls printEven(n - 1)
*/
void printOdd(int n)
{
    if (n <= 0)
        return;

    if (n % 2 != 0)
        cout << "🔶 Odd: " << n << endl;

    printEven(n - 1); // 🔁 Indirect recursive call
}

/*
🚀 MAIN FUNCTION
Starts the indirect recursion by calling printEven(n)
*/
int main()
{
    int n = 10;

    cout << "🔁 INDIRECT RECURSION DEMO: Printing numbers from " << n << " to 1\n";
    cout << "------------------------------------------------------\n";

    printEven(n); // Starts the mutual call chain

    return 0;
}

/*
🔁 INDIRECT RECURSION DEMO: Printing numbers from 10 to 1
------------------------------------------------------
🔷 Even: 10
🔶 Odd: 9
🔷 Even: 8
🔶 Odd: 7
🔷 Even: 6
🔶 Odd: 5
🔷 Even: 4
🔶 Odd: 3
🔷 Even: 2
🔶 Odd: 1

*/