//============================================================================
// Name        : Chatbot1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;
const int MAX_RESP = 3;

typedef vector<string> vstring;

vstring find_match(string input);
void copy(char *array[], vstring &v);


typedef struct {
	char *input;
	char *responses[MAX_RESP];
}record;

record KnowledgeBase[] = {
		{"WHAT IS YOUR NAME", // Works, need to input in all caps. More responses as well.
				{"MY NAME IS CHATTERBOT2.",
						"YOU CAN CALL ME CHATTERBOT2.",
						"WHY DO YOU WANT TO KNOW MY NAME?"}
		},

		{"HI",
				{"HI THERE!",
						"HELLO!",
						"HI!"}
		},

		{"HOW ARE YOU",
				{"I'M DOING FINE!",
						"I'M DOING WELL AND YOU?",
						"WHY DO YOU WANT TO KNOW HOW AM I DOING?"}
		},

		{"IM OKAY",
				{"THATS GREAT!",
						"FANTASTIC",
						"THATS GOOD"}
		},
		{"IM PRETTY GOOD",
				{"GOOD",
						"AWESOME",
						"BANNANA PANCAKES FOR THE HAPPY CAMPER"
				}

		},
		{"WHAT ARE YOU DOING?",
				{"MAKING BANNANA PANCAKES",
						"LOOKING FOR A JOB",
						"DISTRACTED BY THE MOON"
				}

		},

		{"WHO ARE YOU",
				{"I'M AN A.I PROGRAM.",
						"I THINK THAT YOU KNOW WHO I AM.",
						"WHY ARE YOU ASKING?"}
		},

		{"ARE YOU INTELLIGENT",
				{"YES,OF COURSE.",
						"WHAT DO YOU THINK?",
						"ACTUALY,I'M VERY INTELLIGENT!"}
		},

		{"ARE YOU REAL",
				{"DOES THAT QUESTION REALLY MATTER TO YOU?",
						"WHAT DO YOU MEAN BY THAT?",
						"I'M AS REAL AS I CAN BE."}
		},

		{"I DONT KNOW",
				{"WELL, YOU SHOULD PROBABLY FIGURE IT OUT",
						"I DONT EITHER",
						"SAME, LETS GET SOME PANCAKES"
				}
		},
		{"COOL",
				{"YEAH",
				"OBVIOUSLY",
				"DONT BE THAT GUY",

				}
		},
		{"IM SAD",
				{"ME TOO, LETS TAKE A NAP",
						"DONT BE SAD, BE HAPPY",
						"DONT BE SAD, PARTY ON!"
				}

		}
};

size_t nKnowledgeBaseSize = sizeof(KnowledgeBase)/sizeof(KnowledgeBase[0]);


int main() {// Main function, doesn't need editing
	cout << "IM DEAF SO PLEASE SCREAM";
	srand((unsigned) time(NULL));

	string sInput = "";
	string sResponse = "";

	while(1) {

		cout << ">";
		getline(cin, sInput);
		vstring responses = find_match(sInput);
		if(sInput == "BYE") {
			cout << "IT WAS NICE TALKING TO YOU USER, SEE YOU NEXT TIME!" << std::endl;
			break;
		}
		else if(responses.size() == 0)  {
			cout << "I'M NOT SURE IF I  UNDERSTAND WHAT YOU  ARE TALKING ABOUT." << std::endl;
		}
		else {
			int nSelection = rand()  % MAX_RESP;
			sResponse =   responses[nSelection]; std::cout << sResponse << std::endl;
		}
	}

	return 0;
}

// make a  search for the  user's input
// inside the database of the program
vstring find_match(string  input) {
	vstring result;
	for(int i = 0; i < nKnowledgeBaseSize;  i++) {
		if(string(KnowledgeBase[i].input) == input) {
			copy(KnowledgeBase[i].responses, result);
			return result;
		}
	}
	return result;
}

void copy(char  *array[], vstring &v) {
	for(int i = 0;  i < MAX_RESP; ++i) {
		v.push_back(array[i]);
	}
}
