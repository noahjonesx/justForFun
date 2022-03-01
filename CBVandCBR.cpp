#include <iostream>
using namespace std;
//swap function
void callByValue(int x, int y) {
    //set value of x equal to palceholder
    int i=x;
    //set value of y to x, half of swap is complete
    x = y;
    //set value from placeholder (o.g. value of x) to y
    //swap complete
    y = i;
}
    void callByReference(int &x, int &y) {
        int i = x;
        x=y;
        y=i;
    }
int main () {
    int a = 5; 
    int b = 6;
    cout << "Before swap: " << endl;
    cout << "a: "<<a<<endl<<"b: "<<b<<endl<<endl;

    //callByValue(a,b);
    callByReference(a,b);

    cout << "After swap: " << endl;
    cout << "a: "<<a<<endl<<"b: "<<b<<endl<<endl;
    return 0;
}