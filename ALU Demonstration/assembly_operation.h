#ifndef ASSEMBLY_OPERATION
#define ASSEMBLY_OPERATION

#include <bitset>
#include <vector>

class assembly_operation
{
private:
	enum operator_code
	{
		ADD,
		SUB,
		AND,
		OR,
		XOR,
		NOT,
		LSL,
		LSR,
		EQ,
		LT,
		GT,
		INVALID
	};

	operator_code hashit(string const& inbound_string)
	{
		if (inbound_string == "ADD") return ADD;
		if (inbound_string == "SUB") return SUB;
		if (inbound_string == "AND") return AND;
		if (inbound_string == "OR") return OR;
		if (inbound_string == "XOR") return XOR;
		if (inbound_string == "NOT") return NOT;
		if (inbound_string == "LSL") return LSL;
		if (inbound_string == "LSR") return LSR;
		if (inbound_string == "EQ") return EQ;
		if (inbound_string == "LT") return LT;
		if (inbound_string == "GT") return GT;
		return INVALID;
	}

	vector<bitset<32>> hex_to_binary(int number_of_args, vector<string> arguements_to_convert)
	{
		if (arguements_to_convert.size() <= 0 
			|| number_of_args > arguements_to_convert.size()
			|| arguements_to_convert.size() > number_of_args)
		{
			throw out_of_range("ERROR: Invalid Operand Count!");
		}

		vector<bitset<32>> modified_arguements;

		for (int i = 0; i < number_of_args; i++) //convert hex arguments to binary
		{
			//print unmodified hex input arguments
			stringstream ss;
			ss << hex << arguements_to_convert[i];
			unsigned n;
			ss >> n;
			bitset<32> b(n);
			modified_arguements.push_back(b);
		}
		return modified_arguements;
	}

	void print_input(string operator_type, vector<string> hex_operand_vec)
	{
		cout << operator_type << " ";
		for (string operand : hex_operand_vec)
		{
			cout << operand << " ";
		}
		cout << ": ";
	}

public:
	string execute_operation(string operator_type, vector<string> hex_operand_vec)
	{
		switch (hashit(operator_type))
		{
			case ADD:
			{
				print_input(operator_type, hex_operand_vec);

				try
				{
					vector<bitset<32>> bin_operand_vec = hex_to_binary(2, hex_operand_vec);
					unsigned long result = bin_operand_vec[0].to_ulong() + bin_operand_vec[1].to_ulong();
					cout << hex << result << endl;
				}
				catch (const out_of_range& error)
				{
					cerr << error.what() << endl;
				}
				break;
			}
			case SUB:
			{
				print_input(operator_type, hex_operand_vec);

				try
				{
					vector<bitset<32>> bin_operand_vec = hex_to_binary(2, hex_operand_vec);
					unsigned long result = bin_operand_vec[0].to_ulong() - bin_operand_vec[1].to_ulong();
					cout << hex << result << endl;
				}
				catch (const out_of_range& error)
				{
					cerr << error.what() << endl;
				}
				break;
			}
			case AND:
			{
				print_input(operator_type, hex_operand_vec);
				
				try 
				{
					vector<bitset<32>> bin_operand_vec = hex_to_binary(2, hex_operand_vec);
					unsigned long result = (bin_operand_vec[0] & bin_operand_vec[1]).to_ulong();
					cout << hex << result << endl;
				}
				catch (const out_of_range& error)
				{
					cerr << error.what() << endl;
				}
				break;
			}
			case OR:
			{
				print_input(operator_type, hex_operand_vec);

				try
				{
					vector<bitset<32>> bin_operand_vec = hex_to_binary(2, hex_operand_vec);
					unsigned long result = (bin_operand_vec[0] | bin_operand_vec[1]).to_ulong();
					cout << hex << result << endl;
				}
				catch (const out_of_range& error)
				{
					cerr << error.what() << endl;
				}
				break;
			}
			case XOR:
				print_input(operator_type, hex_operand_vec);

				try
				{
					vector<bitset<32>> bin_operand_vec = hex_to_binary(2, hex_operand_vec);
					unsigned long result = (bin_operand_vec[0] ^ bin_operand_vec[1]).to_ulong();
					cout << hex << result << endl;
				}
				catch (const out_of_range& error)
				{
					cerr << error.what() << endl;
				}
				break;
			case LSL:
				cout << "LSL" << endl;
				break;
			case LSR:
				cout << "LSR" << endl;
				break;
			case EQ:
				print_input(operator_type, hex_operand_vec);

				try
				{
					vector<bitset<32>> bin_operand_vec = hex_to_binary(2, hex_operand_vec);
					if (bin_operand_vec[0] == bin_operand_vec[1])
					{
						cout << "True" << endl;
					}
					else
					{
						cout << "False" << endl;
					}
				}
				catch (const out_of_range& error)
				{
					cerr << error.what() << endl;
				}
				break;
			case LT:
				print_input(operator_type, hex_operand_vec);

				try
				{
					vector<bitset<32>> bin_operand_vec = hex_to_binary(2, hex_operand_vec);
					if (bin_operand_vec[0].to_ulong() < bin_operand_vec[1].to_ulong())
					{
						cout << "True" << endl;
					}
					else
					{
						cout << "False" << endl;
					}
				}
				catch (const out_of_range& error)
				{
					cerr << error.what() << endl;
				}
				break;
			case GT:
				print_input(operator_type, hex_operand_vec);

				try
				{
					vector<bitset<32>> bin_operand_vec = hex_to_binary(2, hex_operand_vec);
					if (bin_operand_vec[0].to_ulong() > bin_operand_vec[1].to_ulong())
					{
						cout << "True" << endl;
					}
					else
					{
						cout << "False" << endl;
					}
				}
				catch (const out_of_range& error)
				{
					cerr << error.what() << endl;
				}
				break;
			case INVALID:
				print_input(operator_type, hex_operand_vec);
				cout << "ERROR: Unsupported Operation!" << endl;
				break;
		}
		return "null";
	}
};

#endif
