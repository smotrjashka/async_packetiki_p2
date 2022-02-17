#include "content.h"

content::content(std::size_t size) : size(size) {
	//TODO
	ptr_ = malloc(size * 10);
}

void* content::get_ptr() {
	return ptr_;
}

content::~content() {
	free(ptr_);
	ptr_ = nullptr;
}

void content::handle(const char* data, std::size_t size) {

}