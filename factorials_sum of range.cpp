/* By: Paul Patryas
Old c++ program - factorials and summations */

#include <iostream>

int main()
{
    // declare variables
    int sum = 0, val = 50;
    int factorial = 1, val2 = 1;
    int val3 = 10;

    // keep executing while loop as long as val is less than or equal to 100 until condition is false
    while (val <= 100){
        sum += val;     // assigns sum + val to sum
        ++val;          // add 1 to val before
    }
    std::cout << "Sum of 50 to 100 inclusive is: " << sum << std::endl;

    // keep executing while loop as long as val2 is less than or equal to 10 until condition is false
    while (val2 <= 10){
        factorial *= val2;  // assigns factorial * val2 to factorial
        ++val2;             // add 1 to val2
    }
    std::cout << "10! or 10 factorial is: " << factorial << std::endl;

    // keep executing while loop as long as 0 is less than or equal to val3 until condition is false
    while(0 <= val3) {
        std::cout << val3 << std::endl; // print current val3
        --val3; // decrement val3 by 1
    }

    return 0;
}
