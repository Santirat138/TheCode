path="C:/Users/WIN11/Desktop/code/TheCode/Python/text.txt"
try:
    file=open(path, 'r')
    textList=file.readlines()
    file.close()
    result=[]
    for data in textList:
        result.append(data.rstrip("\n"))
    print(textList)
    print(result)
    print(result[0])
    print(result[1])
    for msg in result:
        print(msg)
except IOError as e:
    print(e)