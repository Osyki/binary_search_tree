/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Customers.h
 * Author: hloi
 *
 * Created on November 24, 2018, 9:05 PM
 */

#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include "Binary_Search_Tree.h"
#include "Customer.h"
#include <iostream>

using std::cout;
using std::endl;

template<typename Item_Type>
class Customers : public Binary_Search_Tree<Item_Type> {
public:

    Customers() : Binary_Search_Tree<Item_Type>() {
    }

    Customers(const Customers &orig) {}

    virtual ~Customers() {}

    // count-big-limits: BST Number -> Natural
    // consumes a binary search tree and a credit limit amount, produces the number of customers
    // who have a credit limit higher than the given amount
    int count_big_limits(double limit);

    bool any_over_limit();

    // increase-limit: BST Natural Number -> BST
    // consumes a BST, a credit card number, and an amount of money. Function finds that
    // card number in the BST and changes that customer's credit limit, adding the amount of money
    // given to the limit. Function returns BST identical except for limit change
    Item_Type *increase_limit(string card_number, double limit_add);

    const Item_Type *find(const string &target) const;

private:
    // count-big-limits: BST Number -> Natural
    // consumes a binary search tree and a credit limit amount, produces the number of customers
    // who have a credit limit higher than the given amount
    int count_big_limits(const Binary_Tree<Item_Type> &the_tree, double limit);

    // check-limit: Number Number -> Natural
    // takes in a customer's credit limit and a given credit limit, returns 1 if the customers's
    // credit limit is higher than the given limit, 0 otherwise.
    int check_limit(Customer data, double limit);

    // any-over-limit?: BST -> Boolean
    // consumes a binary search tree and produces true if any customer in that tree has exceeded
    // their credit limit with their total purchases (charges)
    bool any_over_limit(const Binary_Tree<Item_Type> &the_tree);

    // sum-charges: ListOfCharge -> Number
    // consumes a ListOfCharge, produces the sum cost of those charges as a Number
    double sum_charges(list<Charge>::iterator begin,
                       list<Charge>::iterator end);


};

template<typename Item_Type>
int Customers<Item_Type>::count_big_limits(double limit) {
    if (this->is_null()) {
        return 0;
    }
    return check_limit(this->get_data(),limit) + count_big_limits(this->get_left_subtree(),limit) + count_big_limits(this->get_right_subtree(), limit);
}

template<typename Item_Type>
int Customers<Item_Type>::count_big_limits(const Binary_Tree<Item_Type> &the_tree, double limit) {
    if (the_tree.is_null()) {
        return 0;
    }
    return check_limit(the_tree.get_data(),limit) + count_big_limits(the_tree.get_left_subtree(),limit) +
            count_big_limits(the_tree.get_right_subtree(),limit);
}

template<typename Item_Type>
int Customers<Item_Type>::check_limit(Customer data, double limit) {
    //int sum = 0;
    return data.GetLimit() >= limit ? 1 : 0;
}

template<typename Item_Type>
bool Customers<Item_Type>::any_over_limit() {
    if (this->is_null()) {
        return false;
    }

    list<Charge> charges = this->get_data().GetCharges();
    list<Charge>::iterator begin = charges.begin();
    list<Charge>::iterator end = charges.end();
    if (sum_charges(begin, end) > this->get_data().GetLimit()) {
        return true;
    }

    return any_over_limit(this->get_left_subtree()) || any_over_limit(this->get_right_subtree());
}

template<typename Item_Type>
bool Customers<Item_Type>::any_over_limit(const Binary_Tree<Item_Type> &the_tree) {
    if (the_tree.is_null()) {
        return false;
    }

    list<Charge> charges = the_tree.get_data().GetCharges();
    list<Charge>::iterator begin = charges.begin();
    list<Charge>::iterator end = charges.end();

    if (sum_charges(begin, end) > the_tree.get_data().GetLimit()) {
        return true;
    }

    return any_over_limit(the_tree.get_left_subtree()) || any_over_limit(the_tree.get_right_subtree());
}

template<typename Item_Type>
double Customers<Item_Type>::sum_charges(list<Charge>::iterator begin, list<Charge>::iterator end) {
    double sum = 0.0;
    while (begin != end) {
        sum += begin->GetAmount();
        begin++;
    }
    return sum;
}

template<typename Item_Type>
Item_Type *Customers<Item_Type>::increase_limit(string card_number, double limit_add) {
    if (this->is_null()) {
        return NULL;
    }
    if (this->get_data().GetCard_number() == card_number) {
        this->get_data().SetLimit(this->get_data().GetLimit() + limit_add);
        return this->get_data();
    }
    return nullptr;
}

template<typename Item_Type>
const Item_Type *Customers<Item_Type>::find(const string &target) const {
    return nullptr;
}


#endif /* CUSTOMERS_H */

