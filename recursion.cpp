#include <iostream>
using namespace std;
// takes user input for num, and rercursively adds every preceding number until zero
//ex: input of 3 will output (3 + 2 + 1) = 6
// input of 4 will output (4 + 3 + 2 + 1) = 10 

    //recursive function
    int sum(int num) {
        //repeat until num reaches zero 
        if (num != 0) {
            return (num + sum(num - 1));
        }
        //upon returning zero, output total sum
        else {
            return num;
        }
    }
int main() {
    int n;
    cout << "Enter the amount of numbers to add recursively" << endl;
    cin >> n;
    int total = sum(n);
    cout << "The total is equal to: " << total << endl;
    return 0;
}
