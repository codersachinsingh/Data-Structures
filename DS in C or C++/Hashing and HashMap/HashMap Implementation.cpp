/**
 * Data Structures : HashTable or HashMap
 * Author : Sachin Singh
 * Hash Table Implementation with
 * Remainder hashing technique and linear probing collision resolution technique
 * 
*/

 
#include <iostream>
using namespace std;

#define HT_SIZE 100  /* HashTabel Size */


/**
 * Node represents a key/value pair,
 * 
*/
struct Node
{
    int key;
    int value;
};

/**
 * 
 * 
*/
class HashMap
{
  private:
    Node hashtable[HT_SIZE];
    int total_items;
    int hashcode(int key)
    {
        return key % HT_SIZE;
    }

  public:
    HashMap()
    {
        total_items = 0;
        for (int i = 0; i < HT_SIZE; i++)
        {
            hashtable[i].key = -1; // set all keys to -1 initially.
        }
    }

    void put(int, int);
    int get(int);
};


void HashMap::put(int key, int value)
{
    int hc = hashcode(key);
    if (hashtable[hc].key == -1)
    {
        hashtable[hc].value = value;
        hashtable[hc].key = key;
    }
    else
    {
        while (hashtable[hc].key != -1)
        {
            if (hashtable[hc].key == key) {
                cout<<"Duplicate Key"<<endl;
            }
            if (hc == (HT_SIZE - 1))
            {
                cout << "Map Overflow." << endl;
                return;
            }
            else
                hc++;
        }
        hashtable[hc].value = value;
        hashtable[hc].key = key;
    }
}

int HashMap::get(int key)
{
    int hc = hashcode(key);
    if (hashtable[hc].key == key)
        return hashtable[hc].value;
    else
    {
        while (hashtable[hc].key != key)
        {
            if (hc == (HT_SIZE - 1) || hashtable[hc].key == -1)
            {
                cout << "Key Not Found." << endl;
                return -1;
            }
            else 
            {
                hc++;
            }
        }      
        return hashtable[hc].value;
    }
}


// Runner function 
int main()
{
    HashMap map;
    map.put(10, 100);
    map.put(20, 200);
    map.put(40, 300);
    map.put(50, 600);
    map.put(70, 800);
    map.put(170, 432);
    map.put(71,2003);
    map.put(71,545);
    cout << "Returned value by Key : " << map.get(71) << endl;
    return 0;
}