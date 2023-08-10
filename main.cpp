#include <iostream>
#include "State.h"
#include "Searcher.h"
#include "BFS.h"
#include "EightPuzzelSearchableT.h"


using namespace std;


int main()
{
	/*State a("A");
	State b("B");
	State goal("B");

	if(b == goal)
		cout << "Target State found!" << endl;*/


	EightPuzzel ep;
	EightPuzzelSearchableT ep_searchable(ep);

	
	/*Create Search algorithm*/
	Searcher<string>* search_BFS = new BFS<string>();
	Solution<string> solution = search_BFS->search(ep_searchable);

	
	ep_searchable.getGoalState();
	ep_searchable.getStartState();
	ep_searchable.getAllPossibleStates(*ep_searchable.getStartState());



	cin.get();
	return 0;
}