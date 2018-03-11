#include <iostream>

namespace hardendavebintree {
    class binarytree {
    public:
        typedef std::size_t size_type;

        binarytree();

        void print();

        void insert(int num);

        int find(int num, bool &found);

        void del(int num, bool &found);

        size_type size();

        size_type numPrimes();

    private:
        struct node {
            int data;
            node *left;
            node *right;
        };
        node *rootptr;

        friend void remove_max(node *&rootptr, int &max);

        friend void del_aux(node *&rootptr, int num, bool &found);

        friend int find_aux(const node *rootptr, int num, bool &found);

        friend void insert_aux(node *&rootptr, int num);

        friend void print_aux(node *rootptr);

        friend size_type numPrimes_aux(node *rootptr, size_type num);
    };
}