#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#define MAX 100   /* Size of HashTable*/

/**
 *  Struct Node for key/value pair;
*/
struct Node
{
    int key;
    int value;
    struct Node *next; // points to the next node in the list.
} * hashtable[MAX];  // table of node type pointers . each element is a head of a linked list to
                    // corresponding hash index.

/*function declarations*/
void put(int, int);
int get(int);
void remove(int);

/*Generates the hashcode for a given key*/
int getHashCode(int key)
{
    return key % MAX;
}

/*Store the key/value pair to the HashMap. displays error msg if some value already exist with 
* the given key.
*/
void put(int key, int value)
{
    /*Generate hashcode */
    int hash_code = getHashCode(key);

    if (hashtable[hash_code] == nullptr)
    {
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
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
                    printf("Key %d Already Exist.\n", key);  // if given key already there.
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
                    printf("Key %d Already Exist.\n", key);
                    return;
                }
                else
                {
                    break;
                }
            }
        }
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        node->key = key;
        node->value = value;
        node->next = nullptr;
        temp->next = node;
    }
}
/* Retrieves the value associated with given key , if exits otherwise error msg will be displayed value
* -1 returned.
*/
int get(int key)
{
    int hash_code = getHashCode(key);
    if (hashtable[hash_code] == nullptr)
    {
        printf("No associated value found with Key %d.\n", key);
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
                    printf("No associated value found with Key %d.\n", key);
                    return -1;
                }
            }
        }
    }
}

/* Remove a item associated with the given key if that item exist in the HashMap*/
void remove(int key)
{
    int hash_code = getHashCode(key);
    if (hashtable[hash_code] == nullptr)
    {
        printf("Can't Remove.\nNo associated value found with Key %d.\n", key);
    }
    else if (hashtable[hash_code]->key == key)
    {
        struct Node *temp = hashtable[hash_code];
        hashtable[hash_code] = temp->next;
        free(temp); // release memory
    }
    else if (hashtable[hash_code]->next == nullptr)
    {
        printf("Can't Remove.\nNo associated value found with Key %d.\n", key);
        return;
    }

    else {
        struct Node *temp = hashtable[hash_code];
        while (1)
        {
            if (temp->next->next != nullptr)
            {
                if (temp->next->key == key)
                {
                    struct Node *f = temp->next;
                    temp->next = temp->next->next;
                    free(f);
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
                    free(f);
                    break;
                }
                else
                {
                    printf("Can't Remove.\nNo associated value found with Key %d.\n", key);
                    break;
                }
            }
        }
    }
}

//Driver Function...
int main()
{
    put(10, 500);
    put(110, 503);
    put(210, 3);
    printf("Data  : %d , Key : %d\n",get(10),10);
    printf("Data  : %d , Key : %d\n",get(110),110);
    printf("Data  : %d , Key : %d\n",get(210),210);
    remove(110);
    remove(10);
    remove(210);
    printf("Data  : %d , Key : %d\n",get(10),10);
    printf("Data  : %d , Key : %d\n",get(110),110);
    printf("Data  : %d , Key : %d\n",get(210),210);

    return 0;
}