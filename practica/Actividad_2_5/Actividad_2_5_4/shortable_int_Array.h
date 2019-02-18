class ShortableIntArray
{
private:
  unsigned int _size;
  int *_arrVector;
  void swapData(int a, int b);

public:
  ShortableIntArray(int size);
  void addRandomNumberToArray();
  void orderArrAlgBubble();
  void orderArraAlgSelectionSort();
  void writeOnConsole();
  ~ShortableIntArray();
};