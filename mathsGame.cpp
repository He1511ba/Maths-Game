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
	stQuestion QuestionList[100];
	int numOfQuestion;
	int NumberOfCorrectAnswer = 0;
	int NumberOfWrondAnswer = 0;
	emLevel typeOfLevel;
	emOperation typeOfOperation;
	bool IsPass;
};

int simpleCalculator(int num1, int num2, emOperation oprType)
{
	switch (oprType)
	{
	case emOperation::sum:
		return num1 + num2;
		break;
	case emOperation::sub:
		return num1 - num2;
		break;
	case emOperation::mult:
		return num1 * num2;
		break;
	case emOperation::divid:
		return num1 / num2;
		break;
	}
}

stQuestion GenerateQuestion(emLevel level, emOperation oprType)
{
	stQuestion Question;

	if (level == emLevel::mix)
		level = (emLevel)RandomNumbers(1, 3);
	if (oprType == emOperation::mixOp)
		oprType = (emOperation)RandomNumbers(1, 4);

	Question.oprType = oprType;
	Question.QuestionLevel = level;

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

string printTextOfLevel(emLevel level)
{
	string arr[4] = {"Easy", "Med", "Hard", "Mix"};
	return arr[level - 1];
}

string printTextOfOprType(emOperation opr)
{
	string arr[5] = {"Add", "Sub", "Mul", "Div", "Mix"};
	return arr[opr - 1];
}

char printOprSymobl(emOperation oprType)
{
	switch (oprType)
	{
	case emOperation::sum:
		return '+';
		break;
	case emOperation::sub:
		return '-';
		break;
	case emOperation::mult:
		return '*';
		break;
	case emOperation::divid:
		return '/';
		break;
	}
}

int colorScreen(bool IsCorrect)
{
	if (IsCorrect)
		return system("color 2f");
	else
		return system("color 4f");
}

void GenerateQizeQuestion(stQize Qize)
{
	for (int QuestionNum = 1; QuestionNum <= Qize.numOfQuestion; QuestionNum++)
	{
		Qize.QuestionList[QuestionNum] = GenerateQuestion(Qize.typeOfLevel, Qize.typeOfOperation);
	}
}

void printQuestion(int QustionNum, stQize qize)
{
	cout << " Question [" << QustionNum + 1 << "/" << qize.numOfQuestion << "]: \n ";
	cout << "\t" << qize.QuestionList[QustionNum].firstNum << endl;
	cout << printOprSymobl(qize.typeOfOperation) << endl;
	cout << "\t" << qize.QuestionList[QustionNum].secNum << endl;
	cout << " _______ \n";
}

int ReadPlayerAnswer()
{
	int answer;
	cin >> answer;
	return answer;
}

void CheckPlayerAnswer(stQize Qize, int QuestionNum)
{
	if (Qize.QuestionList[QuestionNum].correctAnswer == Qize.QuestionList[QuestionNum].playerAnswer)
	{
		cout << "Right Answer \n";
		Qize.NumberOfCorrectAnswer++;
		Qize.QuestionList[QuestionNum].checkAnswer = true;
	}
	else
	{
		cout << "Wrong Answer \n";
		cout << "The Correct Answer is " << Qize.QuestionList[QuestionNum].correctAnswer<<endl;
		Qize.NumberOfWrondAnswer++;
		Qize.QuestionList[QuestionNum].checkAnswer = false;
	}

	Qize.IsPass = (Qize.NumberOfCorrectAnswer >= Qize.NumberOfWrondAnswer);
}

string PrintFinalResult(bool IsPass)
{
	if (IsPass)
		return "Pass";
	else
		return "Fail";
}

void ResetScreen()
{
	system("cls");
	system("color 0f");
}

void PlayMathsGame()
{
	stQize Qize;
	Qize.numOfQuestion = ReadHowManyQuestion();
	Qize.typeOfLevel = ReadLevel();
	Qize.typeOfOperation = ReadOperation();

	GenerateQizeQuestion(Qize);
}

void startGame()
{
	char playAgian;
	do
	{
		ResetScreen();
		PlayMathsGame();
		cout << endl
			 << " Do you want to play again? Y/N? ";
		cin >> playAgian;
	} while (playAgian == 'Y' || playAgian == 'y');
}

int main()
{
	startGame();
}