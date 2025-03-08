/*
In a unique_ptr, the copy constructor and copy assignment operators are disabled.

We enable things through move semantics.
https://chatgpt.com/share/67bac3a1-28dc-8002-86f0-3d2b483eb617
*/
namespace std {

template <typename T>
class unique_ptr {
    T* data;

   public:
    unique_ptr& operator=(const unique_ptr& val) = delete;

    // unique_ptr(T* d) {
    //     data = d;
    // }

    ~unique_ptr() {
        delete data;
    }
    T operator*() {
        return *data;
    }
};

template <typename T>
unique_ptr<T> make_unique(T data) {
    return unique_ptr(new T{data});
}

// actual way it is implemented
template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

}  // namespace std
