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

    void debugPrint() const {
        Node* current = head;
        int index = 0;
    
        std::cout << "--- DEBUG PRINT ---" << std::endl;
    
        while (current != nullptr) {
            std::cout << "Node: " << index << "\n";
            std::cout << "Address : " << current << "\n";
            std::cout << "Data    : " << current->data << "\n";
            std::cout << "Prev    : " << current->prev << "\n";
            std::cout << "Next    : " << current->next << "\n";
            current = current->next;
            index++;
        }
    
        std::cout <<"end"<< std::endl;
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

    bool isEmpty() const{

        if (head == nullptr && tail ==nullptr){
        return true;
        }

        else{
        return false;
        }
    }
    //use lambda cause it will be so reused. "for every object here, do somethign" lambda can be print, delete, count whatever
    void iterate(const function<void(Node*)> & operation){ //I take an unchanging function. reutnr nothing. and func will operatre on nodes, basically i just go the address and use
        if (tail == nullptr){ //anonymous lambda function that will be used as a skeleton for lots of other junk HEAD IS A MEMBER VARIABLE ITS OK AND TAIL
            return;
        } //so const idk? it treats our tool, this lambda as immutable so future functions know this is whats gonna happen to them, compiler says this tool must not change

        Node* this_node = tail; //we dont want to referencce head eveyr tiem we travceese super inefficient
        while (this_node != nullptr){ //
            Node* prev = this_node -> prev;
            operation(this_node);
            this_node = this_node->prev;
        }  

        

    }

    void print(){
        iterate([](Node* current_item){ //we needed the cosnt to say it wont change later
            cout << current_item-> data << endl; //same as (*node).data but diff syntax so kinda like object
        });

        
    }
    
    void clear(){
        iterate([](Node* current_item){
            delete(current_item);

            
        });

        head = nullptr;
        tail = nullptr;


    }

    void length(){
        int len = 0; //err this is not working exactly but we shall check it later.
        iterate([](Node* current_item){
        });
        


    }

    void step(){

    }






};

int main(void){


    doubly mylist("test"); //need to declare something here
    bool truth;
    truth = mylist.isEmpty();
    cout << truth << endl;

    mylist.append("camera");
    mylist.append("muffintop");

    mylist.print();
    mylist.clear();
    

    truth = mylist.isEmpty();
    cout << truth << endl;

    mylist.print();

    mylist.debugPrint();


    return 0;

}