/* PROCEDURE: */
// STEP (1) - load individual digits of two input numbers in two stack.
// STEP (2a) - carry out integer addition, adding each digit in the same place-number together and storing the resultant place-number in a new stack.
// STEP (2b) - if the resulting number from this mini-addition is greater than 10, the carryover (result / 10) is taken away from the result and is stored for the next mini-addition.
// STEP (3) - if there is one number that hasn't been fully read, the leftover is added to the stack, considering the carryover from (2b).
// STEP (4) - if there is still carryover stored, this is added to the stack.

#include <iostream>
#include <string>
#include <stack>
#include <cstdio>
using namespace std;

stack<int> integer[3]; // represents each of the three big numbers - 0 and 1 are the input numbers, 2 is the resulting number.

void display(); // displays the resultant big number in string form.

int main() {
    int i, j;       // index.
    int strlength;  // length of temp_s string.
    int carryover, temp_i;
    string temp_s, temp_c;
    /* --- STEP (1) --- */
    for (i = 0; i < 2; i++) {
        getline(cin, temp_s);
        strlength = temp_s.length();
        for (j = 0; j < strlength; j++) {
            temp_c = temp_s[j];
            temp_i = stoi(temp_c);
            integer[i].push(temp_i);
        }
    }
    carryover = 0;
    while ((integer[0].empty() == false) && (integer[1].empty() == false)) {
        /* STEP (2a) */
        temp_i = integer[0].top() + integer[1].top();
        if (carryover > 0) {
            temp_i += carryover;
            carryover = 0;
        }
        /* STEP (2b) */
        if (temp_i >= 10) {
            carryover = temp_i / 10;
            temp_i%= 10;
        }
        integer[2].push(temp_i);
        integer[0].pop();
        integer[1].pop();
    }
    /* STEP (3) */
    if ((integer[0].empty() == false) && (integer[1].empty() == true)) {
        while (integer[0].empty() == false) {
            temp_i = integer[0].top();
            if (carryover > 0) {
                temp_i += carryover;
                carryover = 0;
            }
            if (temp_i >= 10) {
                carryover = temp_i / 10;
                temp_i -= 10;
            }
            integer[2].push(temp_i);
            integer[0].pop();
        }
    } else if ((integer[1].empty() == false) && (integer[0].empty() == true)) {
        while (integer[1].empty() == false) {
            temp_i = integer[1].top();
            if (carryover > 0) {
                temp_i += carryover;
                carryover = 0;
            }
            if (temp_i >= 10) {
                carryover = temp_i / 10;
                temp_i -= 10;
            }
            integer[2].push(temp_i);
            integer[1].pop();
        }
    }
    /* STEP (4) */
    if (carryover > 0) {
        integer[2].push(carryover);
    }
    display();
}

void display() {
    string result;
    result = "";
    while (integer[2].empty() == false) {
        result+= (integer[2].top()+48);
        integer[2].pop();
    }
    cout << result << endl;
}