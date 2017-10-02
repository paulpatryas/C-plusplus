/* By: Paul Patryas
    first foray into polymorphism
    Date: Dec 2016 */
 


#include <iostream>
#include <stdlib.h>

class Dog {
    protected:
        int age, height;
    public:
        Dog (int a = 0, int h = 0) {
            age = a;
            height = h;
        }
        virtual int getAge_Height () {
            return 0;
        }
        virtual void Speak() = 0;      // a virtual "Speak" function
        virtual void Color() = 0;     // a virtual "Color" function
};

class Poodle : public Dog { // A poodle "is a" Dog;
    public:
        Poodle (int a = 0, int h = 0) : Dog (a, h) {}
        int getAge_Height () {
            std::cout << "Poodle's age is: " << age << std::endl;
            std::cout << "Poodle's height is: " << height << std::endl;
        }
        void Speak() { std::cout << "yip yip!" << std::endl; }     // poodles are yappy dogs, so have it yip
        void Color() { std::cout << "I'm a small dog." << std::endl; }
};

class GoldenLab : public Dog {// A lab "is a" Dog
    public:
        GoldenLab (int a = 0, int h = 0) : Dog (a, h) {}
        int getAge_Height () {
            std::cout << "Lab's age is: " << age << std::endl;
            std::cout << "Lab's height is: " << height << std::endl;
        }
        void Speak() { std::cout << "woof woof!" << std::endl; }      // bigger dogs have bigger barks
        void Color() { std::cout << "I'm a medium-size dog." << std::endl; }
};

class PitBull : public Dog {// A pit-bull "is a" Dog
    public:
        PitBull (int a = 0, int h = 0) : Dog (a, h) {}
        int getAge_Height () {
            std::cout << "Pitbull's age is: " << age << std::endl;
            std::cout << "Pitbull's height is: " << height << std::endl;
        }
        void Speak() { std::cout << "growl growl!" << std::endl; }
        void Color() { std::cout << "I'm a mean dog." << std::endl; }
};

//  ** THIS IS THE REAL MAGIC **
//  dog is just a pointer to a Dog, not a Poodle, GoldenLab, or PitBull
void DoSomethingWithADog(Dog *dog) {
/*
   magically call the Speak() & Color() of whatever derived class
   the dog "actually" is. So if "dog" points to a Poodle, this will yip,
   or if it points to a lab, this will woof and so forth.
 */
        dog->Speak();
        dog->Color();
        dog->getAge_Height();
}

void getDog();
void getPoodle(int &pAge, int &pHeight);
void getLab(int &lAge, int &lHeight);
void getPitBull(int &pitAge, int &pitHeight);

int main() {
    char do_over;
        do{
            system("CLS"); // clear the screen if user chooses yes
            getDog();
            std::cout << "\n";
            std::cout << "Do you want to repeat the program?(Y/N)";
            std::cin >> do_over;
            std::cout << "\n";
        }while (do_over == 'Y' || do_over == 'y');
        return 0;
}

void getDog() {
    int poodleAge, poodleHeight, labAge, labHeight, pitbullAge, pitbullHeight;

    getPoodle(poodleAge, poodleHeight);
    getLab(labAge, labHeight);
    getPitBull(pitbullAge, pitbullHeight);

    Poodle myPoodle(poodleAge, poodleHeight);
    GoldenLab myLab(labAge, labHeight);
    PitBull myPitbull(pitbullAge, pitbullHeight);

    DoSomethingWithADog(&myPoodle);
    DoSomethingWithADog(&myLab);
    DoSomethingWithADog(&myPitbull);
}

void getPoodle(int &pAge, int &pHeight) {
    std::cout << "Please enter age of poodle: ";
    std::cin >> pAge;
    std::cout << "Please enter height of poodle: ";
    std::cin >> pHeight;
}

void getLab(int &lAge, int &lHeight) {
    std::cout << "Please enter age of lab: ";
    std::cin >> lAge;
    std::cout << "Please enter height of lab: ";
    std::cin >> lHeight;
}

void getPitBull(int &pitAge, int &pitHeight) {
    std::cout << "Please enter age of poodle: ";
    std::cin >> pitAge;
    std::cout << "Please enter height of poodle: ";
    std::cin >> pitHeight;
}
