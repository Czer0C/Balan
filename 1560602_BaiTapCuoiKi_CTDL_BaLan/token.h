#pragma once
#include <iostream>
#include <string>
using namespace std;

#define NotANumber 2147483648

struct token {
	int type;
	long value;

	// Các phương thức.

	// Hàm dựng mặc định.
	token();

	// Hàm dựng 2 tham số: kiểu, giá trị.
	token(int TYPE, int VALUE);

	// Hàm dựng 1 tham số: chuỗi 
	// Nếu chuỗi có > 2 kí tự -> số "dài".
	token(std::string str);

	// Hàm hủy.
	~token();
};