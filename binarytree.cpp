#include "binarytree.h"

using namespace std;

bool isPrime(int num, int divisor);

namespace hardendavebintree {
    binarytree::binarytree() {
        rootptr = nullptr;
    }


    void binarytree::print() {
        print_aux(rootptr);
    }


    void print_aux(binarytree::node *rootptr) {
        if (rootptr != nullptr) {
            print_aux(rootptr->left);
            cout << rootptr->data << " ";
            print_aux(rootptr->right);
        }
    }


    void binarytree::insert(int num) {
        insert_aux(rootptr, num);
    }


    void insert_aux(binarytree::node *&rootptr, int num) {
        if (rootptr == nullptr) {
            rootptr = new binarytree::node;
            rootptr->data = num;
            rootptr->left = nullptr;
            rootptr->right = nullptr;
        } else if (num <= rootptr->data) {
            insert_aux(rootptr->left, num);
        } else {
            insert_aux(rootptr->right, num);
        }
    }


    int binarytree::find(int num, bool &found) {
        return find_aux(rootptr, num, found);
    }


    int find_aux(const binarytree::node *rootptr, int num, bool &found) {
        if (rootptr == nullptr) {
            found = false;
            return 0;
        } else if (rootptr->data == num) {
            found = true;
            return rootptr->data;
        } else if (num < rootptr->data) {
            return find_aux(rootptr->left, num, found);
        } else {
            return find_aux(rootptr->right, num, found);
        }
    }


    void binarytree::del(int num, bool &found) {
        del_aux(rootptr, num, found);
    }


    void del_aux(binarytree::node *&rootptr, int num, bool &found) {
        if (rootptr == nullptr) {
            found = false;
        } else if (num < rootptr->data) {
            del_aux(rootptr->left, num, found);
        } else if (num > rootptr->data) {
            del_aux(rootptr->right, num, found);
        } else if (rootptr->left == nullptr) {
            binarytree::node *tempptr = rootptr;
            rootptr = rootptr->right;
            delete tempptr;
            found = true;
        } else {
            int max;
            remove_max(rootptr->left, max);
            rootptr->data = max;
            found = true;
        }
    }


    void remove_max(binarytree::node *&rootptr, int &max) {
        if (rootptr->right == nullptr) {
            max = rootptr->data;
            binarytree::node *tempptr = rootptr;
            rootptr = rootptr->left;
            delete tempptr;
        } else {
            remove_max(rootptr->right, max);
        }
    }


    binarytree::size_type binarytree::size() {
        binarytree::size_type numberOfItems = 0;
        binarytree::node *currptr = rootptr;

        while (currptr != nullptr) {
            if (currptr->left == nullptr) {
                currptr = currptr->right;
                ++numberOfItems;
            } else if (currptr->right == nullptr) {
                currptr = currptr->left;
                ++numberOfItems;
            }
        }
        return numberOfItems;
    }


    bool isPrime(int num, int divisor) {
        if (divisor == 0) {
            return false;
        } else if (divisor == 1) {
            return true;
        } else if (num % divisor == 0) {
            return false;
        } else {
            return isPrime(num, divisor - 1);
        }
    }


    binarytree::size_type binarytree::numPrimes() {
        binarytree::size_type numberOfPrimes = 0;

        return numPrimes_aux(rootptr, numberOfPrimes);
    }


    binarytree::size_type numPrimes_aux(binarytree::node *rootptr, binarytree::size_type num) {
        if (rootptr == nullptr) {
            return num;
        } else if (isPrime(rootptr->data, rootptr->data - 1)) {
            num++;
        }

        if (rootptr->left == nullptr) {
            numPrimes_aux(rootptr->right, num);
        } else if (rootptr->right == nullptr) {
            numPrimes_aux(rootptr->left, num);
        }
    }
}






/*
OUTPUT:

enter number to insert (negative to quit): 1
enter number to insert (negative to quit): 3
enter number to insert (negative to quit): 4
enter number to insert (negative to quit): 5
enter number to insert (negative to quit): 7
enter number to insert (negative to quit): 23
enter number to insert (negative to quit): 9
enter number to insert (negative to quit): -1
1 3 4 5 7 9 23
Total items: 7

Total Primes: 4

enter number to find (negative to quit): 4
found. The data is 4
enter number to find (negative to quit): 23
found. The data is 23
enter number to find (negative to quit): -1
enter number to delete (negative to quit): 5
found. The list is now 1 3 4 7 9 23
enter number to delete (negative to quit): 4
found. The list is now 1 3 7 9 23
enter number to delete (negative to quit): -1

Process finished with exit code 0

*/