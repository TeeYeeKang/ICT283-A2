//bst pointer

#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

    /**
     * @class BinaryTreePointer template class
     * @brief Represent the binary search tree
     *
     * This bst template class contains structure Node as member variables.
     * The data type depends on the type passed in by the user.
     * This class also contain necessary bst function, such as
     * inorder traversal, preorder traversal and so on.
     *
     * @author Tee Yee Kang
     * @version 01
     * @date 25/10/2021 Tee Yee Kang, Started
     *
     */

template <class T>
struct Node
{
    T info;
    Node<T> *lLink;
    Node<T> *rLink;
};

template <class T>
class BinaryTreePointer
{

public:
        /**
         * @brief Function pointer for traversal function used
         *
         * This function pointer is used for the inorder, preorder and postorder
         * traversal function based on the requirement.
         *
         * @return void
         */
    typedef void (*funcP)(T &);

        /**
         * @brief Add item into the bst
         *
         * This function is used to add new item into the bst. This is the
         * public version of insert function for users. The data
         * type depends on the type passed in by the user.
         *
         * @param insertItem - Item to add
         * @return void
         */
    void InsertItem(const T& insertItem);

        /**
         * @brief Search item from the bst
         *
         * This function is used to search a particular item from the bst.
         * This is the public version of search function for users. The data
         * type depends on the type passed in by the user.
         *
         * @param searchItem - Item to find
         * @return bool
         */
    bool SearchItem(const T& searchItem) const;

        /**
         * @brief Remove all elements in the bst
         *
         * This function is used to clear all items in the bst.
         * This is the public version of destroy bst function for users.
         *
         * @return void
         */
    void DestroyTree();

        /**
         * @brief Inorder traversal function. Search through every node in bst.
         *
         * This function is used to loop through every node in the bst
         * and perform parameter's task in the sequence of inorder.
         * This is the public version of inorder traversal function for users.
         *
         * @param fp - Function pointer
         * @return void
         */
    void InorderTraversal(funcP fp) const;

        /**
         * @brief Preorder traversal function. Search through every node in bst.
         *
         * This function is used to loop through every node in the bst
         * and perform parameter's task in the sequence of preorder.
         * This is the public version of preorder traversal function for users.
         *
         * @param fp - Function pointer
         * @return void
         */
    void PreorderTraversal(funcP fp) const;

        /**
         * @brief Postorder traversal function. Search through every node in bst.
         *
         * This function is used to loop through every node in the bst
         * and perform parameter's task in the sequence of Postorder.
         * This is the public version of Postorder traversal function for users.
         *
         * @param fp - Function pointer
         * @return void
         */
    void PostorderTraversal(funcP fp) const;

        /**
         * @brief Default constructor of binary search tree
         *
         * This is the default constructor. Inside the constructor will set the
         * Node type member variables to null value.
         */
    BinaryTreePointer();

        /**
         * @brief bst destructor
         *
         * Inside the destructor will clear all elements in the bst.
         */
    ~BinaryTreePointer();

        /**
         * @brief Copy constructor of binary search tree
         *
         * This is the copy constructor for deep copy purpose. Inside the constructor will set the
         * elements in the bst to the passed in bst object.
         */
    BinaryTreePointer(const BinaryTreePointer<T>& otherTree);

        /**
         * @brief Overload assignment operator
         *
         * This is the overload assignment operator used for deep copy.
         *
         */
    BinaryTreePointer<T>& operator=(const BinaryTreePointer& otherTree);

private:
    Node<T> *root;
    void CopyTree(Node<T>* &copiedTreeRoot, Node<T>* otherTreeRoot);
    void Destroy(Node<T>* &p);
    void Inorder(funcP fp, Node<T> *p) const;
    void Preorder(funcP fp, Node<T> *p) const;
    void Postorder(funcP fp ,Node<T> *p) const;
    bool SearchElement(Node<T>* nd, const T& item) const;
    void InsertElement(Node<T>*& nd, T item);
};

