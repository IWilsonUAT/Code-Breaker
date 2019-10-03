#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 10;
	//the array for the code words and hints
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"boxed", "Inside something"},
		{"rabbit", "An animal that hops around" },
		{"tail", "All animals have one, even humans"},
		{"watcher", "If you are viewing something from the outside, you are a "},
		{"ears", "On both sides of your head"},
		{"mouse", "A small rodent"},
		{"sub", "There are lots at a school"},
		{"monitor", "Computers have these"},
		{"speaker", "Most tvs have at least one"},
		{"hotel", "You stay in one n vacation"}
	};
	
	cout << "\t\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	//a for loop to do it for the required number of times
	for (int i = 0; i < 5; i++)
	{
		//selecting the word and jumbling it up
		srand(static_cast<unsigned int>(time(0)));
		int choice = (rand() % NUM_WORDS);
		string theWord = WORDS[choice][WORD];
		string theHint = WORDS[choice][HINT];
		string jumble = theWord;
		int length = jumble.size();
		for (int i = 0; i < length; i++)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}
		cout << "The jumble is : " << jumble;
		string guess;
		cout << "\n\nYour guess:";
		cin >> guess;
		//while loop to keep it going until you guess it right or quit
		while ((guess != theWord) && (guess != "quit"))
		{
			if (guess == "hint")
			{
				cout << theHint;
			}
			else
			{
				cout << "Sorry that's not it.";
			}
			cout << "\n\nYour Guess: ";
			cin >> guess;
		}
		if (guess == theWord)
		{
			cout << "\n That's it! You guessed it!\n";

		}
	}
	return 0;
}