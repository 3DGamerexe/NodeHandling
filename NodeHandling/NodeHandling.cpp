
/* Homework #2 Aaliyah Madison */

#include <iostream>
#include <string>
#include <iomanip>
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
            std::cout << "The value you entered should be a single character or digit." << endl;
        }
        else {
            head = new IntSLLNode(el, head);
            if (tail == nullptr) {
                tail = head;
            }
        }      
    }

    void IT(string el) {
        if (el.length() == 1) {
            if (tail != nullptr) {
                tail->next = new IntSLLNode(el);
                tail = tail->next;
            }
            else
                head = tail = new IntSLLNode(el);
        }
        else {
            std::cout << "The value you entered should be a single character or digit." << endl;
        }
    }

    void DH() {
        
        if (head != nullptr) {
            IntSLLNode* tmp = head;
            head = head->next;              
            delete tmp;

            if (head == nullptr) {
                tail = nullptr;
                std::cout << "List is now empty." << endl;
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
            std::cout << "Value deleted. Your list is now empty." << endl; 
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

        //continue if there are values in the linkedList
        if (head != nullptr) {
            //only one node in the list
            if (head == tail && head->info == el) {
                delete head;
                head = tail = nullptr;
                std::cout << "Value found and deleted. Your list is now empty." << endl; 
            }

            //if more than 1 node in the list and the element is the head
            else if (el == head->info) {
                IntSLLNode* tmp = head;
                head = head->next;
                delete tmp;
            }

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
                }
                std::cout << "There is no such node in the list!" << endl;
            }
        }
        else {
            std::cout << "Empty: Try filling the list with values first." << endl;
        }

    }

    void PS() {
        IntSLLNode* current = head; 

        while (current != nullptr) {
            cout << current->info << " ";
            current = current->next;
        }

        if (head == tail) {
            std::cout << "Your list is empty." << endl;
        }
        cout << endl;
    }
};

//Doubly Linked List
class DLLNode {
public:

    class DoublyLinkedList;

    DLLNode() {
        prev = nullptr;
        next = nullptr;
    }

    DLLNode(string info,  DLLNode* nxt = nullptr, DLLNode * pred = nullptr) {
        data = info; next = nxt; prev = pred;
    }
    string data;
    DLLNode* prev;
    DLLNode* next;

};

class DLLNode::DoublyLinkedList {
public:
    DLLNode* head;
    DLLNode* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr; 
    }

    void IH(string el) {
        //input should be length 1
        if (el.length() == 1) {
            head = new DLLNode(el, head, 0);

            if (head->next != nullptr) {
                head->next->prev = head;
            }

            if (tail == nullptr) {
                tail = head;
            }
        }
        else {
            std::cout << "The value you entered should be a single character or digit." << endl;
        }
    }

    void IT(string el) {
        //input should be length 1 
        if (el.length() == 1) {
            if (tail != nullptr) {
                tail = new DLLNode(el, 0, tail);
                tail->prev->next = tail;
            }
            else head = tail = new DLLNode(el);
        }
        else {
            std::cout << "The value you entered should be a single character or digit." << endl;
        }
    }

    void DH() {
        //1 value in list
        if (head == tail && head != nullptr) {
            delete head;
            head = tail = nullptr;
            std::cout << "Your list is now empty." << endl; 

        }
        //no values in the list
        else if (head == nullptr) {
            std::cout << "Your list is empty. Try filling the list first." << endl;
        }
        else {
            DLLNode* tmp = new DLLNode();
            tmp = head;
            head = head->next;
            delete tmp;
            tmp = nullptr; 
        }
    } 

    void DT() {
        //1 value in the list
        if (tail == head && tail != nullptr) {
            delete head;
            head = tail = nullptr;
            std::cout << "Your list is now empty." << endl;
        }
        //list is empty
        else if (tail == nullptr) {
            std::cout << "Your list is empty. Try filling the list first." << endl; 
        }
        else {
            tail = tail->prev;
            delete tail->next;
            tail->next = 0;
        }
    }

    void SD(string el) {
        //if there is at least 1 value
        if (head != nullptr) {

            //only one value in the list that matches user input
            if (head == tail && head->data == el) {
                delete head;
                head = tail = nullptr; 
                std::cout << "Value found and deleted. Your list is now empty." << endl;
            }

            // if el is equal to the first value of the list
            else if (el == head->data) {
                head = head->next;
                delete head->prev;
                head->prev = nullptr; 
            }

            else {
                DLLNode* pred, * tmp;
                for (pred = head, tmp = head->next; tmp != nullptr; pred = pred->next, tmp = tmp->next) {
                    if (tmp->data == el) {
                        pred->next = tmp->next;                    
                        if (tmp->next != nullptr) {
                            tmp->next->prev = pred;
                        }
                        else {
                            tail = pred;
                        }
                        delete tmp;
                        return;
                    }
                }
                std::cout << "There is no such node in the list!" << endl;
            }
        }
        else {
            std::cout << "Your list is empty. Add some values first." << endl; 
            return; 
        }
    }
 
    void PD() {
        DLLNode* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        if (head == tail) {
            std::cout << "Your list is empty." << endl;
        }
        cout << endl;
    }
};


void Menu() {
    std::cout << endl;
    std::cout << std::setw(25) << "M E N U" << endl;
    std::cout << "SLL: IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)" << endl;
    std::cout << "DLL: IH(6), IT(7), DH(8), DT(9), SD(10), PD(11)" << endl << endl;
    std::cout << "Exit Program(12)" << endl << endl;
}

int main()
{    
    int menuValue;
    std::string value;  
    IntSLLNode::SinglyLinkedList single;
    DLLNode::DoublyLinkedList doubly;

     do {
        Menu();
        std::cout << std::setw(20) << "Choose? ";
        std::cin >> menuValue;

        if (menuValue < 0 || menuValue > 12 || cin.fail()) {
            std::cout << "Invalid. Enter a valid number provided in the Menu.";
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
            else if (menuValue < 12) {
                switch (menuValue) {
                case 6:
                    std::cin >> value;
                    doubly.IH(value);
                    break;
                case 7:
                    std::cin >> value;
                    doubly.IT(value);
                    break; 
                case 8:
                    doubly.DH();
                    break;
                case 9:
                    doubly.DT();
                    break;
                case 10:
                    std::cin >> value; 
                    doubly.SD(value);
                    break; 
                case 11:
                    doubly.PD();
                    break;
                }
            }
        }
        
        if (menuValue == 12) {
            std::cout << "Thank you! Have a nice day!" << endl;
        }

     } while (menuValue != 12);
    
}
