
#include <iostream>
#include "bst.h"
#include "Date.h"
#include <fstream>
#include <string>
#include "CollectData.h"
#include "Value.h"

using namespace std;

float CollectData::m_total;
float CollectData::m_max;

void IntegerTree();
void DateTree();
bool operator>(const Date & first, const Date & second);
void Print(int &data);
void Print(Date &data);

int main()
{
    IntegerTree();
    cout<<"--------------------------------------------\n"<<endl;
    DateTree();

    return 0;
}

void IntegerTree()
{
    BinaryTreePointer<int> tree;

    ifstream infile("numberFile.txt");

    if(infile.is_open())
    {
        while(!infile.eof())
        {
            int number;
            infile >> number;
            tree.InsertItem(number);
        }
    }
    else
    {
        cout << "Fail to open the file" << endl;
    }

    infile.close();

    cout << "After inserting 10 numbers\n" << endl;
    cout << "Test for inorder traversal" << endl;
    tree.InorderTraversal(Print);
    cout << "\nTest for preorder traversal" << endl;
    tree.PreorderTraversal(Print);
    cout << "\nTest for postorder traversal" << endl;
    tree.PostorderTraversal(Print);

    cout << "\n\nTest for search function" << endl;
    if(tree.SearchItem(8))
        cout << "Number 8 exists in the tree" << endl;
    else
        cout << "Number 8 does not exist in the tree" <<endl;
    if(tree.SearchItem(99))
        cout << "Number 99 exists in the tree" << endl;
    else
        cout << "Number 99 does not exist in the tree" <<endl;

    cout<<"--------------------------------------------\n"<<endl;
    cout<<"Test for deep copy"<<endl;
    //binaryTreePointer<int> newTree(tree);
    BinaryTreePointer<int> newTree;
    newTree = tree;
    newTree.InorderTraversal(Print);
    cout<<"\n";
    newTree.PreorderTraversal(Print);
    cout<<"\n";
    newTree.PostorderTraversal(Print);
    cout<<"\n";

    cout << "\n\nTest for destroy function" << endl;
    tree.DestroyTree();
    tree.InorderTraversal(Print);
    cout<<endl;
}

void DateTree()
{
    string day, month, year;
    int d, m, y;
    BinaryTreePointer<Date> tree;

    Date d1(1,1,2020);
    Date d2(2,2,2020);
    Date d3(3,3,2020);
    Date d4(4,4,2020);
    Date d5(5,5,2020);
    Date d6(6,6,2020);

    tree.InsertItem(d1);
    tree.InsertItem(d2);
    tree.InsertItem(d3);
    tree.InsertItem(d4);
    tree.InsertItem(d5);
    tree.InsertItem(d6);

    cout << "After inserting all date\n" << endl;
    cout << "Test for inorder traversal" << endl;
    tree.InorderTraversal(Print);
    cout << "\nTest for preorder traversal" << endl;
    tree.PreorderTraversal(Print);
    cout << "\nTest for postorder traversal" << endl;
    tree.PostorderTraversal(Print);

    cout << "\n\nTest for search function" << endl;
    Date date(3,3,20);
    Date date02(11,11,2011);
    if(tree.SearchItem(date))
        cout << "Date 3/3/2020 exists in the tree" << endl;
    else
        cout << "Date 3/3/2020 does not exist in the tree" <<endl;

    if(tree.SearchItem(date02))
        cout << "Date 11/11/2011 exists in the tree" << endl;
    else
        cout << "Date 11/11/2011 does not exist in the tree" <<endl;

    cout << "\nTest for destroy function" << endl;
    tree.DestroyTree();
    tree.InorderTraversal(Print);
    cout<<endl;
}

bool operator>(const Date & first, const Date & second)
{
    if(first == second)
    {
        return false;
    }

    if(first.GetYear()>second.GetYear())
        return true;
    else
        return false;

    if(first.GetYear()==second.GetYear())
    {
        if(first.GetMonth()>second.GetMonth())
            return true;
        else
            return false;
    }

    if(first.GetYear()== second.GetYear())
    {
        if(first.GetMonth()== second.GetMonth())
        {
            if(first.GetDay()>second.GetDay())
                return true;
            else
                return false;
        }
    }
}

void Print(int &data)
{
    cout << data << "  ";
}

void Print(Date &data)
{
    cout << data << "  ";
}

