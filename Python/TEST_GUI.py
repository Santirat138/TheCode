from tkinter import*

root=Tk()
root.title("GUI")
root.geometry("500x500")
root.option_add('*font', 'tahoma 10 bold')
frame=Frame(root)
frame.config(background="cyan")
frame.place(width=300, height=250, x=0, y=0)
button1=Button(frame, text="button1", width=12, height=2)
button1.pack(padx=30, pady=30)
button2=Button(root, text="button2", width=15, height=2)
button2.pack(padx=150, pady=30)
root.mainloop()