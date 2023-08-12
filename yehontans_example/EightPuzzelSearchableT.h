#pragma once
#include "Searchable.h"
#include "EightPuzzel.h"

class EightPuzzelSearchableT : public Searchable<string>
{
public:
	EightPuzzelSearchableT(EightPuzzel& puzzel) : m_puzzel(&puzzel) {}

public:
	//ADD implementation for those methodes
	virtual State<string>* getStartState()
	{
		string s = m_puzzel->getStart();
		State<string>* s1 = new State<string>(s);
		return s1;
	}

	virtual State<string>* getGoalState()
	{
		string s = m_puzzel->getEnd();
		State<string>* s1 = new State<string>(s);
		return s1;
	}

	virtual std::vector<State<string>*>* getAllPossibleStates(State<string>& s) 
	{
		std::vector<string> moves = m_puzzel->getPossibleMoves(s.getState());
		std::vector<State<string>*>* smoves = new std::vector<State<string>*>();
		for(auto it = moves.begin(); it != moves.end(); ++it)
		{
			smoves->push_back(new State<string>(*it));
		}

		return smoves;

	};
private:
	EightPuzzel* m_puzzel;
};

