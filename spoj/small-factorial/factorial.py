result = [None]*500

def multiply(x , res_size) : 
    carry = 0
    for i in range(0 , res_size) : 
        product = result[i]*x + carry 
        result[i] = product % 10 
        carry = product // 10 
  
    while(carry != 0) : 
        result[res_size] = carry%10
        carry = carry // 10
        res_size += 1
    return res_size

def factorial(number) : 
    result[0] = 1
    res_size = 1

    for x in range(2 , number+1) : 
        res_size = multiply(x , res_size)
    
    for i in range(res_size-1 , -1 , -1) : 
        print(result[i] , end="")
    
def main() : 
    test = input()
    test = int(test)
    for i in range(test): 
        integer = input()
        integer = int(integer)
        factorial(integer)
main()