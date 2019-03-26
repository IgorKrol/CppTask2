/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  ariel::Tree mytree;  
  mytree.insert(20);
  mytree.insert(24);
  mytree.insert(15);
  mytree.insert(17);
  mytree.insert(18);
  mytree.insert(16);
  mytree.insert(33);
  mytree.insert(44);

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())

  .CHECK_EQUAL (mytree.size(), 8)
  .CHECK_EQUAL (mytree.root(), 20)
  .CHECK_EQUAL (mytree.parent(15), 20)
  .CHECK_EQUAL (mytree.parent(17), 15)
  .CHECK_THROWS(mytree.insert(17))
  .CHECK_OK    (mytree.remove(24))  
  .CHECK_EQUAL (mytree.contains(24), false)
  .CHECK_EQUAL (mytree.contains(33), true)
  .CHECK_EQUAL (mytree.contains(44), true)
  .CHECK_EQUAL (mytree.contains(1), false)
  .CHECK_THROWS(mytree.remove(24))
  .CHECK_OK    (mytree.print())

  // .print()
  ;
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
