#include <iostream>

#include "StudentList.h"

using namespace std;

int main() {
	StudentList list;

	list.add(new Student("Dima", "Okulich", "Iurivich", "POIT", 3, 13082021, 10, Faculty::FIT));
	list.add(new Student("Sasha0", "Rubasec", "Sasha", "POIT", 2, 12082021, 8, Faculty::FIT));
	list.add(new Student("Ilya", "Dmitruck", "Igor", "POIT", 1, 12082021, 9, Faculty::FIT));
	list.add(new Student("Sasha1", "Bogdan", "Vladimir", "POIT", 6, 12082021, 7, Faculty::FIT));

	list.print();

	cout << list.getSize() << endl << endl;

	list.findBySecName("Rubasec")->print();
	list.findByEnterDate(13082021)->print();
	list.findByGroup(6)->print();
	list.findByMiddleMark(9)->print();
}