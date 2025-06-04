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
