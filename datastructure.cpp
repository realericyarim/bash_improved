#include <iostream>
#include <cstring>
#include <functional>

using namespace std;

class doubly{ //local is just a function variable, inside a struct/class outside method is member variable, global isglobal
    private:
    struct Node {
        string data; //these member variables "stick with" the node no matter what, they are BUNDLED
        Node* next; //so within a struct, we can define pointers to the type of struct huh but only pointersehhh
        Node* prev; //you cant put a donut box inside itself, but you can have a sticky saying there's another on the counter

        void print_info(){ //generally we dont need to pass in stuff that we already own ig!
            cout << "Data = " << data << "Prev = " << prev << "Next = " << next << endl;
        }


    };

    Node* head;
    Node* tail;

public:    //this is so confusing but stack is function scope (constructor is function) heap is program scope until deletedhmm 
    doubly(string value){ //local variables within functions live on the stack so we need to keep our object alive somehow
        // node origin; origin.data = value; these are local variable that are unallocated irl CONSTRUCTORS ARE FUNCTIONS
        head = new Node{value, nullptr, nullptr}; //basically new house at address of head is this new node  (NEW IS FOR POINTERS BABE!)
        tail = head;
    }

    ~doubly(){

    }

    void append(string value){

        if (head==nullptr){ //again has to be nullpointer, cause we are dealing with references here. basically if no one is home
            head = new Node{value, nullptr, nullptr};
            tail = head;
        }

        else{
            Node* newNode = new Node{value, nullptr, nullptr};
            newNode->prev = tail; //so a struct doesnt ahve an address ig? but it is just kind of a way of saying hey these 3 addresses are related?
            tail->next = newNode;
            tail = newNode;
        }

    }

    bool isEmpty(){

        if (head == nullptr){
        return true;
        }
    }
    //use lambda cause it will be so reused. "for every object here, do somethign" lambda can be print, delete, count whatever
    void iterate(const function<void(Node*)> & operation){ //when you call iterate you give it new function as  input, must take a node poointer, and does something to thing at address
        if (head == nullptr){ //anonymous lambda function that will be used as a skeleton for lots of other junk
            return;
        }

        Node* this_node = head; //we dont want to referencce head eveyr tiem we travceese super inefficient
        while (this_node != nullptr){ //
            operation(this_node);
            this_node = this_node->next;
        }


    }




};

int main(void){

    return 0;

}