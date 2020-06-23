#include <iostream>
#include <vector>

template <typename E>
class BinarySearchTree {

    private:
        struct Node {
            private:
                E value;
                Node* left;
                Node* right;
            
            public:
                Node(E val){
                    value = val;
                    left = nullptr;
                    right = nullptr;
                }

                Node(E val, Node* lfptr, Node* rtptr){
                    value = val;
                    left = lfptr;
                    right = rtptr;
                }

                E getValue(){
                    return value;
                }

                Node* getLeft(){
                    return left;
                }

                Node* getRight(){
                    return right;
                }

                void setValue(E val){
                    value = val;
                }

                void setLeft(Node* lftptr){
                    left = lftptr;
                }

                void setRight(Node* rtptr){
                    right = rtptr;
                }

                bool hasChildren(){
                    return (left != nullptr || right != nullptr);
                }
        };
        

        bool add(Node* prevptr, Node* currptr, E value){
            if(currptr == nullptr){
                Node* node = new Node(value, nullptr, nullptr);
                if(prevptr == nullptr){
                    root = node;
                    return true;
                }

                if(value < prevptr -> getValue()){
                    prevptr -> setLeft(node);
                }
                else{
                    prevptr -> setRight(node);
                }

                return true;
            }

            if(value < currptr -> getValue()){
                return add(currptr, currptr -> getLeft(), value);
            }
            if(value > currptr -> getValue()){
                return add(currptr, currptr -> getRight(), value);
            }

            return false;
        }

        void addSubtree(Node* prevptr, Node* currptr){
            if(currptr == nullptr){
                return;
            }

            add(prevptr, currptr, currptr -> getValue());
            addSubtree(currptr, currptr -> getLeft());
            addSubtree(currptr, currptr -> getRight());
        }


        bool remove(Node* prevptr, Node* currptr, E value){
            if(currptr == nullptr){
                return false;
            }

            if(value < currptr -> getValue()){
                return remove(currptr, currptr -> getLeft(), value);
            }

            if(value > currptr -> getValue()){
                return remove(currptr, currptr -> getRight(), value);
            }

            Node* succ = inOrderSuccessor(prevptr, currptr);
            if(prevptr != nullptr){            
                if(value < prevptr -> getValue()){
                    prevptr -> setLeft(succ);
                }
                if(value > prevptr -> getValue()){
                    prevptr -> setRight(succ);
                }
            }

            if(root == currptr){
                root = succ;
            }

            if(succ == nullptr){
                std::cout << "Successor is nullptr  ";
                delete currptr;
                return true;
            }            

            Node temp = *succ;

            succ -> setLeft(currptr -> getLeft());
            succ -> setRight(currptr -> getRight());

            std::cout << "Successor: " << succ -> getValue() << ", Left: " << succ -> getLeft() << ", Right: " << succ -> getRight() << "\t";
            
            currptr -> setLeft(nullptr);
            currptr -> setRight(nullptr);            

            addSubtree(&temp, temp.getLeft());
            addSubtree(&temp, temp.getRight());

            delete currptr;
            return true;
        }

        Node* inOrderSuccessor(Node* prevptr, Node* ptr){
            if(!ptr -> hasChildren()){
                return nullptr;
            }

            if(ptr -> getRight() != nullptr){
                prevptr = ptr;
                ptr = ptr -> getRight();

                bool hasLeft = false;
                while(ptr -> getLeft() != nullptr){
                    prevptr = ptr;
                    ptr = ptr -> getLeft();
                    hasLeft = true;
                }
                if(hasLeft){
                    prevptr -> setLeft(nullptr);
                }
                else{
                    prevptr -> setRight(nullptr);
                }
                
            }
            else{
                prevptr = ptr;
                ptr = ptr -> getLeft();
                prevptr -> setLeft(nullptr);
            }

            return ptr;
        }


        int size(Node* ptr){
            if(ptr == nullptr){
                return 0;
            }

            return 1 + size(ptr -> getLeft()) + size(ptr -> getRight());
        }

        int height(Node* ptr){
            if(ptr == nullptr){
                return 0;
            }
            
            return std::max(1 + height(ptr -> getLeft()), 1 + height(ptr -> getRight()));
        }

        void printInOrder(Node* ptr){
            if(ptr == nullptr){
                return;
            }
            printInOrder(ptr -> getLeft());
            std::cout << ptr -> getValue() << ", ";
            printInOrder(ptr -> getRight());
        }

        void printPreOrder(Node* ptr){
            if(ptr == nullptr){
                return;
            }

            std::cout << ptr -> getValue() << ", ";
            printPreOrder(ptr -> getLeft());
            printPreOrder(ptr -> getRight());
        }

        void printPostOrder(Node* ptr){
            if(ptr == nullptr){
                return;
            }

            printPostOrder(ptr -> getLeft());
            printPostOrder(ptr -> getRight());
            std::cout << ptr -> getValue() << ", ";
        }

        void printAsTree(Node* ptr, int no_of_tabs){
            if(ptr == nullptr){
                return;
            }

            printAsTree(ptr -> getRight(), no_of_tabs + 1);

            for(int i=0; i<=no_of_tabs; i++){
                std::cout << "    ";
            }
            std::cout << ptr -> getValue() << std::endl;

            printAsTree(ptr -> getLeft(), no_of_tabs + 1);
        }


        void removeAll(Node* ptr){
            if(ptr == nullptr){
                return;
            }
            if(ptr -> getLeft() == nullptr&& ptr -> getRight() == nullptr){
                delete ptr;
                return;
            }
            removeAll(ptr -> getLeft());
            removeAll(ptr -> getRight());
        }

        Node* root;

    public:
        BinarySearchTree(std::vector<E> collection);
        BinarySearchTree();
        ~BinarySearchTree();

        bool add(E value){
            return add(nullptr, root, value);
        }

        bool remove(E value){
            return remove(nullptr, root, value);
        }

        int size(){
            return size(root);
        }

        int height(){
            return height(root);
        }

        void printInOrder(){
            printInOrder(root);
        }

        void printPreOrder(){
            printPreOrder(root);
        }

        void printPostOrder(){
            printPostOrder(root);
        }

        void printAsTree(){
            printAsTree(root, 0);
        }
};


template <typename E>
BinarySearchTree<E>::BinarySearchTree(std::vector<E> collection) {
    if(collection.size() == 0){
        return;
    }
    root = nullptr;

    for(E e : collection){
        add(e);
    }
}

template <typename E>
BinarySearchTree<E>::BinarySearchTree() {
    root = nullptr;
}

template <typename E>
BinarySearchTree<E>::~BinarySearchTree() {
    removeAll(root);
}
