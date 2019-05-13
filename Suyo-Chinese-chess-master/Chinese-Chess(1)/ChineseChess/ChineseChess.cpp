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

	GUI.renewChess();
	GUI.showOutput();

	while (true)
	{
		vector<int>currentPosition = {};
		vector<int>nextPosition = {};
		vector<vector<int>>legal = {};
		const vector<int>selectError = { -1,-1 };
		reSelect:
		currentPosition = mainChess.selectedChess();
		if (currentPosition == selectError)
			goto reSelect;
		legal = mainChess.whereCanGO(currentPosition);
		if (legal.size() == 0)
			goto reSelect;
		// 提示可下的位置
		GUI.showHint(legal);
		// 移動棋子、改棋盤，畫出棋盤
		nextPosition = mainChess.moveChess(currentPosition);
		if (nextPosition == selectError)
		{
			GUI.renewChess();
			GUI.showOutput();
			goto reSelect;
		}
			
		mainChess.nextPlayer();


		GUI.renewChess();
		GUI.showOutput();
	}
	return 0;
}

