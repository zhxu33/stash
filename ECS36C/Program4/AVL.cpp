#include "AVL.h"
#include <cassert>
#include <iostream>
#include <string>
#include <queue>
#include "json.hpp"

AVLNode::AVLNode(int key) :
	key_(key),
	parent_(std::weak_ptr<AVLNode>()),
	left_(nullptr),
	right_(nullptr) {}

AVLNode::AVLNode(int key, std::weak_ptr<AVLNode> parent) :
	key_(key),
	parent_(parent),
	left_(nullptr),
	right_(nullptr) {}

AVLTree::AVLTree() : root_(nullptr), size_(0) {}

//return to max of two integers
int max(int a, int b) {
	if (a>b) {
		return a;
	} 
	return b;
}

//return the height of a node
int height(std::shared_ptr<AVLNode> root)
{
    if (root == nullptr) {
        return -1;
    }
    return 1+max(height(root->left_), height(root->right_));
}

//return the balance factor of a node
int balanceFactor(std::shared_ptr<AVLNode> root) {
	return (height(root->right_) - height(root->left_));
}

void AVLTree::Insert(int key) {
	if (root_ == nullptr) {
		root_ = std::make_shared<AVLNode>(key);
		size_++;
		return;
	}
	std::shared_ptr<AVLNode> currentNode = root_, lastNode = nullptr;
	while (currentNode != nullptr) {
		lastNode = currentNode;
		currentNode = (key < currentNode->key_) ?
			currentNode->left_ : currentNode->right_;
	}
	if (key < lastNode->key_) {
		lastNode->left_ = std::make_shared<AVLNode>(key, lastNode);
	} else {
		lastNode->right_ = std::make_shared<AVLNode>(key, lastNode);
	}
	size_++;
	//rotation begins
    currentNode = lastNode;
	std::shared_ptr<AVLNode> a, b, c, p, ta1, ta2, tb1, tb2, tc1, tc2;
    while (currentNode != nullptr) {
		if (balanceFactor(currentNode) > 1) {
			if (balanceFactor(currentNode->right_) > 0) { //Right Right Problem, LL Rotation
				a = currentNode;
				b = a->right_;
				c = b->right_;
				p = a->parent_.lock();
				tb1 = b->left_;
				if (p != nullptr) {
					if (b->key_ > p->key_) {
						p->right_ = b;
					} else {
						p->left_ = b;
					}
					b->parent_ = p;
				} else {
					root_ = b;
					b->parent_.reset();
				}
				b->left_ = a;
				a->parent_ = b;
				a->right_ = tb1;
				if (tb1 != nullptr) {
					tb1->parent_ = a; 
				}
			} else if (balanceFactor(currentNode->right_) < 0) { //Right left problem, RL Rotation
				a = currentNode;
				c = a->right_;
				b = c->left_;
				p = a->parent_.lock();
				tb1 = b->left_;
				tb2 = b->right_;
				if (p != nullptr) {
					if (b->key_ > p->key_) {
						p->right_ = b;
					} else {
						p->left_ = b;
					}
					b->parent_ = p;
				} else {
					root_ = b;
					b->parent_.reset();
				}
				b->left_ = a;
				a->parent_ = b;
				b->right_ = c;
				c->parent_ = b;
				c->left_ = tb2; 
				if (tb2 != nullptr) {
					tb2->parent_ = c; 
				}
				a->right_ = tb1; 
				if (tb1 != nullptr) {
					tb1->parent_ = a; 
				} 
			}
		} else if (balanceFactor(currentNode) < -1) { //Left Right Problem, LR Rotation
			if (balanceFactor(currentNode->left_) > 0) {
				b = currentNode;
				a = b->left_;
				c = a->right_;
				p = b->parent_.lock();
				tc1 = c->left_;
				tc2 = c->right_;
				if (p != nullptr) {
					if (c->key_ > p->key_) {
						p->right_ = c;
					} else {
						p->left_ = c;
					}
					c->parent_ = p;
				} else {
					root_ = c;
					c->parent_.reset();
				} 
				c->left_ = a;
				a->parent_ = c;
				c->right_ = b;
				b->parent_ = c;
				a->right_ = tc1;
				if (tc1 != nullptr) {
					tc1->parent_ = a; 
				} 
				b->left_ = tc2;
				if (tc2 != nullptr) {
					tc2->parent_ = b; 
				}
			} else if (balanceFactor(currentNode->left_) < 0) { //Left Left Problem, RR Rotation
				c = currentNode;
				b = c->left_;
				a = b->left_;
				p = c->parent_.lock();
				tb2 = b->right_;
				if (p != nullptr) {
					if (b->key_ > p->key_) {
						p->right_ = b;
					} else {
						p->left_ = b;
					}
					b->parent_ = p;
				} else {
					root_ = b;
					b->parent_.reset();
				}
				b->right_ = c;
				c->parent_ = b;
				c->left_ = tb2;
				if (tb2 != nullptr) {
					tb2->parent_ = c; 
				}
			}
			currentNode = p; //progress to parent node
		} else {
			currentNode = currentNode->parent_.lock(); 
		}
    }
} 

bool AVLTree::empty() const {
	return size_ == 0;
}

std::string AVLTree::JSON() const {
	nlohmann::json result;
	std::queue< std::shared_ptr<AVLNode> > nodes;
	if (root_ != nullptr) {
		result["root"] = root_->key_;
		nodes.push(root_);
		while (!nodes.empty()) {
			auto v = nodes.front();
			nodes.pop();
			std::string key = std::to_string(v->key_);
			if (v == root_) {
				result[key]["root"] = true;
			}
			result[key]["height"] = height(v);
			result[key]["balance factor"] = balanceFactor(v);
			if (v->left_ != nullptr) {
				result[key]["left"] = v->left_->key_;
				nodes.push(v->left_);
			}
			if (v->right_ != nullptr) {
				result[key]["right"] = v->right_->key_;
				nodes.push(v->right_);
			}
			if (v->parent_.lock() != nullptr) {
				result[key]["parent"] = v->parent_.lock()->key_;
			} else {
				result[key]["root"] = true;
			}
		}
	}
	result["size"] = size_;
	result["height"] = height(root_);
	return result.dump(2) + "\n";
}
