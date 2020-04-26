//
// Created by krage56 on 25.04.2020.
//

#pragma once
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
    //Pointer on the current free-chunk.
    Chunk *currentFreeChunk = nullptr;
    //A point to the beginning of the block
    Chunk *blockBeg = nullptr;
    //A number of free chunks
    size_t freeChunks = 0;
    //Allocates a larger block (pool) for chunks.
    Chunk *allocateBlock(size_t chunkSize);
    //Standard size of chink
    size_t standardChunk = 64;
};

