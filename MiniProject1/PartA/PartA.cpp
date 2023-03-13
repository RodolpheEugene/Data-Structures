#include <iostream>
#include<vector>
#include <algorithm>
#include <iterator>

using namespace std;
class Node {
public:

    int data;
    int bf;
    int height;
    Node* parent;
    Node* left;
    Node* right;

    Node() {
        data = 0;
        bf = 0;
        height = 0;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
    Node(int val) {
        data = val;
        bf = 0;
        height = 0;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
};
Node* myRoot;
vector<int> result;
Node* next(Node* n, Node* root);
Node* leftDescendent(Node* n);
Node* rightAncestor(Node* n, Node* root);
Node* rotateLeft(Node* node);
Node* avlDelete(int data, Node* root);
int balanceFactor(Node* root);
int getHeight(Node* n);
//Node* rebalance(Node* root);
Node* rebalance(Node* node, Node* tempNode);
Node* rebalanceLeft(Node* node);
Node* rebalanceRight(Node* node);
Node* rotateRight(Node* node);
void adjustHeight(Node* n);
Node* AVLInsert(Node* node, int val);
vector<int> rangeSearch(int valx, int valy, Node* root);
int height(Node* node);
void inorder(Node* currentPtr);
Node* insert(Node* root,
    Node* element);
int add(Node* currentPtr);
int find(Node* currentPtr, int val);
Node* parent(Node* root, Node* node);
Node* minVal(Node* root);
Node* maxVal(Node* root);
int isLeaf(Node* node);
int hasOnlyLeftChild(Node* node);
int hasOnlyRightChild(Node* node);
Node* findNode(Node* currentPtr, int value);
Node* deleteNode(Node* root, int value);
<<<<<<< main
Node* avlInsertA(Node* root, Node* tempNode);
=======
>>>>>>> main
int menu();

void inorder(Node* currentPtr) {
    // Only traverse the node if it's not null.
    if (currentPtr != NULL) {
        inorder(currentPtr->left); // Go Left.
        cout << " " << currentPtr->data; // Print the root.
        inorder(currentPtr->right); // Go Right.
    }
}
int add(Node* currentPtr) {
    if (currentPtr != NULL)
        return currentPtr->data + add(currentPtr->left) +
        add(currentPtr->right);
    else
        return 0;
}
// Returns a pointer to the node storing the minimum value in the tree
Node* minVal(Node* root) {
    // Root stores the minimal value.
    if (root->left == NULL)
        return root;
    // The left subtree of the root stores the minimal value.
    else
        return minVal(root->left);
}
// Returns a pointer to the node storing the maximum value in the tree
Node* maxVal(Node* root) {
    // Root stores the maximal value.
    if (root->right == NULL)
        return root;
    // The right subtree of the root stores the maximal value.
    else
        return maxVal(root->right);
}
// Returns 1 if node is a leaf node, 0 otherwise.
int isLeaf(Node* node) {
    return (node->left == NULL && node->right == NULL);
}
// Returns 1 iff node has a left child and no right child.
int hasOnlyLeftChild(Node* node) {
    return (node->left != NULL && node->right == NULL);
}
// Returns 1 iff node has a right child and no left child.
int hasOnlyRightChild(Node* node) {
    return (node->left == NULL && node->right != NULL);
}

// Will delete the node storing value in the tree rooted at root. The
// value must be present in the tree in order for this function to work.
// The function returns a pointer to the root of the resulting tree.
Node* deleteNode(Node* root, int value) {
    Node* delnode, * newDelNode, * saveNode;
    Node* par;
    int saveVal;
    delnode = findNode(root, value); // Get a pointer to the node to delete.
    par = parent(root, delnode); // Get the parent of this node.
    // Take care of the case where the node to delete is a leaf node.
    if (isLeaf(delnode)) {// case 1
        // Deleting the only node in the tree.
        if (par == NULL) {
            delete root; // free the memory for the node.
            return NULL;
        }
        // Deletes the node if it's a left child.
        if (value < par->data) {
            delete par->left; // Free the memory for the node.
        }
        // Deletes the node if it's a right child.
        else {
            delete par->right; // Free the memory for the node.
            par->right = NULL;
        }
        return root; // Return the root of the new tree.
    }
    // Take care of the case where the node to be deleted only has a left
    // child.
    if (hasOnlyLeftChild(delnode)) {
        // Deleting the root node of the tree.
        if (par == NULL) {
            saveNode = delnode->left;
            delete delnode; // Free the node to delete.
            return saveNode; // Return the new root node of the resulting tree.
        }
        // Deletes the node if it's a left child.
        if (value < par->data) {
            saveNode = par->left; // Save the node to delete.
            par->left = par->left->left; // Readjust the parent pointer.
            delete saveNode; // Free the memory for the deleted node.
        }
        // Deletes the node if it's a right child.
        else {
            saveNode = par->right; // Save the node to delete.
            par->right = par->right->left; // Readjust the parent pointer.
            delete saveNode; // Free the memory for the deleted node.
        }
        return root; // Return the root of the tree after the deletion.
    }
    // Takes care of the case where the deleted node only has a right child.
    if (hasOnlyRightChild(delnode)) {
        // Node to delete is the root node.
        if (par == NULL) {
            saveNode = delnode->right;
            delete delnode;
            return saveNode;
        }
        // Delete's the node if it is a left child.
        if (value < par->data) {
            saveNode = par->left;
            par->left = par->left->right;
            delete saveNode;
        }
        // Delete's the node if it is a right child.
        else {
            saveNode = par->right;
            par->right = par->right->right;
            delete saveNode;
        }
        return root;
    }
    //when delnode has two children
      // Find the new physical node to delete.
    newDelNode = minVal(delnode->right);
    saveVal = newDelNode->data;
    deleteNode(root, saveVal);  // Now, delete the proper value.
    // Restore the data to the original node to be deleted.
    delnode->data = saveVal;
    return root;
}
int find(Node* currentPtr, int val) {
    // Check if there are nodes in the tree.
    if (currentPtr != NULL) {
        // Found the value at the root.
        if (currentPtr->data == val)
            return 1;
        // Search to the left.
        if (val < currentPtr->data)
            return find(currentPtr->left, val);
        // Or search to the right.
        else
            return find(currentPtr->right, val);
    }
    else
        return 0;
}

// Returns the parent of the node pointed to by node in the tree rooted at
// root. If the node is the root of the tree, or the node doesn't exist in
// the tree, null will be returned.
Node* parent(Node* node, Node* root) {
    // Take care of NULL cases.
    if (root == NULL || root == node)
        return NULL;
    // The root is the direct parent of node.
    if (root->left == node || root->right == node)
        return root;
    // Look for node's parent in the left side of the tree.
    if (node->data < root->data)
        return parent(root->left, node);
    // Look for node's parent in the right side of the tree.
    else if (node->data > root->data)
        return parent(root->right, node);
    return NULL; // For any other cases.
}
Node* next(Node* n, Node* root) {

    if (n->right != NULL) {
        return leftDescendent(n->right);
    }
    else {
        return rightAncestor(n, root);
    }
}
Node* leftDescendent(Node* n) {
    cout << "leftdesc: " << n->data << endl;
    if (n->left == NULL) {
        return n;
    }
    else {
        return leftDescendent(n->left);
    }
}
Node* rightAncestor(Node* n, Node* root) {
    cout << "right anc.: " << n->data << endl;

    Node* par = parent(n, root);
    if (par == NULL) {
        return NULL;
    }
    if (n->data < par->data) {
        return par;
    }
    else {
        return rightAncestor(par, root);
    }
    //return par;
}
vector<int> rangeSearch(int x, int y, Node* root) {

    vector<int> result;

    Node* temp = findNode(root, x);
    cout << "findnode: " << temp->data << endl;

    while (temp != NULL && temp->data <= y) {
        if (temp->data >= x) {
            result.push_back(temp->data);
        }
        temp = next(temp, root);
        if (temp != NULL) {
            cout << "next: " << temp->data << endl;
        }
        else {
            cout << "no next" << endl;
        }
    }
    cout << "result size: " << result.size() << endl;
    return result;
}
int addRange(int x, int y, Node* root) {

<<<<<<< main
    vector<int> result;
    int sum = 0;

    Node* temp = findNode(root, x);
    cout << "findnode: " << temp->data << endl;

    while (temp != NULL && temp->data <= y) {
        if (temp->data >= x) {
            sum = sum + temp->data;
        }
        temp = next(temp, root);
        if (temp != NULL) {
            cout << "next: " << temp->data << endl;
        }
        else {
            cout << "no next" << endl;
        }
    }
    cout << "result size: " << result.size() << endl;
    return sum;
}
Node* avlDelete(int data, Node* root) {

    Node* temp = new Node();
    Node* n = findNode(root, data);
    deleteNode(n, data);
    Node* M = parent(n, root);
    rebalance(M, temp);
=======
    Node* n = findNode(root, data);
    deleteNode(n, data);
    Node* M = parent(n, root);
    //rebalance(M);
>>>>>>> main

    return root;
}
// Rebalance function
Node* rebalance(Node* node, Node* tempNode) {
    int bf = balanceFactor(node);

    // Left Left Case
    if (bf > 1 && tempNode->data < node->left->data)
        return rotateRight(node);
    // Right Right Case
    if (bf < -1 && tempNode->data < node->right->data)
        return rotateLeft(node);
    // Left Right Case
    if (bf > 1 && tempNode->data < node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    // Right left Case
    if (bf < -1 && tempNode->data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    // updates the height of the tree
    adjustHeight(node);
    // when the node pointer does not change
    return node;
}

// max Function
int max(int a, int b) {
    return (a > b) ? a : b;
}
<<<<<<< main
bool isUnbalanced(Node* root) {

    if (root == NULL) {
        return false;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

=======
/*bool isUnbalanced(Node* root) {

    if (root == NULL) {
        return false;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

>>>>>>> main
    if (abs(leftHeight - rightHeight) > 1) {
        return true;
    }
    return isUnbalanced(root->left) || isUnbalanced(root->right);
<<<<<<< main
}
=======
}*/
>>>>>>> main
/*int getHeight(Node* n) {
    if (n == NULL) {
        return 0;
    }
    return 1 + max(getHeight(n->left), getHeight(n->right));
}*/
// Compute BF Function using recursive method
int balanceFactor(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}
// Compute Height Function
int height(Node* node) {
    if (node == NULL)
        return 0;
    else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // check for max value and adds 1 to it
        return max(leftHeight, rightHeight) + 1;
    }

}
// function to update the tree
void adjustHeight(Node* n) {
    n->height = 1 + max(height(n->left), height(n->right));
}


// Rotate Left Function suing recursive method
Node* rotateLeft(Node* node) {

    Node* temp1 = node->right;
    Node* temp2 = temp1->left;

    // rotation
    temp1->left = node;
    node->right = temp2;

    // update height of AVL
    adjustHeight(node);
    adjustHeight(temp1);

    // return the new root
    return temp1;
}

// Rotation Right Function
Node* rotateRight(Node* node) {
    Node* temp1 = node->left;
    Node* temp2 = temp1->right;

    // rotation
    temp1->right = node;
    node->left = temp2;

    // update height of AVL
    adjustHeight(node);
    adjustHeight(temp1);

    // return the new root
    return temp1;
}

// Function to rebalanceRight

Node* rebalanceRight(Node* node) {
    if (balanceFactor(node) < -1) {
        if (balanceFactor(node->left) > 0) {
            node->left - rotateLeft(node->left);
        }
        return rotateRight(node);
    }
    return node;
}

// Function to rebalanceLeft
Node* rebalanceLeft(Node* node) {
    if (balanceFactor(node) > 1) {
        if (balanceFactor(node->right) < 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }
    return node;
}
// AVLInsert function
  // use Rebalance and Find functions inside of AVLInsert
Node* AVLInsert(Node* node, int val) {
    if (node == NULL) {
        cout << "Value is inserted" << endl;
        return new Node(val);
    }

    if (val < node->data) {
        node->left = AVLInsert(node->left, val);
    }
    else if (val > node->data) {
        node->right = AVLInsert(node->right, val);
    }
    else {
        return node;
    }
    adjustHeight(node);
    findNode(node, val);
    node = rebalanceRight(node);
    node = rebalanceLeft(node);

    return node;
}
<<<<<<< main
Node* avlInsertA(Node* root, Node* tempNode) {

    insert(root, tempNode);
    Node* newTemp = findNode(root, tempNode->data);
    rebalance(root, newTemp);
    return root;
}
Node* insert(Node* root, Node* element) {

    // Inserting into an empty tree.
    if (root == NULL) {
        return element;
    }
    else {
        // element should be inserted to the right.
        if (element->data > root->data) {
            // There is a right subtree to insert the node.
            if (root->right != NULL)
                root->right = insert(root->right, element);
            // Place the node directly to the right of root.
            else
                root->right = element;
        }
        // element should be inserted to the left.
        else {
            // There is a left subtree to insert the node.
            if (root->left != NULL)
                root->left = insert(root->left, element);
            // Place the node directly to the left of root.
            else
                root->left = element;
        }
        // Return the root pointer of the updated tree.
        return root;
    }
}
// Returns a pointer to a node that stores value in it in the subtree
Node* findNode(Node* currentPtr, int value) {
    // Check if there are nodes in the tree.
    if (currentPtr != NULL) {
        // Found the value at the root.
        if (currentPtr->data == value)
            return currentPtr;
        // Search to the left.
        if (value < currentPtr->data)
            return findNode(currentPtr->left, value);
        // Or search to the right.
        else
            return findNode(currentPtr->right, value);
    }
    else
        return NULL; // No node found.
}
=======
>>>>>>> main


void print(std::vector<int> const& result) {
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
}

// Prints out the menu of choices for the user and returns their choice.
int menu() {
    int ans;
    cout << "Here are your choices.\n";
    cout << "1. Insert an item into your tree.\n";
    cout << "2. Delete an item from your tree.\n";
    cout << "3. Search for an item in your tree.\n";
    cout << "4. Print the sum of the nodes. \n";
<<<<<<< main
    cout << "5. Print the next element of the node with key x.\n";
    cout << "6. Find elements between x and y:  \n";
    cout << "7. Find the height of the tree: \n";
    cout << "8. Print the sum of the list of elements between x and y: \n";
    cout << "9 Print out an inorder traversal: \n";
    cout << "10. Exit.\n";
=======
    cout << "5. Print out an inorder traversal.\n";
    cout << "6. Find elements between x and y:  \n";
    cout << "7. Exit.\n";
>>>>>>> main
    cin >> ans;
    return ans;
}
int main() {
    Node* myRoot = NULL, * tempNode;
    int done = 0, ans = 1, val, q6data, valx, valy;
    vector<int> result = {};
    vector<int> result1 = { 1,2,3 };
    ans = menu();
    while (ans < 12) {
        if (ans == 1) {
            // Get value to insert.
            cout << "What value would you like to insert?";
            cin >> val;
            tempNode = new Node(val); // Create the node.
            // Insert the value.
<<<<<<< main
            //myRoot = AVLInsert(myRoot, val);
            myRoot = avlInsertA(myRoot, tempNode);

=======
            myRoot = AVLInsert(myRoot, val);
>>>>>>> main
        }
        if (ans == 2) {
            cout << "What value would you like to delete?\n";
            cin >> val;
            if (!find(myRoot, val))
                cout << "Sorry that value isn't in the tree to delete.\n";
            else {
                myRoot = deleteNode(myRoot, val);
            }
        }
        if (ans == 3) {
            cout << "What value would you like to search for?\n";
            cin >> val;
            if (find(myRoot, val))
                cout << " Found" << val << "in the tree.\n";
            else
                cout << " Did not find %d in the tree.\n";
        }
        if (ans == 4)
            cout << "The sum of the nodes in your tree is" << add(myRoot) << "\n";
        if (ans == 9) {
            // Print the resulting tree.
            cout << "Here is an inorder traversal of your tree: ";
            inorder(myRoot);
            cout << "\n";
        }
        if (ans == 6) {
            cout << "Please enter x value: ";
            cin >> valx;
            cout << "Please enter y value: ";
            cin >> valy;
            print(rangeSearch(valx, valy, myRoot));
            print(result);
        }
        if (ans == 5) {
            cout << "Which element do wish to find the next node in the tree? \n";
            cin >> val;
            Node* m = next(findNode(myRoot, val));
            cout << "The next node is: " << m->data  << "\n";

        }
        if (ans == 7) {
            cout << "The height of the tree is: " << height(myRoot) << "\n";
        }
        if (ans == 8) {
            cout << "Please enter x value: ";
            cin >> valx;
            cout << "Please enter y value: ";
            cin >> valy;
            cout << "the sum of the nodes between x and y is: " << addRange(valx, valy, myRoot) << "\n";
        }
        if (ans == 10)
            exit(0);

        // See if they want to insert more nodes.
        ans = menu();
    }
    return 0;
}
