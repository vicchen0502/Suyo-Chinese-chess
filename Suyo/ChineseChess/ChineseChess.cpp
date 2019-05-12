// ChineseChess.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include "pch.h"//內建標頭檔都在這
#include "chess.h"
#include "Draw.h"
int main()
{
	// 讀取檔案
	// 畫初始化棋盤
	// 讀取誰先下
	Chess mainChess("Initial.txt");
	Draw GUI;
	GUI.renewChessPart();
	GUI.renewLeft();
	GUI.renewRight();
	GUI.showOutput();

	while (true)
	{
		vector<int>currentPosition = {};
		vector<vector<int>>legalList;

		currentPosition = mainChess.selectedChess();
		legalList = mainChess.whereCanGO(currentPosition);
		GUI.showHint(legalList);

	}

	return 0;
}
