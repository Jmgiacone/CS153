/*
 * Name: GIACONE, JORDAN
 * Class and Section: CS153, Section C
 * Date: 5/12/14
 */

#ifndef BSTREE_HPP
#define BSTREE_HPP
#include "BSTreeNode.h"

template <typename T>
MyBSTree<T>::MyBSTree()
{
  root = NULL;
}

template <typename T>
MyBSTree<T>::~MyBSTree()
{
  clear();
}

template <typename T>
MyBSTree<T>::MyBSTree(const MyBSTree<T>& rhs)
{
  root = NULL;
  *this = rhs;
}

template <typename T>
int MyBSTree<T>::size() const
{
  return size(root);
}

template <typename T>
bool MyBSTree<T>::isEmpty() const
{
  return isEmpty(root);
}

template <typename T>
int MyBSTree<T>::height() const
{
  return height(root);
}

template <typename T>
const T& MyBSTree<T>::findMax() const
{
  return findMax(root);
}

template <typename T>
const T& MyBSTree<T>::findMin() const
{
  return findMin(root);
}

template <typename T>
int MyBSTree<T>::contains(const T& x) const
{
  return contains(root, x);
}

template <typename T>
void MyBSTree<T>::clear()
{
  clear(root);
}

template <typename T>
void MyBSTree<T>::insert(const T& x)
{
  insert(root, x);
}

template <typename T>
void MyBSTree<T>::remove(const T& x)
{
  remove(root, x);
}

template <typename T>
void MyBSTree<T>::printPreOrder() const
{
  printPreOrder(root);
}


template <typename T>
void MyBSTree<T>::printPostOrder() const
{
  printPostOrder(root);
}

template <typename T>
void MyBSTree<T>::print() const
{
  prettyPrint(root, 0);
}

template <typename T>
int MyBSTree<T>::size(BSTreeNode<T>* t) const
{
  if(t == NULL)
  {
    return 0;
  }

  return size(t->left) + size(t->right) + 1;
}

template <typename T>
bool MyBSTree<T>::isEmpty(BSTreeNode<T>* t) const
{
  return t == NULL;
}

template <typename T>
int MyBSTree<T>::height(BSTreeNode<T>* t) const
{
  int left, right;
  if(t == NULL)
  {
    return 0;
  }

  left = height(t->left);
  right = height(t->right);

  return (left > right ? left : right) + 1;
}

template <typename T>
const T& MyBSTree<T>::findMax(BSTreeNode<T>* t) const
{
  if(t == NULL)
  {
    throw std::string("PANIC : Tree is Empty!!");
  }
  if(t->right == NULL)
  {
    return t->data;
  }

  return findMax(t->right);
}

template <typename T>
const T& MyBSTree<T>::findMin(BSTreeNode<T>* t) const
{
  if(t == NULL)
  {
    throw std::string("PANIC : Tree is Empty!!");
  }

  if(t->left == NULL)
  {
    return t->data;
  }

  return findMin(t->left);
}

template <typename T>
int MyBSTree<T>::contains(BSTreeNode<T>* t, const T& x) const
{
  int level;
  if(t == NULL)
  {
    return -1;
  }

  if(t->data == x)
  {
    return 0;
  }

  if(x < t->data)
  {
    level = contains(t->left, x);
  }
  else if(x > t->data)
  {
    level = contains(t->right, x);
  }

  return (level < 0 ? level - 1 : level + 1);
}

template <typename T>
void MyBSTree<T>::clear(BSTreeNode<T>* &t)
{
  if(t != NULL)
  {
    clear(t->left);
    clear(t->right);
    delete t;
    t = NULL;
  }
}

template <typename T>
void MyBSTree<T>::insert(BSTreeNode<T>* &t, const T& x)
{
  if(t == NULL)
  {
    t = new BSTreeNode<T>(x, NULL, NULL);
    return;
  }

  if(x < t->data)
  {
    insert(t->left, x);
  }
  else if(x > t->data)
  {
    insert(t->right, x);
  }
  else
  {
    //Do nothing. It's here already
  }
}

template <typename T>
void MyBSTree<T>::remove(BSTreeNode<T>* &t, const T& x)
{
  if(t == NULL)
  {
    return;
  }

  if(x > t->data)
  {
    remove(t->right, x);
  }
  else if(x < t->data)
  {
    remove(t->left, x);
  }
  else
  {
    if(t->left != NULL && t->right != NULL)
    {
      t->data = findMax(t->left);
      remove(t->left, t->data);
    }
    else
    {
      BSTreeNode<T>* tmp = t;
      t = tmp->left;
      if(t == NULL)
      {
        t = tmp->right;
      }

      delete tmp;
    }
  }
}

template <typename T>
void MyBSTree<T>::printPreOrder(BSTreeNode<T>* t) const
{
  if(t != NULL)
  {
    std::cout << t->data << std::endl;

    printPreOrder(t->left);
    printPreOrder(t->right);
  }
}

template <typename T>
void MyBSTree<T>::printPostOrder(BSTreeNode<T>* t) const
{
  if(t != NULL)
  {
    printPostOrder(t->left);
    printPostOrder(t->right);

    std::cout << t->data << std::endl;
  }
}

template <typename T>
void prettyPrint(BSTreeNode<T>* t, int pad)
{
  std::string s(pad, ' ');
  if(t == NULL)
  {
    std::cout << std::endl;
  }
  else
  {
    prettyPrint(t->right, pad + 4);
    std::cout << s << t->data << std::endl;
    prettyPrint(t->left, pad + 4);
  }
}

template <typename T>
MyBSTree<T>& MyBSTree<T>::operator = (const MyBSTree<T>& rhs)
{
  if(this != &rhs)
  {
    clear();
    root = clone(rhs.root);
  }

  return *this;
}

template <typename T>
BSTreeNode<T>* clone(const BSTreeNode<T>* t)
{
  if (t == NULL)
      return NULL;
  else
  {
    return new BSTreeNode<T>(t->data, clone(t->left),clone(t->right));
  }
}
#endif // BSTREE_HPP
