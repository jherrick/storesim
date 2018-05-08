/*
* Name: Joel Herrick
* Date: 3/12/18
* Description: program emulates online store 
*			   store class 
*/

//preprocess directives
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <iostream>
#include "storeSimStore.hpp"

//namespaces
using std::vector;
using std::string;

//add reference to product to inventory vector
void Store::addProduct(Product* p)
{
	inventory.push_back(p);
}

//add reference to member to members vector
void Store::addMember(Customer* c)
{
	members.push_back(c);
}

//returns pointer to product if in inventory, else returns null
Product* Store::getProductFromID(std::string s)
{
	for(int i=0; i<inventory.size(); i++)
	{
		if(inventory[i]->getIdCode() == s)
			return inventory[i];
	}

	return NULL;
}

//returns pointer to customer if in member list, else returns null
Customer* Store::getMemberFromID(std::string s)
{
	for(int i=0; i<members.size(); i++)
	{
		if(members[i]->getAccountID() == s)
			return members[i];
	}

	return NULL;
}

//searches inventory title & description for product; case insensitive first letter
//returns sorted vector of results
std::vector<std::string> Store::productSearch(std::string str)
{
	//create vector to store results
	std::vector<std::string> vect;
	//create temp str to perform case insensitive searches
	string str2 = str;
	string str3 = str;

	//make upper/lowercase of first char
	str2[0] = toupper(str2[0]);
	str3[0] = tolower(str3[0]);

	//if title/descript contains upper or lower str add it to results
	for(int i=0; i<inventory.size(); i++)
	{
		if( inventory[i]->getTitle().find(str2) != std::string::npos || 
		    inventory[i]->getDescription().find(str2) != std::string::npos ||
		    inventory[i]->getTitle().find(str3) != std::string::npos ||
		    inventory[i]->getDescription().find(str3) != std::string::npos)
		{
			vect.push_back(inventory[i]->getIdCode());
		}
	}

	//sort and return the vector of results
	std::sort(vect.begin(), vect.end());
	return vect;
	
}

//add product to member cart
std::string Store::addProductToMemberCart(std::string pID, std::string mID)
{
	bool prod = false; 
	bool memb = false;
	bool avail = false;
	Product *tempProd; 
	Customer *tempMemb;

	//check for product
	for(int i=0; i<inventory.size(); i++)
	{
		if(inventory[i]->getIdCode() == pID)
		{
			tempProd = inventory[i];
			prod = true;
		}
	}		

	//no product found
	if(!prod)
		return "product ID not found";

	//check for member
	for(int i=0; i<members.size(); i++)
	{
		if(members[i]->getAccountID() == mID)
		{
			tempMemb = members[i];
			memb = true;
		}
	}

	//no member found
	if(!memb)
		return "member ID not found";

	//out of stock
	if(tempProd->getQuantityAvailable()<1)
		return "product out of stock";

	//otherwise add to cart and return success message
	tempMemb->addProductToCart(pID);
	return "product added to cart";

}	

//check out member
double Store::checkOutMember(std::string mID)
{
	bool memb = false;
	Customer *tempMemb;
	double total = 0;
	double shipping;

	//check for member
	for(int i=0; i<members.size(); i++)
	{
		if(members[i]->getAccountID() == mID)
		{
			tempMemb = members[i];
			memb = true;
		}
	}

	//member not found
	if(!memb)
		return -1;

	//for each item in the cart
	for(int i=0; i<tempMemb->getCart().size(); i++)
	{

		//check to see that it's in inventory
		for(int j=0; j<inventory.size(); j++)
		{
			if(inventory[j]->getIdCode() == tempMemb->getCart()[i])
			{
				//check that it's available to purchase
				if(inventory[j]->getQuantityAvailable()>0)
				{
					//purchase it by adding price to total and decrementing quantity available
					total += inventory[j]->getPrice();
					inventory[j]->decreaseQuantity();
				}
			}
		}	
	}

	//if premium member, don't charge shipping and empty cart and return total
	if(tempMemb->isPremiumMember())
	{
		tempMemb->emptyCart();
		return total;
	}

	//empty the cart
	tempMemb->emptyCart();

	//avoiding weird corner-case bug
	if(total==0)
		return total;

	//return total + shipping
	shipping = total*.07;
	return total + shipping;
}