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

int ReadHowManyQuestion()
{
	int numOfQuestion;
	do
	{
		cout << "How Many Question do you want to answer ? ";
		cin >> numOfQuestion;
		cout << endl;
	} while (numOfQuestion < 1 || numOfQuestion > 10);

	return numOfQuestion;
}

emLevel ReadLevel()
{
	int level;
	do
	{
		cout << "Choose Question Level Easy:[1] , Medain:[2] , Hard:[3] , Mix:[4] ? ";
		cin >> level;
		cout << endl;
	} while (level < 1 || level > 4);

	return (emLevel)level;
}

emOperation ReadOperation()
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

struct stQuestion
{
	short numOfQuestion;
	int firstNum;
	int secNum;
	int playerAnswer;
	bool checkAnswer;
	int correctAnswer;
	emLevel QuestionLevel;
	emOperation oprType;
};

struct stQize
{
	int numOfQuestion;
	int NumberOfCorrectAnswer = 0;
	int NumberOfWrondAnswer = 0;
	emLevel typeOfLevel;
	emOperation typeOfOperation;
	bool isPass;
};

int simpleCalculator(int num1, int num2, emOperation oprType)
{
	switch (oprType)
	{
	case emOperation::sum:
		return num1 + num2;
		break;
	case emOperation::sub:
		return num1 / num2;
		break;
	case emOperation::mult:
		return num1 * num2;
		break;
	case emOperation::divid:
		return num1 / num2;
		break;
	}
}

stQuestion choicLevel(emLevel level, emOperation oprType)
{
	stQuestion Question;

	if (level == emLevel::mix)
		level = (emLevel)RandomNumbers(1, 3);
	if (oprType == emOperation::mixOp)
		oprType = (emOperation)RandomNumbers(1, 4);

	switch (level)
	{
	case emLevel::esay:
		Question.firstNum = RandomNumbers(1, 10);
		Question.secNum = RandomNumbers(1, 10);
		Question.correctAnswer = simpleCalculator(Question.firstNum, Question.secNum, oprType);
		return Question;
		break;
	case emLevel::med:
		Question.firstNum = RandomNumbers(21, 50);
		Question.secNum = RandomNumbers(21, 50);
		Question.correctAnswer = simpleCalculator(Question.firstNum, Question.secNum, oprType);
		return Question;
		break;
	case emLevel::hard:
		Question.firstNum = RandomNumbers(51, 100);
		Question.correctAnswer = Question.secNum = RandomNumbers(51, 100);
		simpleCalculator(Question.firstNum, Question.secNum, oprType);
		return Question;
		break;
	}
}
void printRoundResult()
{
	stQuestion Question;
	cout << "_______________________________ \n";
	cout << "Question [" << endl;
	cout << Question.firstNum << endl
		 << Question.secNum;
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
		ReadHowManyQuestion();
		ReadLevel();
		ReadOperation();
		printRoundResult();
		cout << endl
			 << " Do you want to play again? Y/N? ";
		cin >> playAgian;
	} while (playAgian == 'Y' || playAgian == 'y');
}

int main()
{
	startGame();
}