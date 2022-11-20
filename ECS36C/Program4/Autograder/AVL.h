#include <memory>
#include <string>

class AVLNode {
 public:
 	AVLNode(int key);
 	AVLNode(int key, std::weak_ptr<AVLNode> parent);
	int key_;
	std::weak_ptr<AVLNode> parent_;
	std::shared_ptr<AVLNode> left_;
	std::shared_ptr<AVLNode> right_;
}; 

class AVLTree {
 public:
 	AVLTree();
 	void Insert(int key);
 	std::string JSON() const;
 	bool empty() const;
 private:
 	std::shared_ptr<AVLNode> root_;
 	size_t size_;
};