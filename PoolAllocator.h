//
// Created by krage56 on 25.04.2020.
//

#ifndef MOVE_POOLALLOCATOR_H
#define MOVE_POOLALLOCATOR_H

#include <cstddef>
/*Initialize a single memory-block*/
class PoolAllocator {
    //use as just pointer on the beginning of allocated block of memory
    struct Chunk {
        //if chunk not use yet the "next" route to next chunk
        //else it overload like its block of data
        Chunk* next;
    };
public:
    /*Allocator with parameter - number of chunks*/
    explicit PoolAllocator(size_t chunksPerBlock = 1024);
    //Receive quantity of bites required
    void *allocate(size_t size);
    //Deallocate chunk on ptr-pointer
    void deallocate(void *ptr, size_t size);

    ~PoolAllocator();
private:
    /**
     * There are a number of blocks which consist of chunks.
     * This variable control the number chunks per block.
     */
    size_t mChunksPerBlock;

    /**
     * Pointer on the nearest free-chunk.
     */
    Chunk *mAlloc = nullptr;//заменить на коллекцию указателей на начала блоков и указатель
                            //на текущий свободный chunk - необходимо, чтобы освободить память
                            //в деструкторе

    /**
     * Allocates a larger block (pool) for chunks.
     */
    Chunk *allocateBlock(size_t chunkSize);
    //Standard size of memory
    size_t standardChunk = 64;
};


#endif //MOVE_POOLALLOCATOR_H
