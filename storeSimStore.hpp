#ifndef STORE_HPP
#define STORE_HPP

#include <vector>
#include <string>
#include "storeSimCust.hpp"

class Store
{
private:
    std::vector<Product*> inventory;
    std::vector<Customer*> members;
public:
    void addProduct(Product* p);
    void addMember(Customer* c);
    Product* getProductFromID(std::string);
    Customer* getMemberFromID(std::string);
    std::vector<std::string>  productSearch(std::string str);
    std::string addProductToMemberCart(std::string pID, std::string mID);
    double checkOutMember(std::string mID);
};

#endif
