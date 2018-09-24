#ifndef DECL_H_
#define DECL_H_

struct SingleSymbol {
	char symbol;
	int priority;
};

class Pre2Post {
	private:
		int exp_length;
	public:
		int get_priority(char symbol);
		
