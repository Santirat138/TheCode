from tkinter import*
from Account import*

page1=Tk()
page1.title("main")
page1.geometry("500x500")
page1.option_add('*font', 'JetBrain 10 bold')
text1=Text(page1, height=3, width=30)
text1.pack(pady=10)
button1=Button(page1, text="บันทึก", width=12, command=save)
page1.mainloop()