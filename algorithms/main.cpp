#include <iostream>

#include "insertion_sort.h"
#include "nearest_neighbor.h"
#include "optimal_scheduling.h"

int main(int argc, const char * argv[]) {
	cout << "insertion_sort:" << endl;
	insertion_sort::run();
	
	cout << endl << "nearest_neighbor:" << endl;
	nearest_neighbor::run();
	
	cout << endl << "optimal_scheduling:" << endl;
	optimal_scheduling::run();
	
	return 0;
}
