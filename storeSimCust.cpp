/*
* Name: Joel Herrick
* Date: 3/12/18
* Description: program emulates online store 
*			   customer class 
*/

//preprocessor directives
#include <vector>
#include "storeSimCust.hpp"

//constructor
Customer::Customer(std::string n, std::string a, bool pm)
{
	name = n;
	accountID = a;
	premiumMember = pm;
}

//returns account id
std::string Customer::getAccountID()
{
	return accountID;
}

//returns cart vector
std::vector<std::string> Customer::getCart()
{
	return cart;
}

//adds product to cart vector
void Customer::addProductToCart(std::string item)
{
	cart.push_back(item);
}

//returns bool of is premium member
bool Customer::isPremiumMember()
{
	return premiumMember;
}

//clears cart vector
void Customer::emptyCart()
{
	cart.clear();
}