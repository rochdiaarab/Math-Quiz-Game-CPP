#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

struct QuestionLevels
{
    bool easy = false;    
    bool mid = false;    
    bool hard = false;    
    bool mix = false;     
};

struct OperationTypes
{
    bool add = false;    
    bool div = false;     
    bool sub = false;     
    bool mul = false;    
};

struct Question
{
    int firstNumber;
    int secondNumber;
    int answer;         
};

struct DifficultyRange
{
    int minValue;
    int maxValue;
};

struct GameScore
{
    int correctAnswers;
    int wrongAnswers;
};

int RandomNumber(int from, int to)  
{
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}

void GenerateSubtractionQuestion(Question &question, const DifficultyRange &difficulty)  
{
    question.firstNumber  = RandomNumber(difficulty.minValue, difficulty.maxValue);
    question.secondNumber = RandomNumber(difficulty.minValue, difficulty.maxValue);
    question.answer       = question.firstNumber - question.secondNumber;
}

void GenerateAdditionQuestion(Question &question, const DifficultyRange &difficulty)  
{
    question.firstNumber  = RandomNumber(difficulty.minValue, difficulty.maxValue);
    question.secondNumber = RandomNumber(difficulty.minValue, difficulty.maxValue);
    question.answer       = question.firstNumber + question.secondNumber;
}

void GenerateMultiplicationQuestion(Question &question, const DifficultyRange &difficulty)  
{
    question.firstNumber  = RandomNumber(difficulty.minValue, difficulty.maxValue);
    question.secondNumber = RandomNumber(difficulty.minValue, difficulty.maxValue);
    question.answer       = question.firstNumber * question.secondNumber;
}

void GenerateDivisionQuestion(Question &question, const DifficultyRange &difficulty)  
{
    do
    {
        question.secondNumber = RandomNumber(difficulty.minValue, difficulty.maxValue);
    }
    while (question.secondNumber == 0);
    
    int answer = RandomNumber(1, 100);
    question.firstNumber = answer * question.secondNumber;
    question.answer = answer;
}

void SetEasyLevel(DifficultyRange &difficulty)
{
    difficulty.minValue = 1;
    difficulty.maxValue = 10;
}

void SetMediumLevel(DifficultyRange &difficulty)
{
    difficulty.minValue = 10;
    difficulty.maxValue = 30;
}

void SetHardLevel(DifficultyRange &difficulty)
{
    difficulty.minValue = 30;
    difficulty.maxValue = 100;
}

void SetMixedLevel(DifficultyRange &difficulty)
{
    difficulty.minValue = 1;
    difficulty.maxValue = 100;
}

void ChooseDifficulty(DifficultyRange &difficulty, QuestionLevels &levels)
{
    int levelChoice;  
    cout << "Choose difficulty: | Easy(1) | Mid(2) | Hard(3) | Mix(4): "; 
    cin >> levelChoice;

    if (levelChoice == 1)
    {
        SetEasyLevel(difficulty);
        levels.easy = true;  
    }
    else if (levelChoice == 2)
    {
        SetMediumLevel(difficulty);
        levels.mid = true;  
    }
    else if (levelChoice == 3)
    {
        SetHardLevel(difficulty);
        levels.hard = true;  
    }
    else
    {
        SetMixedLevel(difficulty);
        levels.mix = true;   
    }
}

void CheckAnswer(Question &question, GameScore &score)
{
    int userAnswer;
    cin >> userAnswer;

    if (userAnswer == question.answer)
    {
        cout << "You are right!" << endl;
        score.correctAnswers++;
    }
    else
    {
        cout << "Wrong!" << endl;
        cout << "The right answer is " << question.answer << endl;
        score.wrongAnswers++;
    }
}
void ChooseOperation(
    Question &question,
    GameScore &score,
    const DifficultyRange &difficulty,  
    OperationTypes &operationType)
{
    int operationChoice;  
    cout << "Choose operation: | Add(1) | Sub(2) | Mul(3) | Div(4): ";  
    cin >> operationChoice;

    if (operationChoice == 1)
    {
        GenerateAdditionQuestion(question, difficulty);
        cout << question.firstNumber << " + " << question.secondNumber << " equals what? ";
        CheckAnswer(question, score);
        operationType.add = true; 
    }
    else if (operationChoice == 2)
    {
        GenerateSubtractionQuestion(question, difficulty);
        cout << question.firstNumber << " - " << question.secondNumber << " equals what? ";
        CheckAnswer(question, score);
        operationType.sub = true;  
    }
    else if (operationChoice == 3)
    {
        GenerateMultiplicationQuestion(question, difficulty);
        cout << question.firstNumber << " * " << question.secondNumber << " equals what? ";
        CheckAnswer(question, score);
        operationType.mul = true;  
    }
    else if (operationChoice == 4)
    {
        GenerateDivisionQuestion(question, difficulty);
        cout << question.firstNumber << " / " << question.secondNumber << " equals what? ";
        CheckAnswer(question, score);
        operationType.div = true;  
    }
}
void PlayQuestion(
    GameScore &score,
    QuestionLevels &questionLevel,
    OperationTypes &operations)
{
    Question question = {};
    DifficultyRange difficulty = {};

    ChooseDifficulty(difficulty, questionLevel);
    ChooseOperation(question, score, difficulty, operations);
}

int PlayGame(
    GameScore &score,
    QuestionLevels &questionLevel,
    OperationTypes &operation)
{
    int questionCount;  
    cout << "How many questions do you want? ";
    cin >> questionCount;

    for (int i = 1; i <= questionCount; i++)
    {
        cout << "Question [" << i << "/" << questionCount << "]" << endl;
        PlayQuestion(score, questionLevel, operation);
    }

    return questionCount;
}

void PrintDifficulty(const QuestionLevels &level)  
{
    if (level.easy)
        cout << "Difficulty level: Easy" << endl;
    else if (level.hard)
        cout << "Difficulty level: Hard" << endl;
    else if (level.mid)
        cout << "Difficulty level: Medium" << endl;
    else
        cout << "Difficulty level: Mixed" << endl;
}

void PrintOperation(const OperationTypes &operation)  
{
    if (operation.add)
        cout << "Operation type: Addition" << endl; 
    else if (operation.mul)
        cout << "Operation type: Multiplication" << endl; 
    else if (operation.div)
        cout << "Operation type: Division" << endl;  
    else
        cout << "Operation type: Subtraction" << endl;  
}

void PrintResults()
{
    GameScore score = {};
    QuestionLevels questionLevel = {};
    OperationTypes operation = {};

    int questionCount = PlayGame(score, questionLevel, operation);

    cout << "________________________________________" << endl;
    cout << "Questions asked: " << questionCount << endl;
    PrintDifficulty(questionLevel);
    PrintOperation(operation);
    cout << "Correct answers: " << score.correctAnswers << endl;
    cout << "Wrong answers: " << score.wrongAnswers << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int playAgain;
    do
    {
        PrintResults();
        cout << "Play again? (1 for Yes, 0 for No): "; 
        cin >> playAgain;
    }
    while (playAgain == 1);

    return 0;
}
 