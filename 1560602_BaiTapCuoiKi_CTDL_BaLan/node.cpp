#include "node.h"

// Hàm dựng mặc định.
node::node() {
	pNext = NULL;
}

// Hàm dựng 1 tham số.
node::node(token data) {
	key = data; 
	pNext = NULL;
}