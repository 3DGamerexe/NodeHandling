
/* Homework #2 Aaliyah Madison */

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = NULL;
    }
};


class SinglyLinkedList {
    Node* head;

public:

    void IH(string v) {
        
    }
};



void Menu() {
    std::cout << "\n";
    std::cout << "\t\tM E N U\n";
    std::cout << "SLL: IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)\n";
    std::cout << "DLL: IH(6), IT(7), DH(8), DT(9), SD(10), PD(11)\n\n";
    std::cout << "Exit Program(12)\n";
}

int main()
{
    Menu();

    int menuValue;
    std::string value;
    std::cin >> menuValue;
    std::cin >> value;



    while (menuValue != 12) {
        if (menuValue < 0 || menuValue > 12 || cin.fail()) {
            cout << "Invalid. Enter a valid number provided in the Menu.";
        }
        else {
            cout << "Valid. Thank you.";

            if (menuValue <= 5) {
                SinglyLinkedList single;

                switch (menuValue) {
                case 0:
                    single.IH(value);
                }
                    
            }
            /*else {
                DoublyLinkedList doubly(menuValue);
            }*/
            
        }
        Menu();
        std::cin >> menuValue;
    }
    if (menuValue == 12) {
        cout << "Thank you! Have a nice day!";
    }
    
}
