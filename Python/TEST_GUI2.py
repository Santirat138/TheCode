from tkinter import *

root = Tk()
root.geometry("300x150")

entry = Entry(root, width=25)
entry.pack(pady=10)

def show():
    text = entry.get()          # อ่านข้อความที่ผู้ใช้พิมพ์
    result.config(text=f"คุณพิมพ์: {text}")

btn = Button(root, text="ตกลง", command=show)
btn.pack()

result = Label(root, text="")
result.pack(pady=10)

root.mainloop()