from tkinter import*
from TEST_StupidEncrypt import*
root=Tk()
root.title("GUI")
root.geometry("300x200")
root.option_add('*font', 'JetBrain 10 bold')

data = ""
mainKey=""
enMaker=EncryptMaker()

def save():
    global data
    data = text1.get("1.0", END).strip()
    print("บันทึกแล้ว:"+data)
    enMaker.plainTextLL.addLast(data)
    writer(enMaker.plainTextLL)

def encrypt():
    enMaker.plainTextLL=reader()
    enMaker.makeBin()
    enMaker.removeDuplicate()
    writer(enMaker.cipherLL)
    global mainKey
    mainKey=enMaker.finalKey
    print(mainKey)
    
text1=Text(root, height=3, width=30)
text1.pack(pady=10)

button1=Button(root, text="บันทึก", width=12, command=save)
button2=Button(root, text="Encrypt", width=8, command=encrypt)
button1.pack(pady=5)
button2.pack(pady=8)
root.mainloop()
