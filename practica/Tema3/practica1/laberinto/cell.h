class Cell
{
private:
  int _cell1, _cell2;

public:
  Cell();
  Cell(int cell1, int cell2);
  void setCell1(int cell1);
  void setCell2(int cell2);
  int getCell1();
  int getCell2();
  ~Cell();
};