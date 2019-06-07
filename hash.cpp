/*
 * Copyright 2019
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Gnanasekar Rajakumar (gnanasekar.r29@gmail.com)
 */

#include <iostream>
#include <string>


using namespace std;

#define HASH_SIZE 64

class node
{
public:
    node();
    node(char* key, char* value);
    node* next;
    char* getkey() { return m_key; }
    char* getvalue() { return m_value; }
    void setvalue(char* value) { m_value = _strdup(value); }
private:
    char* m_key;
    char* m_value;
    
};

node::node(char* key, char* value)
{
    m_key = _strdup(key);
    m_value = _strdup(value);
    next = NULL;
}

class hashtbl
{
public:
    hashtbl();
    void insert(char* key, char* value);
    char* getvalue(char* key);
    void deletekey(char* key);
private:
    // Take an array of 1K size
    node* m_hash_array[HASH_SIZE];
    int hashcode(char* key);
};

hashtbl::hashtbl()
{
    memset(m_hash_array, '\0', sizeof(m_hash_array));
}

// Lets use string len as hash code which will be used as index into the 
// hash table
int hashtbl::hashcode(char* key)
{
    int code = strlen(key);
    return (code % HASH_SIZE);
}

char* hashtbl::getvalue(char* key)
{
    int index = hashcode(key);
    if (!m_hash_array[index])
        return NULL;

    node* head = m_hash_array[index];
    while (head)
    {
        if (strcmp(head->getkey(), key) == 0)
            return head->getvalue();

        head = head->next;
    }

    return NULL;
}

void hashtbl::deletekey(char* key)
{
    int index = hashcode(key);
    if (!m_hash_array[index])
        return;

    node* head = m_hash_array[index];
    // If it is the only element, then remove and mark it as NULL
    // If it is the first element, then remove and make next element as first
    if (strcmp(head->getkey(), key) == 0)
    {
        m_hash_array[index] = head->next;
        delete head;
        return;
    }

    // otherwise delete the entry in the chain
    node* prev = head;
    head = head->next;
    while (head)
    {
        if (strcmp(head->getkey(), key) == 0)
        {
            prev->next = head->next;
            delete head;
            return;
        }
        prev = head;
        head = head->next;
    }
}


// Using chaining to avoid key collision
void hashtbl::insert(char* key, char* value)
{
    int index = hashcode(key);

    // key already exist just add to the list
    if (m_hash_array[index])
    {
        node* tmp = NULL;
        node* head = m_hash_array[index];
        // check if the key already exist. If so overwrite the value
        while (head)
        {
            if (strcmp(head->getkey(), key) == 0)
            {
                head->setvalue(value);
                break;
            }
            tmp = head;
            head = head->next;
        }
        // otherwise insert the key value pair in the end
        if (head == NULL)
        {
            node* newnode = new node(key, value);
            tmp->next = newnode;
        }
    }
    else
    {
        node* newnode = new node(key, value);
        m_hash_array[index] = newnode;
    }
}

int main(int argc, char** argv)
{
    hashtbl myhash;
    myhash.insert("chennai", "hot");
    myhash.insert("Bangalore", "cold");
    myhash.insert("Delhi", "humid");
    myhash.insert("Bombay", "busy");
    myhash.insert("Tanjore", "temples");
    myhash.insert("Mysore", "Palace");

    cout << "chennai = " << myhash.getvalue("chennai") << endl;
    cout << "Bangalore = " << myhash.getvalue("Bangalore") << endl;
    cout << "Delhi = " << myhash.getvalue("Delhi") << endl;
    cout << "Bombay = " << myhash.getvalue("Bombay") << endl;
    cout << "Mysore = " << myhash.getvalue("Mysore") << endl;
    cout << "Tanjore = " << myhash.getvalue("Tanjore") << endl;
    if (!myhash.getvalue("Kolkata"))
    cout << "Kolkata = " << "Key does not exist " << endl;

    //overwrite a key now
    cout << endl << "chennai key overwritten" << endl;
    myhash.insert("chennai", "super");
    cout << "chennai = " << myhash.getvalue("chennai") << endl;


    //delete a key now
    cout << endl << "chennai key delete" << endl;
    myhash.deletekey("chennai");
    if (!myhash.getvalue("chennai"))
        cout << "chennai = " << "Key does not exist " << endl;
    cout << "Bangalore = " << myhash.getvalue("Bangalore") << endl;
    cout << "Delhi = " << myhash.getvalue("Delhi") << endl;
    cout << "Bombay = " << myhash.getvalue("Bombay") << endl;
    cout << "Mysore = " << myhash.getvalue("Mysore") << endl;
    cout << "Tanjore = " << myhash.getvalue("Tanjore") << endl;
}