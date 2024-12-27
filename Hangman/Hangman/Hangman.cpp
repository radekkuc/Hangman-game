#include <iostream>
#include <unordered_set>
#include <vector>
#include <cstdlib>
#include <algorithm>

std::string mask(std::string wordToMask) {
	std::string maskedWord = "";
	for (int i = 0; i < wordToMask.size(); i++) {
		maskedWord += "_ ";
	}
	return maskedWord;
}


int main() {
	std::vector<std::string>words = {
		"apple", "banana", "cherry", "grape", "orange", "mango", "peach", "plum", "kiwi", "lemon",
"tiger", "elephant", "giraffe", "zebra", "panther", "rabbit", "squirrel", "koala", "otter", "penguin",
"ocean", "river", "mountain", "forest", "desert", "canyon", "island", "lagoon", "volcano", "valley",
"pencil", "notebook", "keyboard", "mouse", "monitor", "laptop", "printer", "camera", "tablet", "phone",
"castle", "village", "bridge", "garden", "tower", "library", "temple", "fortress", "lighthouse", "stadium"
	};


	int n = words.size() - 1;
	srand((unsigned)time(NULL));
	int index = rand() % n;
	std::string wordToGuess = words[index];
	std::unordered_set<char> chars;
	
	for (char c : wordToGuess) {
		chars.insert(c);
	}

	int guesses = 5;
	int right = 0;
	char guess;
	std::string used = "";
	std::string holder = mask(wordToGuess);
	std::cout << "-----------------------------------------------------------------" << std::endl;
	std::cout << "Try to guess the word" << std::endl;
	std::cout << "You can type in only one letter at time" << std::endl;
	std::cout << "Game ends if you guess the word or you dont have any more guesses" << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
	while (guesses > 0) {
		std::cout << "-----------------------------------------------------------------" << std::endl;
		std::cout << "guessed letters: " << holder << std::endl; 
		std::cout << "used letters: " << used << std::endl;
		std::cout << "Type your guess here: ";
		std::cin >> guess;
		if (used.find(guess) == std::string::npos) {  
			if (!used.empty()) {
				used += ", ";  
			}
			used += guess;
		}
		std::cout << "-----------------------------------------------------------------" << std::endl;
		
		if (std::isalpha(guess) && chars.find(guess) != chars.end()) {
			int found = wordToGuess.find(guess);
			int mult = found * 2;
			holder.replace(mult, 1, 1, guess);
			right++;
			std::cout << "You guessed right" << std::endl;
			for (int i = found + 1; i < wordToGuess.size(); i++) {
				if (wordToGuess[i] == guess) {
					holder.replace(2 * i, 1, 1, guess);
					right++;
				}
			}
			if (right >= wordToGuess.size()) {
				std::cout << "Congratulations, you have guessed all the letters";
				return 1;
			}
		}
		else if(!std::isalpha(guess) || std::isupper(guess)){
			std::cout << "Word contains only small letters" << std::endl;
		}
		else {
			std::cout << "Wrong guess, " << guesses - 1 << " left" << std::endl;
			guesses--;
		}
	}
	std::cout << "You have lost, try again";
}


