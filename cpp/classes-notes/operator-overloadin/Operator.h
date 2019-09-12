#ifndef OPERATOR_H
#define OPERATOR_H

class Operator { 
    public : 
        int number;
        Operator();
        Operator(int);
        Operator operator+(Operator obj);
};

#endif