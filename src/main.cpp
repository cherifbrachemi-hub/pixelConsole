#include<iostream>
#include<cmath>
#include"Header.h"



int main()
{
	
	Grid inventory(10, 5);
	IdManager mgr;
	inventory.print_grid();


	//inventory.can_place_at(0, 4, sword);

	Item sword(mgr.create_id(), "Sword", 2, 3);
	Item potion(mgr.create_id(), "Potion", 1, 1);

	inventory.place_item(1, 2, sword);


	inventory.print_grid();
	
	int a = mgr.create_id();  // devrait être 0
	int b = mgr.create_id();  // devrait être 1
	int c = mgr.create_id();  // devrait être 2
	mgr.remove_at_slot(b);    // libère l'ID 1
	int d = mgr.create_id();  // devrait réutiliser 1, pas créer 3

	
	return 0;
}
