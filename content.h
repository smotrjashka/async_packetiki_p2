#pragma once

#include <cstddef>
#include <stdlib.h>

struct content {

	content(std::size_t size);
	~content();

	void handle(const char* data, std::size_t size);

	void* get_ptr();

	std::size_t size;

private:
	void* ptr_;

}