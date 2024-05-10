#include <iostream>
#include "node.hh"


int main()
{

    DLList<int> myList;

    // Test 1;
    // Test a push to the back of the dll

    std::cout << "\nTest 1" << std::endl;
    std::cout << "Adding the value '2' to the end of the list." << std::endl;
    myList.push_back( 2 );
    myList.display();
    std::cout << "Expected count 1. Actual count " << myList.size() << std::endl;
    std::cout << std::endl;

    // Test 2
    // Test a push to the front
    std::cout << "\nTest 2" << std::endl;
    std::cout << "Adding the value '3' to the front of the list." << std::endl;
    myList.push_front( 3 );
    myList.display();
    std::cout << "Expected count 2. Actual count " << myList.size() << std::endl;
    std::cout << std::endl;

    // Test 3
    // Test a push to the end again.
    std::cout << "\nTest 3" << std::endl;
    std::cout << "Adding the value '3' to the end of the list." << std::endl;
    myList.push_back( 4 );
    myList.display();
    std::cout << "Expected count 3. Actual count " << myList.size() << std::endl;
    std::cout << std::endl;


    //Test 4
    // Test several pushes to the back.
    std::cout << "\nTest 4" << std::endl;
    std::cout << "Adding the values 100, 101, 102, and 103 to the end of the list." << std::endl;

    myList.push_back(100);
    myList.push_back(101);
    myList.push_back(102);
    myList.push_back(103);
    myList.display();
    std::cout << "Expected count 7. Actual count " << myList.size() << std::endl;
    std::cout << std::endl;


    //Test 5
    // Test several pushes to the front.
    std::cout << "\nTest 5" << std::endl;
    std::cout << "Adding the values 104 and 105 to the front of the list." << std::endl;
    myList.push_front(104);
    myList.push_front(105);
    myList.display();
    std::cout << "Expected count 9. Actual count " << myList.size() << std::endl;
    std::cout << std::endl;
    
    //Test 6
    // Test an insert to the middle of the list.
    std::cout << "\nTest 6" << std::endl;
    std::cout << "Inserting the value 888 to the node after 100." << std::endl;
    myList.insert_after( 100, 888 );
    myList.display();
    std::cout << "Expected count 10. Actual count " << myList.size() << std::endl;
    std::cout << std::endl;

    // Test 7
    // Test an insert after the end of the list. 
    std::cout << "\nTest 7" << std::endl;
    std::cout << "Inserting the value 666 to the node after 103, which should be at the end of the list." << std::endl;
    myList.insert_after( 103, 666 );
    myList.display();
    std::cout << "Expected count 11. Actual count " << myList.size() << std::endl;
    std::cout << std::endl;

    
    // Test 8 
    // Test an insert after after head node.
    std::cout << "\nTest 8" << std::endl;
    std::cout << "Inserting the value 777 to the node after 105, which should be at the second node." << std::endl;
    myList.insert_after( 105, 777 );
    myList.display();
    std::cout << "Expected count 12. Actual count " << myList.size() << std::endl;
    std::cout << std::endl;


    // Test 9
    // Test: ensure the dll can be copied using a copy constructor.
    std::cout << "\nTest 9" << std::endl;
    std::cout << "Testing the copy constructor." << std::endl;
    DLList<int> newList( myList );

    std::cout << "Original list (myList) size : " << myList.size() << std::endl;
    std::cout << "Copied list (newList) size  : " << newList.size() << std::endl;
    std::cout << std::endl;

    // Test 10
    // Test a pop from the front.
    std::cout << "\nTest 10" << std::endl;
    std::cout << "Testing a pop from the front. This should return the value and remove the node." << std::endl;
    int tmp = myList.pop_front();
    std::cout << "Expected value = 105 : Actual value = " << tmp << ".\n";
    myList.display();
    std::cout << "Expected count 11. Actual count " << myList.size() << std::endl;
    std::cout << std::endl;


    // Test 11
    // Test a pop from the back
    std::cout << "\nTest 11" << std::endl;
    std::cout << "Testing a pop from the front. This should return the value and remove the node." << std::endl;
    tmp = myList.pop_back();
    std::cout << "Expected value = 666 : Actual value = " << tmp << ".\n";
    myList.display();
    std::cout << "Expected count 10. Actual count " << myList.size() << std::endl;
    std::cout << std::endl;


    // Test 12
    // Test the remove method
    std::cout << "\nTest 12" << std::endl;
    std::cout << "Testing a remove from the middle. This should remove the first node with the value 101 amd return 'true'." << std::endl;
    bool removed = myList.remove(101);
    std::string r = removed?"True":"False";
    myList.display();
    std::cout << "Node found? " <<  r << std::endl;
    std::cout << "Expected count 9. Actual count " << myList.size() << std::endl;
    std::cout << std::endl;

    // Test 13
    // Test removal for non-existent value.
    std::cout << "\nTest 13" << std::endl;
    std::cout << "Testing a remove for a non existant node. This should do nothing and return 'false'." << std::endl;
    removed = myList.remove(101);
    r = removed?"True":"False"; 
    myList.display();
    std::cout << "Node found? " <<  r << std::endl;
    std::cout << "Expected count 9. Actual count " << myList.size() << std::endl;
    std::cout << std::endl;

    // Test 15 
    // Test an insert after non existent node.
    std::cout << "\nTest 15" << std::endl;
    std::cout << "Inserting the value 444 to the node after 333, which should not exist." << std::endl;
    bool added = myList.insert_after( 333, 444 );
    r = added?"True":"False"; 
    myList.display();
    std::cout << "Node found? " <<  r << std::endl;
    std::cout << "Expected count 9. Actual count " << myList.size() << std::endl;
    std::cout << std::endl;

    // Test 16
    // Test clear and ability to display empty list.
    std::cout << "\nTest 16" << std::endl;
    std::cout << "Test clear and ability to display empty list." << std::endl;
    myList.clear();
    myList.display();
    std::cout << "Expected count 0. Actual count " << myList.size() << std::endl;
    std::cout << std::endl;

    // Test 17
    // Test removal for empty list.
    std::cout << "\nTest 17" << std::endl;
    std::cout << "Testing a remove for an empty list." << std::endl;
    removed = myList.remove(101);
    r = removed?"True":"False"; 
    myList.display();
    std::cout << "Node found? " <<  r << std::endl;
    std::cout << "Expected count 0. Actual count " << myList.size() << std::endl;
    std::cout << std::endl;

    
    // Test 18
    // Test pop_back in empty list.
    std::cout << "\nTest 18" << std::endl;
    std::cout << "Testing a pop_back for an empty list." << std::endl;
    myList.pop_back();
    myList.display();
    std::cout << "Expected count 0. Actual count " << myList.size() << std::endl;
    std::cout << std::endl;

    // Test 19
    // Test pop_front in empty list.
    std::cout << "\nTest 19" << std::endl;
    std::cout << "Testing a pop_front for an empty list." << std::endl;
    myList.pop_front();
    myList.display();
    std::cout << "Expected count 0. Actual count " << myList.size() << std::endl;
    std::cout << std::endl;

    // Test 20
    // Test insert_after into an empty list;
    std::cout << "\nTest 20" << std::endl;
    std::cout << "Testing a insert_after for an empty list." << std::endl;
    myList.insert_after( 101, 300 );
    myList.display();
    std::cout << "Expected count 0. Actual count " << myList.size() << std::endl;
    std::cout << std::endl;

    // Test 21
    // Test to push into existent empty list.
    std::cout << "\nTest 21" << std::endl;
    std::cout << "Testing a push_front into the list we just cleared." << std::endl;
    myList.push_front(999);
    myList.display();
    std::cout << "Expected count 1. Actual count " << myList.size() << std::endl;
    std::cout << std::endl;

    // Test 22
    // Ensure copied dll has all the members copied into it.
    std::cout << "\nTest 22" << std::endl;
    std::cout << "Ensure copied dll has all the members we copied into it earlier." << std::endl;
    std::cout << "Original list : " << std::endl; 
    myList.display();
    std::cout << "Copied list   : " << std::endl; 
    newList.display();


    std::cout << std::endl;
}