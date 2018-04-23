#include <iostream>
using namespace std;
#define HASHTABLE_SIZE 100

class HashMap
{
  private:
    struct Node
    {
        int key;
        int value;
        struct Node *next; // points to the next node in the list.
    } * hashtable[HASHTABLE_SIZE];

    int getHashCode(int key)
    {
        return key % HASHTABLE_SIZE;
    }

  public:
    HashMap()
    {
        for (int i = 0; i < HASHTABLE_SIZE; i++)
        {
            hashtable[i] = nullptr;
        }
    }
    void put(int, int);
    int get(int);
    void remove(int);
};

/*Store the key/value pair to the HashMap. displays error msg if some value already exist with 
* the given key.
*/
void HashMap::put(int key, int value)
{
    /*Generate hashcode */
    int hash_code = getHashCode(key);

    if (hashtable[hash_code] == nullptr)
    {
        struct Node *node  = new struct Node;
        node->key = key;
        node->value = value;
        node->next = nullptr;
        hashtable[hash_code] = node;
    }

    else
    {
        struct Node *temp = hashtable[hash_code];
        while (1)
        {
            if (temp->next != nullptr)
            {
                if (temp->key == key)
                {
                    cout<<"Key "<<key<<" Already Exist.\n"; // if given key already there.
                    return;
                }
                else
                {
                    temp = temp->next;
                }
            }
            else
            {
                if (temp->key == key)
                {
                    cout<<"Key "<<key<<" Already Exist.\n";
                    return;
                }
                else
                {
                    break;
                }
            }
        }
        struct Node *node  = new struct Node;
        node->key = key;
        node->value = value;
        node->next = nullptr;
        temp->next = node;
    }
}
/* Retrieves the value associated with given key , if exits otherwise error msg will be displayed value
* -1 returned.
*/
int HashMap::get(int key)
{
    int hash_code = getHashCode(key);
    if (hashtable[hash_code] == nullptr)
    {
        cout<<"No associated value found with Key "<<key<<".\n";
        return -1;
    }
    else
    {
        struct Node *temp = hashtable[hash_code];
        while (1)
        {
            if (temp->next != nullptr)
            {
                if (temp->key == key)
                    return temp->value;
                else
                    temp = temp->next;
            }
            else
            {
                if (temp->key == key)
                    return temp->value;
                else
                {
                    cout<<"No associated value found with Key "<<key<<".\n";
                    return -1;
                }
            }
        }
    }
}

/* Remove a item associated with the given key if that item exist in the HashMap*/
void HashMap::remove(int key)
{
    int hash_code = getHashCode(key);
    if (hashtable[hash_code] == nullptr)
    {
        cout<<"Can't Remove.\nNo associated value found with Key "<<key<<".\n";
    }
    else if (hashtable[hash_code]->key == key)
    {
        struct Node *temp = hashtable[hash_code];
        hashtable[hash_code] = temp->next;
        delete temp; // release memory
    }
    else if (hashtable[hash_code]->next == nullptr)
    {
        cout<<"Can't Remove.\nNo associated value found with Key "<<key<<".\n";
        return;
    }

    else
    {
        struct Node *temp = hashtable[hash_code];
        while (1)
        {
            if (temp->next->next != nullptr)
            {
                if (temp->next->key == key)
                {
                    struct Node *f = temp->next;
                    temp->next = temp->next->next;
                    delete f;
                    break;
                }
                else
                {
                    temp = temp->next;
                }
            }
            else
            {
                if (temp->next->key == key)
                {
                    struct Node *f = temp->next;
                    temp->next = nullptr;
                    delete f;
                    break;
                }
                else
                {
                    cout<<"Can't Remove.\nNo associated value found with Key "<<key<<".\n";
                    break;
                }
            }
        }
    }
}

int main()
{
    HashMap hm;
    hm.put(10, 500);
    hm.put(110, 503);
    hm.put(210, 3);
    cout << "Data  : " << hm.get(10) << ", Key : " << 10 << endl;
    cout << "Data  : " << hm.get(110) << ", Key : " << 110 << endl;
    cout << "Data  : " << hm.get(210) << ", Key : " << 210 << endl;
    hm.remove(110);
    hm.remove(10);
    hm.remove(210);
    cout << "Data  : " << hm.get(10) << ", Key : " << 10 << endl;
    cout << "Data  : " << hm.get(110) << ", Key : " << 110 << endl;
    cout << "Data  : " << hm.get(210) << ", Key : " << 210 << endl;
    return 0;
}