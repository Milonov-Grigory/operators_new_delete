//
// Created by krage56 on 25.04.2020.
//

#include "PoolAllocator.h"
#include "iostream"
using namespace std;
PoolAllocator::PoolAllocator(size_t chunksPerBlock): mChunksPerBlock(chunksPerBlock) {
    blockBeg = allocateBlock(standardChunk);
    currentFreeChunk = blockBeg;
    freeChunks = chunksPerBlock;
}

void *PoolAllocator::allocate(size_t size) {
   if(freeChunks < size / standardChunk + ((size % standardChunk)? 1:0)){
       throw std::bad_alloc();
   }
   if(currentFreeChunk == nullptr){
       throw std::bad_alloc();
   }
   freeChunks -= (size / standardChunk + ((size % standardChunk)? 1:0));
   Chunk* freeChunk = currentFreeChunk;
   for(size_t i = 0; i <= size / standardChunk + ((size % standardChunk)? 1:0); ++i){
        currentFreeChunk = currentFreeChunk->next;
   }
   return freeChunk;
}

void PoolAllocator::deallocate(void *ptr, size_t size) {
    // The freed chunk's next pointer points to the
    // current allocation pointer:
    if(size / standardChunk + ((size % standardChunk)? 1:0) <= 1){
        reinterpret_cast<Chunk*>(ptr)->next = currentFreeChunk;
        currentFreeChunk = reinterpret_cast<Chunk*>(ptr);
        ++freeChunks;
    }
    else{
        void* tmpPtr = ptr;
        for(size_t i = 0; i < size / standardChunk + ((size % standardChunk)? 1:0); ++i){
            reinterpret_cast<Chunk*>(tmpPtr)->next =
                    reinterpret_cast<Chunk*>(reinterpret_cast<char*>(ptr) + standardChunk);
            tmpPtr = reinterpret_cast<Chunk*>(tmpPtr)->next;
            ++freeChunks;
        }
        reinterpret_cast<Chunk*>(tmpPtr)->next = nullptr;
    }
}

PoolAllocator::Chunk *PoolAllocator::allocateBlock(size_t chunkSize) {
    cout << "\nAllocating block (" << mChunksPerBlock << " chunks):\n\n";

    size_t blockSize = mChunksPerBlock * chunkSize;//block size in bites

    // The first chunk of the new block.
    auto *blockBegin = reinterpret_cast<Chunk*>(malloc(blockSize));

    // Once the block is allocated, we need to chain all
    // the chunks in this block:
    Chunk *chunk = blockBegin;
    //Block marking
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
        free(blockBeg);//Is this way to free the memory correct?
        freeChunks = 0;
}
