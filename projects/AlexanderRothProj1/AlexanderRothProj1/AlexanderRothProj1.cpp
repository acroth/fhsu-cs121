#include <iostream>
//#define _WIN32 - I used this to test the condition

// Author: Alexander Roth
// Date: 08-17-2026
/* This is my first C++ program.
   CSCI 121 Computer Science I
*/

using namespace std;

int main(){
    cout << "Hello World!" << endl;
    cout << "This is my very first C++ program." << endl;
    /**
       The directions said to use system but I am on a macbook and there is no "pause" cmd. So I was recieving a line in the console: "sh: pause: command not found".  The program would then auto exit with code 0. Opted to add a compile time conditional to check if the OS is Windows to run "pause" and a fall back for anything not Windows.
     */
    #if defined(_WIN32)
        system("pause");
    #else
        cout << "Press [Enter/Return] to continue..." <<endl;
        cin.get();
    #endif
}
/** Step 5 Test case answer:
    Recieved a build error for use of an undeclared indentifier 'Cout';
 */
