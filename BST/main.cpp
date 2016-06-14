#include <iostream>
#include <cstdlib>
#include "BST.h"

using namespace std;


int main()
{
	BinarySearchTree<int> b;
	int ch;
	int tmp, tmp1;
	while (1)
	{
		cout << endl << endl;
		cout << " Binary Search Tree Operations " << endl;
		cout << " ----------------------------- " << endl;
		cout << " 1. Insertion/Creation " << endl;
		cout << " 2. In-Order Traversal " << endl;
		cout << " 3. Pre-Order Traversal " << endl;
		cout << " 4. Post-Order Traversal " << endl;
		cout << " 5. Removal " << endl;
		cout << " 6. Search " << endl;
		cout << " 7. Min " << endl;
		cout << " 8. Max " << endl;
		cout << " 9. Count Nodes " << endl;
		cout << " 10. Exit " << endl;
		cout << " Enter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1: cout << " Enter data to be inserted : ";
			cin.ignore(1);
			cin >> tmp;
			b.insert(tmp);
			break;
		case 2: cout << endl;
			cout << " In-Order Traversal " << endl;
			cout << " -------------------" << endl;
			b.print_inorder();
			break;
		case 3: cout << endl;
			cout << " Pre-Order Traversal " << endl;
			cout << " -------------------" << endl;
			b.print_preorder();
			break;
		case 4: cout << endl;
			cout << " Post-Order Traversal " << endl;
			cout << " --------------------" << endl;
			b.print_postorder();
			break;
		case 5: cout << " Enter data to be deleted : ";
			cin.clear();
			cin.ignore(1);
			cin >> tmp1;
			b.remove(tmp1);
			break;
		case 6: cout << " Enter data to be searched : ";
			cin.ignore(1);
			cin >> tmp;
			b.search(tmp);
			break;

		case 7: cout << " Min is:" << b.min() << endl;
			break;
		case 8: cout << "  Max is :" << b.max() << endl;
			break;
		case 9: cout << " Count Nodes :" << b.count_nodes() << endl;
			break;
 
		//case 7: system("pause");
			//return 0;
			//break;
		case 10: 
		return 0;
		break;
		}
	}
}