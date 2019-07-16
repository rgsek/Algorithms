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

using namespace std;

class Node {
public:
    class Node(int data);
    Node* get_next();
    void set_next(Node* next);
    unsigned char get_data();
private:
    Node* m_next;
    unsigned char m_dummy;
};

Node::Node(int data)
{
    m_dummy = data;
    m_next = NULL;
}

Node* Node::get_next()
{
    return m_next;
}

unsigned char Node::get_data()
{
    return m_dummy;
}

void Node::set_next(Node* next)
{
    m_next = next;
}

void check_and_remove_loop(Node* head)
{
    // Take two pointers and point to head.
    Node* slow = head;
    Node* fast = head;

    while (slow && fast && fast->get_next())
    {
        // Move slow by one and fast by two. check if both meet
        // at some point
        slow = slow->get_next();
        fast = fast->get_next()->get_next();

        if (slow == fast)
        {
            cout << "Loop detected at " << slow->get_data() << endl;
            break;
        }
    }

    if (slow != fast)
    {
        cout << " No loop seen " << endl;
    }

    // Loop is seen. Now find the starting of the loop and remove it
    Node* start = head;
    while (start)
    {
        start = start->get_next();
        Node* temp = slow;
        slow = slow->get_next();

        // This is the begining of the loop. Remove it.
        // Note: the distance from start of linked list to start of loop will be
        // same as distance between where loop was seen and start of loop.
        // Wondering how??! Refer to the Floyd cycle detection algo :)
        if (start == slow)
        {
            temp->set_next(NULL);
            cout << "Loop starting " << slow->get_data()  << endl;
            cout << "Making " << temp->get_data() << " point to NULL"  << endl;
            break;
        }
    }
}

int main(int argc, char** argv)
{
    Node* A = new Node('A');
    Node* B = new Node('B');
    Node* C = new Node('C');
    Node* D = new Node('D');
    Node* E = new Node('E');
    Node* F = new Node('F');
    Node* G = new Node('G');
    Node* H = new Node('H');

    A->set_next(B);
    B->set_next(C);
    C->set_next(D);
    D->set_next(E);
    E->set_next(F);
    F->set_next(G);
    G->set_next(H);
    H->set_next(C);

    // create a loopy list now.
    // A -> B -> C -> D -> E
    //           |         |
    //           H <- G <- F

    check_and_remove_loop(A);

    // Call the above function again and it should return with no loop found
    cout << "Calling again after removing loop" << endl;
    check_and_remove_loop(A);
    return 0;
}
