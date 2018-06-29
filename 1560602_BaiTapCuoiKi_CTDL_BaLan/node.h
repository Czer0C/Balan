#pragma once
#include "token.h"

struct node {
	token key;
	node * pNext;

	// Các phương thức.

	// Hàm dựng mặc định.
	node();

	// Hàm dựng 1 tham số.
	node(token data);
};
