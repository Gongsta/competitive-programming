
struct Chunk {
    Chunk* next;
    size_t size;
    void* data;
}

class GenericAllocator {
   public:
    virtual void* allocate(size_t size) = 0;
    virtual void deallocate(void* ptr) = 0;
};

class MyAllocator : public GenericAllocator {
    void* memory_pool;
    size_t pool_size;

   public:
    MyAllocator() {
        memory_pool = malloc(1024);
    }
    void* allocate(size_t size) override {
    }

    void deallocate(void* ptr) override {
        free(ptr);
    }
    ~MyAllocator() {
        free(memory_pool);
    }
}
