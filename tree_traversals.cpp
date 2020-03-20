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
#include <list>
#include <stack>

using namespace std;

class node
{
public:
    node();
    node(int key, node* left, node* right);
    
    node* m_left;
    node* m_right;
    int m_key;
};

class BT
{
public:
    BT()
    {
        m_root = NULL;
    }
    void inorder(node* root);
    void preorder(node* root);
    void postorder(node* root);
    int insert(int key, node* root);
    node* get_root() { return m_root;}
private:
    node* m_root;
};


node::node(int key, node* left, node* right)
{
    m_key = key;
    m_left = left;
    m_right = right;
}

int
BT::insert(int key, node* root)
{
    if (!m_root)
    {
        m_root = new node(key, NULL, NULL);
        return 1;
    }

    if (root->m_key > key)
    {
        if (root->m_left)
        {
            if (root->m_left->m_key > key)
                return insert(key, root->m_left);
        }

        node* tmp = root->m_left;
        root->m_left = new node(key, tmp, NULL);
        return 1;
    }
    else if (root->m_key < key)
    {
        if (root->m_right)
        {
            if (root->m_right->m_key < key)
                return insert(key, root->m_right);

        }

        node* tmp = root->m_right;
        root->m_right = new node(key, NULL, tmp);
        return 1;
    }
    else
        return 1;
}

// Left subtree, root, right subtree
void BT::inorder(node* root)
{
    if (root)
    {
        inorder(root->m_left);
        cout << root->m_key << " ";
        inorder(root->m_right);
    }
}

// Root, left subtree, right subtree
void BT::preorder(node* root)
{
    if (root)
    {
        cout << root->m_key << " ";
        preorder(root->m_left);
        preorder(root->m_right);
    }
}

// left subtree, right subtree, root
void BT::postorder(node* root)
{
    if (root)
    {
        postorder(root->m_left);
        postorder(root->m_right);
        cout << root->m_key << " ";
    }
}

/*
Tree structure created by insert function
              25
           24    26
        20          27
     18                29
  12                     35
1
*/
int main(int argc, char** argv)
{
    BT binaryTree;

    binaryTree.insert(25, binaryTree.get_root());
    binaryTree.insert(20, binaryTree.get_root());
    binaryTree.insert(27, binaryTree.get_root());
    binaryTree.insert(18, binaryTree.get_root());
    binaryTree.insert(24, binaryTree.get_root());
    binaryTree.insert(29, binaryTree.get_root());
    binaryTree.insert(35, binaryTree.get_root());
    binaryTree.insert(1, binaryTree.get_root());
    binaryTree.insert(12, binaryTree.get_root());
    binaryTree.insert(26, binaryTree.get_root());

    cout << "Inorder " << endl;
    binaryTree.inorder(binaryTree.get_root());
    cout << endl;

    cout << "Preorder " << endl;
    binaryTree.preorder(binaryTree.get_root());
    cout << endl;

    cout << "Postorder " << endl;
    binaryTree.postorder(binaryTree.get_root());
    cout << endl;

    return 0;
}
