//
// Created by krage56 on 25.04.2020.
//

#include "PoolAllocator.h"
#include "iostream"
using namespace std;
PoolAllocator::PoolAllocator(size_t chunksPerBlock): mChunksPerBlock(chunksPerBlock) {}

void *PoolAllocator::allocate(size_t size) {
    //Firstly the memory-block must be declared
    if (mAlloc == nullptr) {
        mAlloc = allocateBlock(size);
    }
    // The return value is the current position of
    // the allocation pointer:

    Chunk *freeChunk = mAlloc;

    // Advance (bump) the allocation pointer to the next chunk.
    //
    // When no chunks left, the `mAlloc` will be set to `nullptr`, and
    // this will cause allocation of a new block on the next request:

    mAlloc = mAlloc->next;

    return freeChunk;
}

void PoolAllocator::deallocate(void *ptr, size_t size) {
    // The freed chunk's next pointer points to the
    // current allocation pointer:
    reinterpret_cast<Chunk *>(ptr)->next = mAlloc;

    // And the allocation pointer is now set
    // to the returned (free) chunk:

    mAlloc = reinterpret_cast<Chunk *>(ptr);
}

PoolAllocator::Chunk *PoolAllocator::allocateBlock(size_t chunkSize) {
    cout << "\nAllocating block (" << mChunksPerBlock << " chunks):\n\n";

    size_t blockSize = mChunksPerBlock * chunkSize;//block size in bites

    // The first chunk of the new block.
    auto *blockBegin = reinterpret_cast<Chunk*>(malloc(blockSize));

    // Once the block is allocated, we need to chain all
    // the chunks in this block:
    Chunk *chunk = blockBegin;

    for (size_t i = 0; i < mChunksPerBlock - 1; ++i) {
        //create a pointer on the new block of data
        chunk->next =
                reinterpret_cast<Chunk*>(reinterpret_cast<char*>(chunk) + chunkSize);
        chunk = chunk->next;
    }

    chunk->next = nullptr;//the end of the block
    return blockBegin;
}

PoolAllocator::~PoolAllocator() {

}
