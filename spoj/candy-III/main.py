def main():
    print("\n")
    testCases = int(input())
    print("\n")
    for _ in range(testCases):
        totalNumber = int(input())
        sumCandy= 0
        for _ in range(totalNumber) : 
            candy = int(input())
            sumCandy += candy
        
        if(sumCandy%totalNumber == 0) : 
            print("YES")
        else :
            print("NO")
        print("\n")

main()