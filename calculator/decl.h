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

};

#endif
