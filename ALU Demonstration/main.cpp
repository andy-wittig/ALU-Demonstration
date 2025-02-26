#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

#include "assembly_operation.h"

int main()
{
	fstream inputFile("input.txt");
	assembly_operation assembly_operation_handler;

	string line;

	if (inputFile.is_open())
	{
		while (getline(inputFile, line)) //read through each line from file
		{
			stringstream token_stream(line);
			string token;
			vector<string> tokenized_line;

			while (token_stream >> token) //split token stream into seperate tokens
			{
				tokenized_line.push_back(token);
			}

			vector<string> token_operands = { tokenized_line.begin() + 1, tokenized_line.end() };

			assembly_operation_handler.execute_operation(tokenized_line[0], token_operands);
		}
	}
	else
	{
		cerr << "ERROR: File could not be read!" << endl;
	}
	inputFile.close();

	return 0;
}