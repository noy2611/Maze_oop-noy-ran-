#pragma once

#include <string>

class EightPuzzel
{
public:
	EightPuzzel() {};
	~EightPuzzel() {};

public:
	//All the methods for the game
	std::string getStart() { return m_startPos; }
	std::string getEnd() { return m_endPos; }
	std::vector<string> getPossibleMoves(string& state) 
	{ 
		std::vector<string>* vec = new vector<string>(); 
		return *vec; 
		//get possible moves...
	}
	

private:
	int m_board[3][3];
	std::string m_startPos;
	std::string m_endPos;
};
