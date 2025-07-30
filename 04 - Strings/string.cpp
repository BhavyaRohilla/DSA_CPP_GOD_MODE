#include <iostream>
#include <string>    // Important for std::string
#include <algorithm> // For reverse
using namespace std;

int main()
{
    // 1. Declaration and Initialization
    string s1 = "Hello";
    string s2("World");
    string s3;

    // 2. Input without spaces
    cout << "Enter a word (no spaces): ";
    cin >> s3;

    // 3. Input with spaces
    cin.ignore(); // Clear buffer
    string s4;
    cout << "Enter a line (with spaces): ";
    getline(cin, s4);

    // 4. Print Strings
    cout << "\nYou entered:\n";
    cout << "s1 = " << s1 << "\ns2 = " << s2 << "\ns3 = " << s3 << "\ns4 = " << s4 << endl;

    // 5. String Length
    cout << "\nLength of s4: " << s4.length() << endl;

    // 6. String Concatenation
    string s5 = s1 + " " + s2;
    cout << "Concatenated s1 + s2: " << s5 << endl;

    // 7. Comparison
    if (s1 == "Hello")
        cout << "s1 equals 'Hello'" << endl;

    // 8. Traversal
    cout << "Characters in s2: ";
    for (char ch : s2)
        cout << ch << " ";
    cout << endl;

    // 9. Modification
    s2[0] = 'M';
    cout << "Modified s2: " << s2 << endl;

    // 10. Reversal
    string rev = s3;
    reverse(rev.begin(), rev.end());
    cout << "Reversed s3: " << rev << endl;

    // 11. Substring
    cout << "Substring of s4 from index 2 (length 4): " << s4.substr(2, 4) << endl;

    return 0;
}
