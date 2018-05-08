#include "storeSimStore.hpp"
#include <iostream>

using namespace std;

int main()
{
	vector<string> vect, vect2, vect3, vect5;

	
	for(int i =0; i<vect.size(); i++)
		cout << vect[i] << endl;


	Product myProduct("aaa", "wood", "low maintenance pet", 50, 3);
	Product myProduct2("aab", "track", "fully house-trained", 250, 1);
	Product myProduct3("aac", "brock", "Wood", 25, 21);
	Product myProduct4("aad", "crock", "test", 2500, 11);


	cout << "aaa =" << myProduct.getIdCode() << endl;
	cout << "pet rock =" << myProduct.getTitle() << endl;
	cout << "low maint... =" << myProduct.getDescription() << endl;
	cout << "50 =" << myProduct.getPrice() << endl;
	cout << "3 =" << myProduct.getQuantityAvailable() << endl;
	myProduct.decreaseQuantity();
	cout << "2 =" << myProduct.getQuantityAvailable() << endl;

	Customer myCustomer("Jenny", "8675309", true);
	Customer myCustomer2("Bobby", "90210", false);

	cout << "8675309 =" << myCustomer.getAccountID() << endl;
	cout << "1 =" << myCustomer.isPremiumMember() << endl;

	myCustomer.addProductToCart("12345");
	cout << "12345 = ";
	vect = myCustomer.getCart();
	for(int i =0; i<vect.size(); i++)
		cout << vect[i] << endl;

	myCustomer.emptyCart();

	cout << "expects nothing ";

	Product* test1;
	Customer* test2;

	Store myStore;
	myStore.addProduct(&myProduct4);

	myStore.addProduct(&myProduct2);
	myStore.addProduct(&myProduct);
	myStore.addProduct(&myProduct3);

	
	
	myStore.addMember(&myCustomer);
	myStore.addMember(&myCustomer2);

	vect5 = myStore.productSearch("wood");

	for(int i =0; i<vect5.size(); i++)
		cout << i << " " << vect5[i] << endl;

	
	cout << myStore.addProductToMemberCart("aaa", "8675309") << endl;
	cout << myStore.addProductToMemberCart("aaa", "8675309") << endl;
	cout << myStore.addProductToMemberCart("aaa", "8675309") << endl;
	cout << myStore.addProductToMemberCart("aab", "8675309") << endl;
	cout << myStore.addProductToMemberCart("aaa", "90210") << endl;

	cout << "cust 2 " << endl;

	vect3 = myCustomer2.getCart();
	for(int i =0; i<vect3.size(); i++)
		cout << vect3[i] << endl;	

	cout << "cust 1 " << endl;

	vect2 = myCustomer.getCart();
	for(int i =0; i<vect2.size(); i++)
		cout << vect2[i] << endl;	
	cout << "cust 2 total " << myStore.checkOutMember("90210") << endl;

	cout << "cust 1 total " << myStore.checkOutMember("8675309") << endl;
	
	return 0;
}