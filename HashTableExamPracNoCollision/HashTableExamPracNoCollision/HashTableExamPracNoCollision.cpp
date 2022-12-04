#include "People.h"
#include "Person.h"


int main(int argc, char* argv[])
{
    //person IntHashTable = new person<T>(TABLE_SIZE);
    
    //Hash_Table<int>* Table = new Hash_Table<int>; //<-- This for int
    Hash_Table<int,string>* Table = new Hash_Table<int,string>; // this for String

    Table->init_hash_table();
    Table->print_table();

    
    Person<int,string> Jacob = {1,"Worker"};
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
    Table->hash_table_insert(905,"Jacob");
    // Table->hash_table_insert(Kate);
    // Table->hash_table_insert(Mpho);
    // Table->hash_table_insert(Sarah);
    // Table->hash_table_insert(Edna);
    // Table->hash_table_insert(Maren);
    // Table->hash_table_insert(Eliza);
    // Table->hash_table_insert(Robert);
    // Table->hash_table_insert(Jane);


    Table->print_table();
    Person<int> tmp = Table->hash_table_lookup("Jacob");
    if (tmp.Name == N_A_PERSON)
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Found: " << tmp.Name << endl;
    }
    tmp = Table->hash_table_lookup("Jane");
    if (tmp.Name == ("00ffffffffffff"))
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Found: " << tmp.Name << endl;
    }

    cout << tmp.Data << " reeeeeeeeeeeee" << endl;
    Table->hash_table_delete("Jacob");
    Table->print_table();
    Table->hash_table_delete("Jane");
    Table->print_table();
   

    return 0;
}
