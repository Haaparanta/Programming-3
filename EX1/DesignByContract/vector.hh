#ifndef VECTOR_HH
#define VECTOR_HH

class VectorInt
{
public:
  VectorInt();
  ~VectorInt();

  int front() const;

  int& operator[](int location);
  int& at(int location);

  void push_back(int element);

  void swap(VectorInt& v);

private:
  int* datablock_; // This pointer will point to an array of integers allocated with new
  int blocksize_;  // Size of the allocated array
  int elementamount_;   // size of the area used from array
};

#endif // VECTOR_HH
