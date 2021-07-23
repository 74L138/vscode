import numpy as np
def random_num(a,b):

    ran=b-a
    result=0
    for i in range(ran):
        r=np.random.randint(2)
        result+=r
    if result>ran:
        return random_num(a,b)
    else: return a+result

print(random_num(1,8))
