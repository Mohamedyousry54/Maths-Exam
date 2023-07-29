#include <iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;
/*
<summary>
math quiz for add ,sub ,mult and div skills
 with a collection of question for these skills the user have the ability to choose the number of questions , 
type of questions and Level of questions 
 and the program return 
 a card with the whole information about the exam and the results
take a look in the code
</summary>
*/
enum enLevel{easy=1,meduim=2,hard=3,mix=4};
enum enType { Add = 1, Sub = 2, Mult = 3, divs = 4,mixs=5 };
struct strandom {int first;int second;int result;};

//functions declarations
//functions for numbers and printing

void read_Number(int&);

void printexp(enType, strandom);

int Number_of_question();

int random_Number(int, int);
//result functions 

int results(enType, strandom);

bool check_result(int, int);
//levels fucntions

int Enter_level();

bool easy_level(enType);

bool medium_level(enType);

bool hard_level(enType);

enLevel mix_level();

void What_level(enLevel&, int);

void print_Levels(int);
//type functions 

int what_Type();

void print_Types(int);

enType mix_type();

void Types(enType&, int);
// quiz functions and the final results card

void final_card(int , int, int, int );

void math_Quiz();

void repeat_quiz();

void start_Quiz();

//the main function
int main(){
	srand((unsigned)time(NULL));
	start_Quiz();
	return 0;
}
// functions declarations
void read_Number(int& i) {

	cin >> i;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(200, '\n');
		cout << "enter avalid number ";
		cin >> i;
	}
}

void printexp(enType type, strandom rand)
{
	switch (type)
	{
	case enType::Add:
		cout << rand.first << " \n" << rand.second << "+\n__________\n";
		break;
	case enType::Sub:
		cout << rand.first << " \n" << rand.second << "-\n__________\n";
		break;
	case enType::Mult:
		cout << rand.first << " \n" << rand.second << "*\n__________\n";
		break;
	case enType::divs:
		cout << rand.first << " \n" << rand.second << "/\n__________\n";
		break;
	}
}

int Number_of_question() {
	int num;
	cout << "How many question do you want to answer ?";
	read_Number(num);
	return num;
}

int random_Number(int to, int from)
{
	return (rand() % (to - from + 1) + from);
}

int results(enType type, strandom rand)
{
	switch (type)
	{
	case enType::Add:
		rand.result = rand.first + rand.second;
		break;
	case enType::Sub:
		rand.result = rand.first - rand.second;
		break;
	case enType::Mult:
		rand.result = rand.first * rand.second;
		break;
	case enType::divs:
		rand.result = rand.first / rand.second;
		break;
	}
	return rand.result;
}

bool check_result(int realresult, int result)
{
	bool win = 0;
	if (realresult == result)
	{
		cout << "Right Answer :-) \a\n";
		system("color 02");
		win = 1;
	}
	else
	{
		cout << "wrong Answer :-(\a\n";
		system("color 04");
		win = 0;
		cout << "the right answer is : " << realresult;
	}
	return win;
}

int Enter_level()
{
	int num;
	cout << "Enter questions level [1] easy, [2] medium,[3] hard,[4] mix ?";
	read_Number(num);
	return num;
}

bool easy_level(enType type)
{
	strandom strand = { 0,0,0 };
	bool winner = 0;
	int res;
	strand.first = random_Number(1, 10);
	strand.second = random_Number(1, 10);
	printexp(type, strand);
	strand.result = results(type, strand);
	cin >> res;
	winner = check_result(strand.result, res);
	return winner;
}

bool medium_level(enType type)
{
	strandom strand = { 0,0,0 };
	bool winner = 0;
	int res;
	strand.first = random_Number(1, 100);
	strand.second = random_Number(1, 100);
	printexp(type, strand);
	strand.result = results(type, strand);
	cin >> res;
	winner = check_result(strand.result, res);
	return winner;
}

bool hard_level(enType type)
{
	strandom strand = { 0,0,0 };
	bool winner = 0;
	int res;
	strand.first = random_Number(1, 1000);
	strand.second = random_Number(1, 1000);
	printexp(type, strand);
	strand.result = results(type, strand);
	cin >> res;
	winner = check_result(strand.result, res);
	return winner;
}

