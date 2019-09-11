def main() :
    for _ in range(10) : 
        total_number = int(input())
        difference = int(input()) 
        absolute_difference = total_number - difference
        answer = absolute_difference//2
        print(total_number-answer)
        print(answer)   
main()