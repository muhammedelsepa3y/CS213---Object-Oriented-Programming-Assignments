/*
                     Solution of Assignment 2
                            Group A
  Made by
        Name                              ID            Section
        Mohamed Samy Abdelsalam Elsebaey  20200445      12
        Fouad Sayed Fouad Sayed           20200384      12

*/
#include <iostream>
#include <string>
using namespace std;
class Item{
private:
    int ID,quantity;
    string name;
    double price;
    static int static_ID;

public:
    Item(){
        quantity=0;
        price=0;
        name="";
        ID=static_ID++;}
    Item(string name,int quantity,double price){
        this->name=name;
        this->quantity=quantity;
        this->price=price;
        ID=static_ID++;}
    Item(Item &obj){
        this->name=obj.name;
        this->quantity=obj.quantity;
        this->price=obj.price;
        ID=obj.ID;}
    void set_Name(string name){
        this->name=name;}
    void set_Price(double price){
        this->price=price;}
    void set_Quantity(int quantity){
        this->quantity=quantity;}
    string get_Name(){
        return name;}
    double get_Price(){
        return price;}
    int get_ID(){
        return ID;}
    int get_Quantity(){
        return quantity;}
    bool operator ==(Item obj) const{
        return this->name == obj.name;}
    void operator +=(int Quantity){
        this->quantity += Quantity;}
    void operator -=(int Quantity){
        this->quantity -= Quantity;}
    friend ostream &operator<<(ostream &output, Item &obj){
        output << "ID:"<<obj.get_ID() << ", "<< "Name:"<<obj.get_Name() << ", "<< "Price:"<<obj.get_Price() << ", "<< "Quantity:"<<obj.get_Quantity() <<"\n";return output;}
    friend istream &operator>>(istream &input, Item &obj){
        input >> obj.name >> obj.quantity >> obj.price;return input;}};
int Item::static_ID = 1;
class Seller{
private:
    string name,email;
    Item *items;
    int maxItems,items_Counter;

public:
    Seller(){items_Counter=0;}
    Seller(string name, string email, int maxItems){
        this->name = name;
        this->email = email;
        this->maxItems = maxItems;
        items = new Item[maxItems];
        items_Counter=0;}
    friend istream &operator>>(istream &input, Seller &object){
        input >> object.name >> object.email;return input;};
    friend ostream &operator<<(ostream &output, Seller &object){
        output << "Seller Name: "<<object.name << " , " << "Seller Email: "<<object.email << "\n";return output;};
    bool add_Item(Item obj){
        bool x=0;
        if (items_Counter == maxItems){return false;
        }else{
            for (int z = 0; z < items_Counter; z++){
                if (items[z] == obj){
                        items[z] += obj.get_Quantity();
                        x=1;
                        break;}}
            if(!x){
                    items[items_Counter++] = obj;}
            return true;}}
    bool sell_Item(string nname,int qquantity){
        for (int p = 0; p < items_Counter; p++){
            if (items[p].get_Name() == nname){
                if (items[p].get_Quantity() >= qquantity){items[p] -= qquantity;
                }else{cout << "There is only " << items[p].get_Quantity() << " quantity left for this item\n";}
                return true;}
        }return false;}
    void print_Items(){for (int q = 0; q < items_Counter; q++){
        cout << items[q];}}
    Item *find_An_Item_By_Id(int Id){
        for (int a = 0; a < items_Counter; a++){
            if (items[a].get_ID() == Id){
                    return &(items[a]);}
            }return nullptr;}
    ~Seller(){
        delete[] items;}
    void set_Max_Items(int maxItems){
        this->maxItems = maxItems;
        items = new Item[maxItems];}
    Item *get_Items(){
        return items;}
    int get_Items_Counter(){
        return items_Counter;}};
int main(){
    cout << "Please Enter seller details \"name, email\": ";
    Seller *seller = new Seller();
    cin >> *seller;
    cout << "Please Enter max number of items: ";
    int maxNumberOfItems;
    cin >> maxNumberOfItems;
    seller->set_Max_Items(maxNumberOfItems);
    int choice=0;
    while(choice!=6){
        cout << "\n1. Print My Info.\n2. Add An Item.\n3. Sell An Item.\n4. Print Items.\n5. Find an Item by ID\n6. Exit\nPlease enter your choice: ";
        cin>>choice;
        string item_name;
        int item_quantity;
        int ID;
        Item *find_Item;
        switch(choice){
            case 1:
                cout << *seller;
                break;
            case 2:
                cout << "Please Enter item details you want to add \"name, quantity, price\":  ";
                cin >> seller->get_Items()[seller->get_Items_Counter()];
                seller->add_Item(seller->get_Items()[seller->get_Items_Counter()]);
                break;
            case 3:
                cout << "Please Enter item you want to sell \"name, quantity\": ";
                cin >> item_name>>item_quantity;
                seller->sell_Item(item_name, item_quantity);
                break;
            case 4:
                seller->print_Items();
                break;
            case 5:
                cout << "Please Enter Item Id you want to search about:  ";
                cin >> ID;
                find_Item= seller->find_An_Item_By_Id(ID);
                if (find_Item != nullptr){cout << *find_Item;
                    }else{
                        cout << "Item with given ID doesn't exist!\n";}
                break;
            default:
                cout << "Invalid Choice!\n";
                continue;}
    }return 0;}
