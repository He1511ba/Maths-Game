#include <iostream>
#include <cstdlib>
using namespace std;

enum emLevel
{
	esay = 1,
	med = 2,
	hard = 3,
	mix = 4
};

enum emOperation
{
	sum = 1,
	sub = 2,
	mult = 3,
	divid = 4,
	mixOp = 5
};
enum emWinner
{
	player = 1,
	computer = 2
};

int ReadHowManyQuestions()
{
	int numOfQuestions;
	do
	{
		cout << "How Many Questions do you want to answer ? ";
		cin >> numOfQuestions;
		cout << endl;
	} while (numOfQuestions < 1 || numOfQuestions > 10);

	return numOfQuestions;
}

int ReadLevel()
{
	int level;
	do
	{
		cout << "Choose Questions Level Easy:[1] , Medain:[2] , Hard:[3] , Mix:[4] ? ";
		cin >> level;
		cout << endl;
	} while (level < 1 || level > 4);

	return (emLevel)level;
}

int ReadOperation()
{
	int Opr;
	do
	{
		cout << "Enter Operation Type Sum:[1] , Sub:[2] , Mult:[3] , Div:[4] , MixOpr:[5] ? ";
		cin >> Opr;
		cout << endl;
	} while (Opr < 1 || Opr > 5);

	return (emOperation)Opr;
}

int RandomNumbers(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

struct stRoundInfo
{
	short numOfRound;
	int firstNum;
	int secNum;
	int result;
};

void choicLevel(emLevel level)
{
	stRoundInfo RoundInfo;
	switch (level)
	{
	case emLevel::esay:
		RoundInfo.firstNum = RandomNumbers(1, 10);
		RoundInfo.secNum = RandomNumbers(1, 10);
		break;
	case emLevel::med:
		RoundInfo.firstNum = RandomNumbers(21, 50);
		RoundInfo.secNum = RandomNumbers(21, 50);
		break;
	case emLevel::hard:
		RoundInfo.firstNum = RandomNumbers(51, 100);
		RoundInfo.secNum = RandomNumbers(51, 100);
		break;
	}
}
void printRoundResult()
{
	stRoundInfo RoundInfo;
	cout << "_______________________________ \n";
	cout << "Question [" << endl;
	cout << RoundInfo.firstNum << endl <<RoundInfo.secNum;
}
void ResetScreen()
{
	system("cls");
	system("color 0f");
}

void startGame()
{
	char playAgian;
	do
	{
		ResetScreen();
		ReadHowManyQuestions();
		ReadLevel();
		ReadOperation();
		printRoundResult();
		cout << "\tDo you want to play again? Y/N? ";
		cin >> playAgian;
	} while (playAgian == 'Y' || playAgian == 'y');
}

int main()
{
	startGame();
}