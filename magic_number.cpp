/* By: Paul Patryas
    Old c++ project - Magic number
    Date: Aug 2016 */

#include <iostream>
#include <stdlib.h>

// declare functions
int get_product_sum();
void clean_input(void);


int main(){

    // call functions
    get_product_sum();
    getchar();

}

int get_product_sum(){

    // declare variables
    long double even_product = 1, odd_product = 1, sum_odd = 0, sum_even = 0, factorial = 1, total_sum = 0;
    long double user_input, odd_numbers = 0, even_numbers = 0;
    char do_over;


    do {

        // do...while loop that continues until user inputs other than 'y' or 'Y'
        std::cout << "Enter a number to find magic: ";
        std::cin >> user_input;
        clean_input();

        // run for loop against user input
        for(int i=1; i <= user_input; i++){
            // find odd numbers in range: get product, sum, and # of all odd numbers in range
            if(i&1 != 0){
                odd_product *= i;
                sum_odd += i;
                odd_numbers++;
            }
            // find even numbers in range: get product, sum, and # of all even numbers in range
            else{
                even_product *= i;
                sum_even += i;
                even_numbers++;
            }
            // find factorial of user input & find sum of all numbers in range
            factorial *= i;
            total_sum += i;
        }

        // print out # of odd numbers in range
        std::cout << "\n";
        std::cout << "Number of odd numbers between " << user_input << " are: " << odd_numbers << std::endl;
        std::cout << "Odd numbers are: ";

       // for loop to print out all odd numbers in range
        for(int i=1; i <= user_input; i++){
            if(i&1 != 0){
                std::cout << i << " ";
            }
        }
        // print out product & sum of all odd numbers in range
        std::cout << std::endl;
        std::cout << "Product of odd numbers is: " <<  odd_product << std::endl;
        std::cout << "Sum of odd numbers is: " << sum_odd << std::endl;


        std::cout << std::endl;

        // print out # of even numbers in range
        std::cout << "Number of even numbers between " << user_input << " are: " << even_numbers << std::endl;
        std::cout << "Even numbers are: ";

        // for loop to print out all even numbers in range
        for(int i=1; i <= user_input; i++){
            if(i%2 == 0){
                std::cout << i << " ";
            }
        }
        // print out product & sum of all even numbers in range
        std::cout << std::endl;
        std::cout << "Product of even numbers is: " << even_product << std::endl;;
        std::cout << "Sum of even numbers is: " << sum_even << "\n " << std::endl;

        // print out factorial of user input & total sum in range
        std::cout << "Factorial of " << user_input << " is: " << factorial << std::endl;
        std::cout << "Sum of all numbers between " << user_input << " is: " << total_sum << "\n " << std::endl;

        std::cout << "Do you want to repeat the program?(Y/N)";
        std::cin >> do_over;
        std::cout << "\n";
    return 0;
    }while(do_over == 'Y' or do_over == 'y');
}
void clean_input(void){
    while (getchar()!='\n');
    return;
}
