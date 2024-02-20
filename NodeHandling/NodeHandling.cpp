
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
        else {
            head = new IntSLLNode(el, head);
            if (tail == 0) {
                tail = head;
            }
        }      
    }

    void IT(string el) {

        if (tail != nullptr) {
            tail->next = new IntSLLNode(el);
            tail = tail->next;
        }
        else 
            head = tail = new IntSLLNode(el);
    }

    void DH() {
        if (head != nullptr) {
            IntSLLNode* tmp = head;
            head = head->next;              
            delete tmp;
            if (head == nullptr) {
                tail = nullptr;
            }
        }
        else {
            cout << "Empty: No value to delete." << endl;
        }
    }

    void DT() {
        if (tail == nullptr) {  //if there are no elements
            cout << "Empty: No value to delete." << endl; 
        }
        else if (tail == head) { //if there is only 1 element
            delete head;
            tail = head = nullptr;
        }
        else {
            IntSLLNode* tmp = head;
            while (tmp->next != tail) {
                tmp = tmp->next;
            }
            delete tail;
            tail = tmp;
            tail->next = nullptr;
        }
    }

    void SD(string el) {

        if (head != 0) {
            //only one node in the list
            if (head == tail && head->info == el) {
                delete head;
                head = tail = nullptr;
            }

            //if more than 1 node in the list and the element is the head
            else if (el == head->info) {
                IntSLLNode* tmp = head;
                head = head->next;
                delete tmp;
            }
            //multiple nodes with any value that isn't the head
            else {
                IntSLLNode* pred, * tmp;
                for (pred = head, tmp = head->next; tmp != nullptr; pred = pred->next, tmp = tmp->next) {
                    if (tmp->info == el) {
                        pred->next = tmp->next;
                        if (tmp == tail)
                            tail = pred;
                        delete tmp;
                        return;
                    }
                    else {
                        cout << "Value is not in LinkedList. Sorry." << endl;
                        return;
                    }
                }

            }
        }
        

    }

    void PS() {
        IntSLLNode* current = head; 

        while (current != nullptr) {
            cout << current->info << " ";
            current = current->next;
        }
        cout << endl;

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
        std::cout << "Choose: ";
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
                case 1:
                    std::cin >> value;
                    single.IT(value);
                    break;
                case 2:
                    single.DH();
                    break;
                case 3:
                    single.DT();
                    break;
                case 4:
                    std::cin >> value;
                    single.SD(value);
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
