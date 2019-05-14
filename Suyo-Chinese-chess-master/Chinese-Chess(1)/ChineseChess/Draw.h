#ifndef DRAW_H
#define DRAW_H

//#include"pch.h"
//#include"chess.h"

using namespace std;
class Draw
{
private:
	vector<int>carList;
	vector<string>chessPart;
	vector<string>leftPart;
	vector<string>rightPart;
	vector<string>regretMenu;
public:
	friend class Chess;
	void showOutput();			// show ��� + �Ԫp + �ѽL + �����¬���U�� + �ާ@���ܡC
	void showHint(vector<vector<int>>legalList);
	void renewChess();
	void showRegretMenu();


	int selectRegret();

	void renewRight();
	void renewLeft();
	void renewChessPart();
	void renewCarOrder();
};

#endif // DRAW_H

