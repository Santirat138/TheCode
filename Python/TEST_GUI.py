from tkinter import*

root=Tk()
root.title("GUI")
root.geometry("500x500")
root.option_add('*font', 'tahoma 10 bold')

frame=Frame(root)
frame.config(background="cyan")
frame.place(width=300, height=250, x=0, y=0)

label1Num=IntVar(value=0)

def func():
    label1Num.set(label1Num.get()+1)


label1=Label(frame, width=80, height=60, bg="white", textvariable=label1Num)
label1.place(height=10, width=50, x=10, y=10)
button1=Button(root, text="button1", width=12, height=2, command=func)
button1.pack(padx=100, pady=20)
button2=Button(root, text="button2", width=15, height=2)
button2.pack(padx=150, pady=30)

root.mainloop()