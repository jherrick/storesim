/*
* Name: Joel Herrick
* Date: 3/12/18
* Description: program emulates online store 
*			   product class 
*/

//preprocess directives
#include <string>
#include "storeSimProd.hpp"

//constructor
Product::Product(std::string id, std::string t, std::string d, double p, int qa)
{
	idCode = id;
	title = t;
	description = d;
	price = p;
	quantityAvailable = qa;
}

//returns idcode
std::string Product::getIdCode()
{
	return idCode;
}

//returns title
std::string Product::getTitle()
{
	return title;
}

//returns description of item
std::string Product::getDescription()
{
	return description;
}

//returns price
double Product::getPrice()
{
	return price;
}

//returns quant available
int Product::getQuantityAvailable()
{
	return quantityAvailable;
}

//decreases quant available
void Product::decreaseQuantity()
{
	quantityAvailable -= 1;
}