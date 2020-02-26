#ifndef CARD_HPP
#define CARD_HPP

class Card
{
  private:
    int value = 0;
    Card* prev;
    Card* next;

  public:
    Card(int value, Card* prev = nullptr, Card* next = nullptr);

    void SetNext(Card* next);
    void SetPrev(Card* prev);
    void SetValue(int value);
    int GetValue();
    Card* GetNext();
    Card* GetPrev();

};

#endif
