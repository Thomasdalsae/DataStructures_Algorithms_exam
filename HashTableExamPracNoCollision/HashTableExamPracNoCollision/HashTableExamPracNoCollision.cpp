#include "Node.h"
#include "HashTable.h"
#include "Person.h"


int main() {
    Hash_Table<int, Person> personTable{};
    Person person1 = Person(42, "Seksi", 'A');
    Person person2 = Person(26, "Haldor", 'H');
    Person person3 = Person(24, "Thomas", 'T');
    Person person4 = Person(22, "Ni", 'S');
    
    Person person5 = person1 + person4;
    
    
    personTable.Insert(101, person1);
    personTable.Insert(1250, person2);
    
    personTable.Print();
    
    return 0;
    Hash_Table<int, int> hashTable = Hash_Table<int,int>();

    cout << (hashTable.IsEmpty() ? "HASH TABLE IS EMPTY" : "HASH TABLE IS NOT EMPTY") << endl;
    
    hashTable.Insert(201, 420);
    cout << (hashTable.IsEmpty() ? "HASH TABLE IS EMPTY" : "HASH TABLE IS NOT EMPTY") << endl;
    hashTable.Insert(101, 69);
    hashTable.Insert(201, 314);
    hashTable.Insert(205, 314);
    hashTable.Print();
    cout << hashTable.Lookup(101) << endl;
    cout << hashTable.Lookup(201) << endl;

    // testing delete
    // hashTable.Delete(010);
    hashTable.Delete(201);
    
    hashTable.Print();

    /*
    //person IntHashTable = new person<T>(TABLE_SIZE);
    //Hash_Table<int>* Table = new Hash_Table<int>; //<-- This for int
    auto Table = new Hash_Table<int, string>; // this for String

    Table->print_table();
    Node<int, string> Jacob = {1, "Worker"};
    // Person<int> Kate = {2,"Kate", 36};
    // Person<int> Mpho = {3,"Mpho", 14};
    //  Person<int> Sarah = {4,"Sarah", 34};
    // Person<int> Edna = {5,"Edna", 54};
    //  Person<int> Maren = {6,"Maren", 44};
    // Person<int>  Eliza = {7,"Eliza", 23};
    // Person<int> Robert = {8,"Robert", 74};
    // Person<int> Jane = {9,"Jane", 64};

    //Person<string> Jacob = {"Person1", "Jacob", 56,734.23123f};
    // Person<string> Kate = {"Person2", "Kate", 36};
    // Person<string> Mpho = {"Person3", "Mpho", 14};
    // Person<string> Sarah = {"Person4", "Sarah", 34};
    // Person<string> Edna = {"Person5", "Edna", 54};
    // Person<string> Maren = {"Person6", "Maren", 44};
    // Person<string> Eliza = {"Person7", "Eliza", 23};
    // Person<string> Robert = {"Person8", "Robert", 74};
    // Person<string> Jane = {"Person9", "Jane", 64};

    //inserting with the name,
    Table->hash_table_insert(905, "Jacob");
    // Table->hash_table_insert(Kate);
    // Table->hash_table_insert(Mpho);
    // Table->hash_table_insert(Sarah);
    // Table->hash_table_insert(Edna);
    // Table->hash_table_insert(Maren);
    // Table->hash_table_insert(Eliza);
    // Table->hash_table_insert(Robert);
    // Table->hash_table_insert(Jane);


    Table->print_table();
    Node<int> tmp = Table->hash_table_lookup("Jacob");
    if (tmp.Name == N_A_PERSON) {
        cout << "Not found" << endl;
    }
    else {
        cout << "Found: " << tmp.Name << endl;
    }
    tmp = Table->hash_table_lookup("Jane");
    if (tmp.Name == ("00ffffffffffff")) {
        cout << "Not found" << endl;
    }
    else {
        cout << "Found: " << tmp.Name << endl;
    }

    cout << tmp.Data << " reeeeeeeeeeeee" << endl;
    Table->hash_table_delete("Jacob");
    Table->print_table();
    Table->hash_table_delete("Jane");
    Table->print_table();


    return 0;*/
}
