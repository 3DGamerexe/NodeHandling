
/* Homework #2 Aaliyah Madison */

#include <iostream>
#include <string>
using namespace std;

class IntSLLNode {

public:
    class SinglyLinkedList;  

    IntSLLNode() {
        next = 0;
    }
    IntSLLNode(string i, IntSLLNode* in = nullptr) {
        info = i; 
        next = in;
    }
    string info;
    IntSLLNode* next;  
    
};


class IntSLLNode::SinglyLinkedList {
public: 
    IntSLLNode* head;
    IntSLLNode* tail;

    SinglyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    void IH(string el) {

        if (el.length() > 1) {
            cout << "The value you entered should be a single character or digit." << endl;
        }
        else if (el.length() == 1) {
            head = new IntSLLNode(el, head);
            if (tail == 0) {
                tail = head;
            }
        }

        /*head = new IntSLLNode(el, head);
        if (tail == 0) {
            tail = head;
        }*/

        //if (el.length() > 1) {
        //    cout << "The value you enter in the LinkedList should be a single character or digit." << endl;
        //}

        //else if (el.length() == 1) {
        //    //head = new IntSLLNode(el, head);
        //    IntSLLNode* newNode = new IntSLLNode(el, head);
        //    head = newNode; 

        //    if (tail == nullptr) {
        //        tail = head;
        //    }
        //    PS(head);
        //}       
    }

    void PS() {
        IntSLLNode* current = head; 

        while (current != 0) {
            cout << current->info << " ";
            current = current->next;
        }
        cout << endl;

        /*if (head != NULL) {
            cout << head -> info << endl;
        }*/
    }
};



void Menu() {
    std::cout << "\n";
    std::cout << "\t\tM E N U" << endl;
    std::cout << "SLL: IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)" << endl;
    std::cout << "DLL: IH(6), IT(7), DH(8), DT(9), SD(10), PD(11)" << endl << endl;
    std::cout << "Exit Program(12)" << endl;
}

int main()
{    
    int menuValue;
    std::string value;  
    IntSLLNode::SinglyLinkedList single;

     do {
        Menu();
        std::cin >> menuValue;

        if (menuValue < 0 || menuValue > 12 || cin.fail()) {
            cout << "Invalid. Enter a valid number provided in the Menu.";
        }

        else {

            if (menuValue <= 5) {
                          
                switch (menuValue) {
                case 0:
                    std::cin >> value;
                    single.IH(value);
                    break;
                case 5:
                    single.PS();
                }
            }    
        }
        
        if (menuValue == 12) {
            cout << "Thank you! Have a nice day!";
        }

     } while (menuValue != 12);
    
}
