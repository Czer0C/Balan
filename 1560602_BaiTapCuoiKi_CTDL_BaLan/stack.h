#pragma once
#include "node.h"

struct stack {
	node * pHead;

	// Các phương thức.

	// Hàm dựng mặc định.
	stack();
	
	// Hàm hủy.
	~stack();

	// Kiểm tra ngăn xếp rỗng.
	bool isEmpty();

	// "Đẩy" 1 token vào đầu ngăn xếp.
	void push(token data);

	// "Nhổ" token đầu tiên khỏi ngăn xếp.
	token pop();

	// "Xem" token đầu tiên của ngăn xếp.
	token top();
};