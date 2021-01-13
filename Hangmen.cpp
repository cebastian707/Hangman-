//PROGRAM DONE BY::CEBASTIAN SANTIAGO
//C++HANGMAN
#include<iostream>
#include<string>
#include<cctype>
#include<ctime>
#include<time.h>

using namespace std;

void welcome();
void user_guess(char&,string&,string&);
void update(char&, string&, string&);
void Winner(string&, string&);
void loser(int&, int&,string&);

int main() {
    const int Maxes = 10;
	srand(time(NULL));
	int choice = rand() % Maxes;
	string hidden = "*****";
	string words[Maxes] = { "WORLD","POWER","GAMES","EXTRA","PIZZA","CHIVA","DADDY","NIGGA","BUDDY","CODES" };
	char user = '\n';
	int Max = 8;
	int Tries = 1;
	string the_one = " ";
	the_one = words[choice];
	
	
	welcome();
	cout << "Your on try " << Tries << endl;
	do {
		user_guess(user, hidden, the_one);
		cout << endl;
		update(user, hidden,the_one);
		Tries++;
		Winner(hidden, the_one);
		loser(Max, Tries, the_one);
		
		if (Max > Tries) {
			cout << "Your on try " << Tries << endl;
		}
	
	} while (Max > Tries);

	return 0;
}

void loser(int& M, int& T,string & W) {
	if (M == T){
		cout << "You Have been Hanged Fam!:" << " The word was: ";
		cout << W << endl;
		cout << endl;
		cout << "******************\n" << endl;
		cout << "  ----------      " << endl;
		cout << " |       ( )     " << endl;
		cout << " |        |      " << endl;
		cout << " |      __|__    " << endl;
		cout << " |        |      " << endl;
		cout << " |        |      " << endl;
		cout << " |       /|      " << endl;
		cout << "-----" << endl;
		exit(0);
	}
}




void Winner(string& H, string& S) {
	if (H == S) {
		cout << endl;
		cout << endl;
		cout << "You guessed the word!: " << S << endl;
		cout << "End of Game!" << endl;
		exit(0);
	}
}




void update(char& guesses, string& secert, string& wordes) {
	for (int i = 0; i < wordes.length(); i++) {
		if (guesses == wordes[i]) {
			secert[i] = guesses;
		}
	}
}



void welcome() {
	cout << "Welcome to Hangmen" << endl;
	cout << "******************\n" << endl;
	cout << "  ----------      " << endl;
	cout << " |       ( )     " << endl;
	cout << " |        |      " << endl;
	cout << " |      __|__    " << endl;
	cout << " |        |      " << endl;
	cout << " |        |      " << endl;
	cout << " |       /|      " << endl;
	cout << "-----" << endl;
	cout << endl;
	cout << "You get seven tries!" << endl;
	cout << "The word has Five letters" << endl;
	cout << "*********************\n" << endl;
}



void user_guess(char& guess,string& hiddens,string& word) {

	cout << "Correct?:"<< hiddens << ":"<<"Enter  a letter to guees the word(A-Z)?: ";
	cin >> guess;
	guess = toupper(guess);

    while (toupper(guess) < 'A' || toupper(guess) > 'Z') {
		cin.clear();
		cin.ignore(200, '\n');
		cout << "Incorrect not a letter retype!" << endl;
		cout << "Enter  a letter to guees the word(A-Z)?: ";
		cin >> guess;
	}
}