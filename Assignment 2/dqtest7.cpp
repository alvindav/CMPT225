/* Deque Test Program 4 */
#include <cstring>
#include <iostream>
#include "Deque.h"

using namespace std ;

int main (int argc, char * const argv[]) {
    cout << "\n\nDeque Class Test Program 4 - START\n\n";

    // Make a Deque
    Deque dq1;

    // Insert some elements 
    dq1.push_left(1);
    dq1.push_left(2);
    dq1.push_left(3);
    dq1.push_left(4);
    dq1.push_left(5);
    dq1.push_left(6);
    dq1.push_left(7);
    dq1.push_left(8);
    dq1.cursor_left();
    dq1.cursor_left();
    dq1.cursor_left();
    cout << "***DISPLAYING DQ1***" << endl;
    dq1.verbose_display();

    // Make a copy
    Deque dq2(dq1);
    cout << "***DISPLAYING DQ2 (DQ1 COPY)***" << endl;
    dq2.verbose_display();

    // Make a Deque
    Deque * dq3 = new Deque();

    // Insert some elements 
    dq3->push_left(1);
    dq3->push_left(2);
    dq3->push_left(3);
    dq3->push_left(4);
    dq3->push_left(5);
    dq3->cursor_left();
    dq3->cursor_left();
    cout << "***DISPLAYING DQ3***" << endl;
    dq3->verbose_display();
 
    // Make a copy
    cout << "***DISPLAYING DQ4 (DQ3 COPY)***" << endl;
    Deque * dq4 = new Deque(*dq3);
    dq4->verbose_display();


    return 0;
}