template <class T>
BinaryTreePointer<T>::BinaryTreePointer()
{
    root = nullptr;
}

//copy constructor
template<class T>
BinaryTreePointer<T>::BinaryTreePointer(const BinaryTreePointer<T>& otherTree)
{
    if(otherTree.root==nullptr)
    {
        root = nullptr;
    }
    else
    {
        CopyTree(root, otherTree.root);
    }
}

template<class T>
BinaryTreePointer<T>& BinaryTreePointer<T>::operator=(const BinaryTreePointer& otherTree)
{
    if(this != &otherTree)
    {
        this->DestroyTree();
        Node<T> *c = otherTree.root;
        CopyTree(root, c);
    }
    return *this;
}

template<class T>
void BinaryTreePointer<T>::CopyTree(Node<T>* &copiedTreeRoot, Node<T>* otherTreeRoot)
{
    if(otherTreeRoot==nullptr)
    {
        copiedTreeRoot = nullptr;
    }
    else
    {
        copiedTreeRoot = new Node<T>;
        copiedTreeRoot->info = otherTreeRoot->info;
        CopyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        CopyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
}

template<class T>
BinaryTreePointer<T>::~BinaryTreePointer()
{
    Destroy(root);
}

template <class T>
void BinaryTreePointer<T>::InorderTraversal(funcP fp) const
{
    Inorder(fp, root);
}

template <class T>
void BinaryTreePointer<T>::PreorderTraversal(funcP fp) const
{
    Preorder(fp, root);
}

template <class T>
void BinaryTreePointer<T>::PostorderTraversal(funcP fp) const
{
    Postorder(fp, root);
}

template <class T>
void BinaryTreePointer<T>::Inorder(funcP fp, Node<T> *p) const
{
    if(p!=nullptr)
    {
        Inorder(fp, p->lLink);
        (fp)(p->info);
        Inorder(fp, p->rLink);
    }
}

template <class T>
void BinaryTreePointer<T>::Preorder(funcP fp, Node<T> *p) const
{
    if(p!=nullptr)
    {
        (fp)(p->info);
        Preorder(fp, p->lLink);
        Preorder(fp, p->rLink);
    }
}

template <class T>
void BinaryTreePointer<T>::Postorder(funcP fp, Node<T> *p) const
{
    if(p!=nullptr)
    {
        Postorder(fp, p->lLink);
        Postorder(fp, p->rLink);
        (fp)(p->info);
    }
}

template<class T>
void BinaryTreePointer<T>::Destroy(Node<T>* &p)
{
    if(p!=nullptr)
    {
        Destroy(p->lLink);
        Destroy(p->rLink);
        delete p;
        p=nullptr;
    }
}

template<class T>
void BinaryTreePointer<T>::DestroyTree()
{
    Destroy(root);
}

template<class T>
bool BinaryTreePointer<T>::SearchItem(const T& searchItem) const
{
    if(SearchElement(root, searchItem))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
bool BinaryTreePointer<T>::SearchElement(Node<T>* nd, const T& item) const
{
    //base case
    if(nd == nullptr)
    {
        return false;
    }

    if(nd->info == item)
    {
        return true;
    }

    //recursive case
    if(item > nd->info)
    {
        return SearchElement(nd->rLink, item);
    }
    else
    {
        return SearchElement(nd->lLink, item);
    }
}

template<class T>
void BinaryTreePointer<T>::InsertItem(const T& insertItem)
{
    InsertElement(root, insertItem);
}

template<class T>
void BinaryTreePointer<T>::InsertElement(Node<T>*& nd, T item)
{
    if(nd == nullptr) // you are the root or you reached the end of a tree
    {
        nd = new Node<T>;
        nd->info = item;
        nd->lLink = nullptr;
        nd->rLink = nullptr;
    }
    else
    {
        if(item < nd->info)
        {
            InsertElement(nd->lLink, item);
        }
        else
        {
            InsertElement(nd->rLink, item);
        }
    }
}

#endif // BST_H


