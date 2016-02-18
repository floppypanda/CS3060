#ifndef MONEY_H
#define MONEY_H

class Money
{
  private:
    unsigned int dollars;
    unsigned int cents;
  public:
    unsigned int getDollars() const;
    void setDollars(unsigned int dollars);
    unsigned int getCents() const;
    void setCents(unsigned int cents);
    double getMoney() const;
};

#endif
