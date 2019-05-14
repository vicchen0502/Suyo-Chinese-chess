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
	//Chess mainChess("check.txt"); //和局情況
	Draw GUI;

	GUI.renewChess();
	GUI.showOutput();
	mainChess.renewHistory();
	do
	{
		vector<int>currentPosition = {};
		vector<int>nextPosition = {};
		vector<vector<int>>legal = {};
		vector<vector<int>>nextLegal = {};
		const vector<int>selectError = { -1,-1 };
		const vector<int>regret = { -2,-2 };
		//const vector<int>regretUndo = { -3,-3 };
		reSelect:
		currentPosition = mainChess.selectedChess();
		if (currentPosition == selectError)
			goto reSelect;
		else if (currentPosition == regret)
		{
			int change;
			GUI.showRegretMenu();
			change = GUI.selectRegret();
			// 不毀棋

			if (change == 1)
			{
				GUI.showOutput();
				goto reSelect;
			}
			// 毀棋
			else if (change == 0)
			{
				if (Chess::getStepNumber() >= 2)
				{
					mainChess.assignBoard();
					GUI.renewChess();
					GUI.showOutput();
					goto reSelect;
				}
				else if (Chess::getStepNumber() <= 1)
				{
					GUI.renewChess();
					GUI.showOutput();
					goto reSelect;
				}
			}
		}
		/*else if (currentPosition == regretUndo)
		{
			int change;
			GUI.showCancelRegretMenu();
			change = GUI.selectRegret();
			//不還原
			if (change == 1)
			{
				GUI.showOutput();
				goto reSelect;
			}
			// 還原
			else if (change == 0)
			{
				if (Chess::getStepNumber() >= 2)
				{
					mainChess.assignBoard();
					GUI.renewChess();
					GUI.showOutput();
					goto reSelect;
				}
				else if (Chess::getStepNumber() <= 1)
				{
					GUI.renewChess();
					GUI.showOutput();
					goto reSelect;
				}
			}
		}*/
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
		
		if (Chess::getEnd() >= 0)
		{
			GUI.renewChess();
			GUI.showOutput();
			return Chess::getEnd();
			break;
		}
		mainChess.nextPlayer();

		mainChess.renewHistory();
		GUI.renewChess();
		GUI.showOutput();
	} while (Chess::getEnd() == -1);
	return 0;
}

