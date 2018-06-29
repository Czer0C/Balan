#include "token.h"

// Hàm dựng mặc định.
token::token() { 
	type = -1;
	value = -1;
} 

// Hàm dựng 2 tham số.
token::token(int TYPE, int VALUE) { 
	type = TYPE;
	value = VALUE; 
} 

// Hàm dựng 1 tham số (string). 
token::token(std::string str) {	
	type = 0;				// Mặc định ban đầu kiểu là 0.
	if (str.size() == 1) {  // Nếu có 1 kí tự.
		value = str[0];		// Lấy giá trị của kí tự.	
		if (str[0] == '(' || str[0] == ')')
			type = 1;		// Là ngoặc thì độ ưu tiên = 1.
		else if (str[0] == '+' || str[0] == '-')
			type = 2;		// Là dấu +, - thì độ ưu tiên = 2.
		else if (str[0] == '*' || str[0] == '/')
			type = 3;		// Là dấu *, / thì độ ưu tiên = 3.
		else
			value -= '0';	// Là số thì lấy giá trị nguyên thực sự của nó.
	}
	else // Nếu chuỗi có lớn hơn 2 kí tự (tức số nguyên).
		value = atoi(str.c_str()); // Rút giá trị kiểu nguyên.
}

// Hàm hủy.
token::~token() {

}