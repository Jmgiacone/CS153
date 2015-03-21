/*
 * Name: GIACONE, JORDAN
 * Class and Section: CS153, Section C
 * Date: 5/12/14
 */

#ifndef BSTREENODE_H
#define BSTREENODE_H
template <typename T>
struct BSTreeNode
{
  T data;
  BSTreeNode* left, *right;
  BSTreeNode<T>(T x, BSTreeNode* l, BSTreeNode* r) : data(x), left(l), right(r){}
};
#endif
