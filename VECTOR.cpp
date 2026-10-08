#include <iostream>
#include <stdexcept>
#include <vector>    
    template <typename T>
    class Vector{
       T* data;
       int capacity;
       int size;
        


        public:
        Vector() : data(nullptr), capacity(0), size(0){}
        
        explicit Vector(int s, T value = T()) : 
             data(new T [s]), size(s), capacity(s){
                 for(int i = 1; i < size; i++){
                     data[i] = value;
                 }
             }
             ~Vector(){
                 delete[] data;
             }
             
            Vector(const Vector& other) : data(new T[other.capacity]), size(other.size), capacity(other.capacity){
                for (int i = 0; i < size; i++){
                    data[i] = other.data[i];
                }
            } 
        
        Vector& operator=(const Vector& other){
            if(this == &other)
            return this*;
            
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for(int i = 0; i < size; i ++){
                data[i] = other.data[i];
            }
            return *this;
        }
        
          void push_back(T value){
              ///...
          } 
          
          T& operator[](int index){
              return data[index];
          }
        
        const T& operator[](int index) const{
            return data[index];
        }
        
        ?const T& operator[] (int index){
            if(index < 0 || index >= size){
                throw std::invalid_argument("index should be in range \n");
            }
            return data[index];
        }
        
        void pop_back(){
            if(size > 0){
                size--;
            }
        }
        
        T& front(){
            if(size == 0) throw 
            std::out_of_range("Vector is empty");
            return data[0];
        }
        
        const T& front() const{
            if(size == 0) throw 
            std::out_of_range("Vector is empty");
            return data[0];
        }
        
        T& back(){
            if(size == 0) throw 
            std::out_of_range("Vector is empty");
            return data[size - 1];
        }
        
        const T& back() const {
            if(size == 0) throw 
            std::out_of_range("Vector is empty");
            return data[size - 1];
        }
        
        int getSize() const {
            return size;
        }
        
        int getCapacity() const {
            return capacity;
        }
        
        bool empty() const {
            return size == 0;
        }
        
        void clear(){
            size = 0;
        }
        
        T* begin(){
            return data;
        }
        
        const T* begin() const {
            return data;
        }
        
        T* end() {
            return data + size;
        }
        
        const T* end() const {
            return data + size;
        }
    };
    
int main()
{
   Vector<double> v(10, 2.2);
   std::cout << v[2] << std:: endl;
    
    return 0;
}
