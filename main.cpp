#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d, Node* l, Node* r) {
        this->data = d;
        this->left = l;
        this->right = r;
    }
};

struct ListCell {
    int item;
    ListCell* next;

    ListCell(int i, ListCell* n) {
        item = i;
        next = n;
    }
};

typedef ListCell* List;

// Tree operations
Node* insert(Node* root, int value);
bool isLeaf(Node* root);
void showTree(Node* root);
bool member(int x, Node* tree);

/* Random */
void reverse(const char* str);
int strLength(const char* str);
int maxArr(int A[], int n);

/*Linked list operations*/
bool isPrefix(const List A, const List B);
bool isEmpty(List a);
List tail(List l);
List cons(int n, List l);
int head(List l);
List negatives(const List l);
void showList(List l);

int main() {

    Node* t = new Node(6, NULL, NULL);
    cout << "Is it a leaf: " << isLeaf(t) << endl;
    insert(t, 5);
    insert(t, 90);
    insert(t, 21);
    showTree(t);
    cout << "\nMember = " << member(0, t);

    /*
    cout << "\nLength of string: " << strLength("Brandon") << endl;
    cout << "Reversed string ";
    reverse("Brandon");

    delete t;

    puts("\n");

    int test[4] = {1,2,21,5};
    cout << maxArr(test, 3);

    puts("\n");

    List a = new ListCell(1, new ListCell(2, new ListCell(3, new ListCell(4, NULL))));
    List b = new ListCell(1,
                          new ListCell(2, new ListCell(3, new ListCell(4, new ListCell(5, new ListCell(6, NULL))))));

    cout << "Is a prefix: " << isPrefix(a, b);

    delete a, b;

    puts("\n");

    List l = new ListCell(1, new ListCell(-2, new ListCell(5, new ListCell(-3, new ListCell(-10, NULL)))));
    List ans = negatives(l);
    showList(ans);

    delete l;
     */

    return 0;
}

void showList(List l)
{
    if (!isEmpty(l))
    {
        cout << l->item << " ";
        showList(tail(l));
    }
}

List cons(int n, List l)
{
    return new ListCell(n, l);
}

int head(List l)
{
    return l->item;
}

List tail(List l)
{
    return l->next;
}

bool isEmpty(List a)
{
    return a == NULL;
}

/**
 * This function computes if List A is a prefix of List B.
 *
 * Example:
 *
 * A = 1->2->3->4 \ B = 1->2->3->4->5->6
 * isPrefix(A,B) -> true
 *
 * @param A
 *  List
 * @param B
 *  List
 * @return
 *  Boolean
 */
bool isPrefix(const List A, const List B)
{
    if (isEmpty(A) || isEmpty(B))
    {
        return isEmpty(A);
    }
    return head(A) == head(B) ? isPrefix(tail(A), tail(B)) : false;
}

List negatives(const List l)
{
    if (!isEmpty(l))
    {
        List p = new ListCell(l->item*-1, negatives(l->next));
        return p;
    }
}

bool isLeaf(Node* root) {
    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    return false;
}

/**
 * Inserts a node in a tree
 *
 * @param root
 *  Root Node
 * @param value
 *  Integer Value
 * @return
 *  The root node
 */
Node* insert(Node* root, int value) {
    if (root == NULL) {
        root = new Node(value, NULL, NULL);
    } else if (isLeaf(root)) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}


void showTree(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        showTree(root->left);
        showTree(root->right);
    }

}

/**
 * This function searches a tree to find integer 'x'. If 'x' is present,
 * member returns true, false otherwise.
 *
 * @param x
 *  Integer to look for
 * @param tree
 *  Tree to search
 * @return
 *  Boolean
 */
bool member(int x, Node* tree)
{
    if (tree != NULL)
    {
        return x == tree->data ? true :
               member(x, tree->left) || member(x, tree->right);
    }
}

int strLength(const char* str)
{
    int ans = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        ans++;
    }
    return ans;
}

/**
 * Reverse a null-terminated string
 *
 * @param str
 *  A string
 */
void reverse(const char* str)
{
    if (str != NULL)
    {
        int len = strLength(str);
        char* newStr = new char[len+1]; // Added +1 to include '\0' character

        int j = 0;
        for (int i = len -1; i >= 0; i--)
        {
            newStr[j] = str[i];
            j++;
        }
        newStr[j] = '\0';
        cout << '\n' << newStr;
    }
}

/**
 * Returns the maximum number in an array using recursion
 *
 * @param A
 *  Integer array
 * @param n
 *  Integer specifying how many numbers to search
 * @return
 *  The greatest int value in the array
 */
int maxArr(int A[], int n)
{
    if (n == 1)
    {
        return A[0];
    }
    return max(maxArr(A, n-1), A[n-1]);
}
