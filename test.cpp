#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <cstring>
#include <string>

#ifndef container_of
#define container_of(ptr, type, member) ({ \
    auto *__mptr = (ptr); \
    (type *)( (char *)__mptr - offsetof(type,member) );})

#endif

struct Chunk
{
	char magic[8];
	size_t size;
	bool   used;
	Chunk  *next;
	int    data;
	Chunk() = default;
	Chunk(const Chunk& other) = default;
	Chunk(size_t sz, bool u) : size(sz), used(u), next(0), data(0)
	{
		strcpy(magic,"CHUNK");
	}
};

Chunk* getChunk(void* ptr)
{
	return container_of(ptr, Chunk, data);
}

#define MEM_POOL_SIZE 1024*1024
unsigned char memory_pool[MEM_POOL_SIZE];



int main() try
{
	std::cout << "We have memory pool at " << memory_pool << std::endl;

	Chunk * chunk_ptr = new (memory_pool) Chunk(1024, true);
	std::cout << "We created first chunk at: " << chunk_ptr << std::endl;

	std::string* str = new (reinterpret_cast<char*>(&(chunk_ptr->data))) std::string("Hello Wold!");
	std::cout << "We have made string: " << *str << " at " << str << std::endl;

	Chunk* c1 = getChunk(str);
	std::cout << "We've got chunk ptr from user pointer: " << c1 << std::endl;

	std::cout << "Check the magic is 'CHUNK': " << c1->magic << std::endl;

	str->std::string::~string(); // calling d-tor
	
	return 0;
}
catch(std::bad_alloc& e)
{
  std::cout << "Cannot allocate memory: " << e.what() << std::endl;
	return 1;
}
catch( ... )
{
	std::cout << "Exception caught..." << std::endl;
	return 1;
}

