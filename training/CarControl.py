import tkinter as tk
import tkinter.font as tkFont

class App:
    def __init__(self, root):
        #setting title
        root.title("undefined")
        #setting window size
        width=600
        height=500
        screenwidth = root.winfo_screenwidth()
        screenheight = root.winfo_screenheight()
        alignstr = '%dx%d+%d+%d' % (width, height, (screenwidth - width) / 2, (screenheight - height) / 2)
        root.geometry(alignstr)
        root.resizable(width=False, height=False)

        GButton_11=tk.Button(root)
        GButton_11["bg"] = "#f0f0f0"
        ft = tkFont.Font(family='Times',size=10)
        GButton_11["font"] = ft
        GButton_11["fg"] = "#000000"
        GButton_11["justify"] = "center"
        GButton_11["text"] = "A"
        GButton_11.place(x=190,y=240,width=70,height=25)
        GButton_11["command"] = self.GButton_11_command

        GButton_106=tk.Button(root)
        GButton_106["bg"] = "#f0f0f0"
        ft = tkFont.Font(family='Times',size=10)
        GButton_106["font"] = ft
        GButton_106["fg"] = "#000000"
        GButton_106["justify"] = "center"
        GButton_106["text"] = "D"
        GButton_106.place(x=310,y=240,width=70,height=25)
        GButton_106["command"] = self.GButton_106_command

        GButton_506=tk.Button(root)
        GButton_506["bg"] = "#f0f0f0"
        ft = tkFont.Font(family='Times',size=10)
        GButton_506["font"] = ft
        GButton_506["fg"] = "#000000"
        GButton_506["justify"] = "center"
        GButton_506["text"] = "W"
        GButton_506.place(x=250,y=190,width=70,height=25)
        GButton_506["command"] = self.GButton_506_command

        GButton_706=tk.Button(root)
        GButton_706["bg"] = "#f0f0f0"
        ft = tkFont.Font(family='Times',size=10)
        GButton_706["font"] = ft
        GButton_706["fg"] = "#000000"
        GButton_706["justify"] = "center"
        GButton_706["text"] = "S"
        GButton_706.place(x=250,y=300,width=70,height=25)
        GButton_706["command"] = self.GButton_706_command

    def GButton_11_command(self):
        print("command")


    def GButton_106_command(self):
        print("command")


    def GButton_506_command(self):
        print("command")


    def GButton_706_command(self):
        print("command")

if __name__ == "__main__":
    root = tk.Tk()
    app = App(root)
    root.mainloop()
