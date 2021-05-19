import random
l=random.randrange(1,101)
def guess():
    for i in range(10):
        x=int(input("your value"))
        if x<l:
            print("try bigger")
        elif x>l:
            print("try less")     
        else:
            return ("you win")
    return("you lose")
x=guess()
print(x)
    
