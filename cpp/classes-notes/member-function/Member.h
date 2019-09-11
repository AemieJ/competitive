#ifndef MEMBER_H
#define MEMBER_H


class Member {
    public : 
        Member(int reg , int constant);
        void printValue();
    private : 
        int regularVariable;
        const int constantVariable;
};

#endif