enLevel mix_level()
{
	enLevel levels[] = { enLevel::easy,enLevel::meduim, enLevel::hard };
	enLevel randomLevel = levels[rand() % 3];
	return randomLevel;
}

void What_level(enLevel& level, int x) {
	switch (x)
	{
	case 1:
		level = enLevel::easy;
		break;
	case 2:
		level = enLevel::meduim;
		break;
	case 3:
		level = enLevel::hard;
		break;
	case 4:
		level = mix_level();
		break;
	}
}

void print_Levels(int level) {
	switch (level)
	{
	case 1:
		cout << "easy";
		break;
	case 2:
		cout << "meduim";
		break;
	case 3:
		cout << "hard";
		break;
	case 4:
		cout << "mix";
		break;
	}
}

int what_Type()
{
	int num;
	cout << "Enter questions type [1] add, [2] sub,[3] mult,[4] div,[5] mix ?";
	read_Number(num);
	return num;
}

void print_Types(int types) {
	switch (types)
	{
	case 1:
		cout << "Add";
		break;
	case 2:
		cout << "Sub";
		break;
	case 3:
		cout << "mult";
		break;
	case 4:
		cout << "div";
		break;
	case 5:
		cout << "mix";
		break;
	}
}

enType mix_type() {
	enType levels[] = { enType::Add,enType::Sub, enType::Mult,enType::divs};
	enType random_Type = levels[rand()%4];
	return random_Type;
}

void Types(enType& type, int number) {
	switch (number)
	{
	case 1:
		type = enType::Add;
		break;
	case 2:
		type = enType::Sub;
		break;
	case 3:
		type = enType::Mult;
		break;
	case 4:
		type = enType::divs;
		break;
	case 5:
		type = mix_type();
		break;
	}
}

void final_card(int rights, int wrong, int type, int level) {
	cout << "\n\n\n\n________________________________\n\n";
	cout << "   Final Results is ";
	if (rights > wrong)
	{
		cout << "Pass :-)";
		system("color 02");
	}
	else if (rights < wrong)
	{
		cout << "Fail:-( ";
		system("color 04");
	}
	else
	{
		cout << "Tie 50/100.";
		system("color 06");
	}
	cout << "\n\n";
	cout << "________________________________\n\n";
	cout << setw(27) << "Number of questions is  " << ": " << rights + wrong << endl;
	cout << setw(27) << "question level " << ": ";
	print_Levels(level);
	cout << endl;
	cout << setw(27) << "operation type is  " << ": ";
	print_Types(type);
	cout << endl;
	cout << setw(27) << "Number of right answers is  " << ": " << rights << endl;
	cout << setw(27) << "Number of wrong answers is  " << ": " << wrong << endl << endl;
	cout << "________________________________\n\n";
}

void math_Quiz() {
	system("cls");
	int questions = 0, chooseLevel = 0, choosetype = 0;
	int rights = 0, wrong = 0;
	int done = 0;

	strandom rands = { 0,0,0 };
	enLevel  level = enLevel::easy;
	enType type = enType::Add;

	questions = Number_of_question();
	chooseLevel = Enter_level();
	choosetype = what_Type();
	while (done != questions)
	{
		bool right = 0;
		What_level(level, chooseLevel);
		Types(type, choosetype);
		done++;
		cout << "\n\nQuestion [" << done << "/" << questions << "]\n\n";

		switch (level)
		{
		case enLevel::easy:
			right = easy_level(type);
			break;
		case enLevel::meduim:
			right = medium_level(type);
			break;
		case enLevel::hard:
			right = hard_level(type);
			break;
		}
		if (right)
			rights++;
		else
			wrong++;

	}
	final_card(rights, wrong, choosetype, chooseLevel);
}

void repeat_quiz()
{
	bool want = 0;
	do
	{
		system("color 0f");
		math_Quiz();
		cout << "Do you want to take another exam?[1] Yes,[0] NO  ";
		cin >> want;
	} while (want);
}

void start_Quiz() { repeat_quiz(); }
