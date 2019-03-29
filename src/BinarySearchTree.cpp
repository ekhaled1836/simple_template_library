#include <bits/stdc++.h>

using namespace std;

template <typename> class BinaryTreeNode;

template <typename T> class BinaryTree {
public:
  BinaryTree(T pValue) : mRoot{new BinaryTreeNode<T>(pValue)} {}
  ~BinaryTree() { delete mRoot; }
	BinaryTreeNode<T>& root() { return *mRoot; }
	
private:
  BinaryTreeNode<T> *mRoot;
};

template <typename T> class BinaryTreeNode {
public:
  BinaryTreeNode(T &pValue) : mData{pValue}, mLeft{nullptr}, mRight{nullptr} {}
  BinaryTreeNode(T &&pValue) : mData{pValue}, mLeft{nullptr}, mRight{nullptr} {}
  ~BinaryTreeNode() {
    if (mLeft)
      delete mLeft;
    if (mRight)
      delete mRight;
  }
	BinaryTreeNode<T>& left(T pValue = 0) { if(!mLeft) mLeft = new BinaryTreeNode<T>(pValue); return *mLeft; }
	BinaryTreeNode<T>& right(T pValue = 0) { if(!mRight) mRight = new BinaryTreeNode<T>(pValue); return *mRight; }
	bool hasLeft() { return static_cast<bool>(mLeft); }
	bool hasRight() { return static_cast<bool>(mRight); }
	T& operator()() { return *mData; }
	T& operator[](uint8_t pTmp) { return *mData; }
	T& data() { return *mData; }

private:
  T mData;
  BinaryTreeNode<T> *mLeft;
  BinaryTreeNode<T> *mRight;
  friend class BinaryTree<T>;
};

int main() {
  // Do something with the BST once done.
  return 0;
}