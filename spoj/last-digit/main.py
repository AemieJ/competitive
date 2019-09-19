import math

def main() : 
    test = input() 

    for _ in range(int(test)): 
        base , power = map(int, input().split())
        if(base!= 0 or power != 0) :
            if power < 4:
                print(pow(base,power)%10)
            else : 
                for j in range(1,5):
                    if((power-j)%4==0):
                        print(pow(base,j)%10)
                        break
main()