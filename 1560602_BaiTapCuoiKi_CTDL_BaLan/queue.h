#pragma once
#include "node.h"

struct queue {
	node * pHead;
	node * pTail;

	// Các phương thức.
	queue();

	// Hàm dựng 1 tham số (string).
	// Từ 1 chuỗi, "cắt" nhỏ chuỗi ra thành các token và bỏ vào hàng đợi.
	queue(std::string expression);

	// Hàm hủy mặc định.
	~queue();

	// Kiểm tra ngăn xếp rỗng.
	bool isEmpty();

	// "Cho" 1 token vào hàng đợi.
	void enqueue(token data);

	// "Nhổ" token đầu tiên khỏi hàng đợi.
	token pop();

	// "Xem" token đầu tiên của hàng đợi.
	token top();
};