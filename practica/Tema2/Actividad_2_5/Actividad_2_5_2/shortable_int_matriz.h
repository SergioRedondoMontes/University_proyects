class ShortableIntMatriz
{
private:
  unsigned int _sizeRow, _sizeCol;
  int **_arrMatrix;

public:
  ShortableIntMatriz(int sizeRow, int sizeCol);
  void addRandomNumberToMatrix();
  void orderArrAlgBubblesReverse();
  void writeOnConsole();
  ~ShortableIntMatriz();
};