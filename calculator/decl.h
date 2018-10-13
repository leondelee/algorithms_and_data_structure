#ifndef DECL_H_
#define DECL_H_

#include <stack>
#include <string>

class Mid2Post {
private:
	std::stack <char> stack_operator;
	int stack_top_priority = -1;
	std::string target_string;
public:
	std::string res_string;
	Mid2Post(std::string t_string);
	~Mid2Post();
	int get_priority(char ch);
	void deal_current_ch(char current_ch);
	void transformer();
	void cout_top();

};

class Calculator {
private:
	char current_operator;
	std::string target_exp;
	int res = 0;
	std::stack <char> ch_stack;
public:
	Calculator(std::string obj_str);
	~Calculator();
	void calculate();
	void calculate_one_step();
};

#endif
