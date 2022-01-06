from tkinter import *
import math
rad = True
answers = []

class Calculator():
    def __init__(self):
        self.root = Tk()
        self.root.title('Scientific Calculator')
        self.root.geometry('400x325')
        #Create Result Window
        self.resultwindow = Entry(self.root,width=35)
        self.resultwindow.grid(row=0, column=0,columnspan=7)
        self.resultwindow.config(font=("Arial", 18))
        self.resultwindow.focus_set()  
        #Create Buttons and set position

        #Row 1
        rad_btn = Button(self.root, text='Rad', width=5, height=3,command=lambda:self.rad()).grid(row=1, column=0, padx=3, pady=3)

        deg_btn = Button(self.root, text='Deg', width=5,height=3,command=lambda:self.deg()).grid(row=1, column=1, padx=3, pady=3)

        factorial_btn = Button(self.root, text='x!', width=5,height=3,command=lambda:self.factorial()).grid(row=1, column=2, padx=3, pady=3)

        e_btn = Button(self.root, text='e', width=5,height=3,command=lambda:self.ins(math.e)).grid(row=1, column=3, padx=3, pady=3)

        pi_btn = Button(self.root, text='π', width=5,height=3,command=lambda:self.ins(math.pi)).grid(row=1, column=4, padx=3, pady=3)

        ans_btn = Button(self.root, text='ANS', width=5,height=3, command=lambda:self.ans()).grid(row=1, column=5, padx=3, pady=3)

        delete_btn = Button(self.root, text='C', width=5,height=3,command=lambda:self.back()).grid(row=1, column=6, padx=3, pady=3)
    
        #ROW 2
        inversesin_btn = Button(self.root, text='sin^-1', command=lambda:self.inversesin(), width=5,height=3).grid(row=2, column=0, padx=3, pady=3)

        sin_btn = Button(self.root, text='sin', width=5,height=3,command=lambda:self.sin()).grid(row=2, column=1, padx=3, pady=3)

        natural_log_btn = Button(self.root, text='ln', width=5,height=3).grid(row=2, column=2, padx=3, pady=3)

        seven_btn = Button(self.root, text='7', width=5,height=3,fg='red',command=lambda:self.ins(7)).grid(row=2, column=3, padx=3, pady=3)

        eight_btn = Button(self.root, text='8', width=5,height=3,fg='red',command=lambda:self.ins(8)).grid(row=2, column=4, padx=3, pady=3)

        nine_btn = Button(self.root, text='9', width=5,height=3,fg='red',command=lambda:self.ins(9)).grid(row=2, column=5, padx=3, pady=3)

        divide_btn = Button(self.root, text='÷', width=5,height=3,command=lambda:self.ins('/')).grid(row=2, column=6, padx=3, pady=3)

        #Row 3
        inversecos_btn = Button(self.root, text='cos^-1', width=5,height=3,command=lambda:self.inversecos()).grid(row=3, column=0, padx=3, pady=3)

        cos_btn = Button(self.root, text='cos', width=5,height=3,command=lambda:self.cos()).grid(row=3, column=1, padx=3, pady=3)

        log_btn = Button(self.root, text='log', width=5,height=3 ,command=lambda:self.log()).grid(row=3, column=2, padx=3, pady=3)

        four_btn = Button(self.root, text='4', width=5,height=3,fg='red',command=lambda:self.ins(4)).grid(row=3, column=3, padx=3, pady=3)

        five_btn = Button(self.root, text='5', width=5,height=3,fg='red',command=lambda:self.ins(5)).grid(row=3, column=4, padx=3, pady=3)

        six_btn = Button(self.root, text='6', width=5,height=3,fg='red',command=lambda:self.ins(6)).grid(row=3, column=5, padx=3, pady=3)

        mulit_btn = Button(self.root, text='x', width=5,height=3,command=lambda:self.ins('*')).grid(row=3, column=6, padx=3, pady=3)

        #Row 4
        inversetan_btn = Button(self.root, text='tan^-1', width=5,height=3,command=lambda:self.inversetan()).grid(row=4, column=0, padx=3, pady=3)

        tan_btn = Button(self.root, text='tan', width=5,height=3,command=lambda:self.tan()).grid(row=4, column=1, padx=3, pady=3)

        sqr_btn = Button(self.root, text='√', width=5,height=3,command=lambda:self.squareroot()).grid(row=4, column=2, padx=3, pady=3)

        one_btn = Button(self.root, text='1', width=5,height=3,fg='red',command=lambda:self.ins(1)).grid(row=4, column=3, padx=3, pady=3)

        two_btn = Button(self.root, text='2', width=5,height=3,fg='red',command=lambda:self.ins(2)).grid(row=4, column=4, padx=3, pady=3)

        three_btn = Button(self.root, text='3', width=5,height=3,fg='red',command=lambda:self.ins(3)).grid(row=4, column=5, padx=3, pady=3)

        minus_btn = Button(self.root, text='-', width=5,height=3,command=lambda:self.ins('-')).grid(row=4, column=6, padx=3, pady=3)

        #Row 5
        mod_btn = Button(self.root, text='MOD', width=5,height=3,command=lambda:self.ins(' mod ')).grid(row=5, column=0, padx=3, pady=3)

        exp_btn = Button(self.root, text='E', width=5,height=3,command=lambda:self.ins(' E ')).grid(row=5, column=1, padx=3, pady=3)

        power_btn = Button(self.root, text='^', width=5,height=3,command=lambda:self.ins('^')).grid(row=5, column=2, padx=3, pady=3)

        zero_btn = Button(self.root, text='0', width=5,height=3,fg='red',command=lambda:self.ins(0)).grid(row=5, column=3, padx=3, pady=3)

        decimal_btn = Button(self.root, text='.', width=5,height=3,fg='red',command=lambda:self.ins('.')).grid(row=5, column=4, padx=3, pady=3)

        equal_btn = Button(self.root, text='=', width=5,height=3,fg='blue',command=lambda:self.equal()).grid(row=5, column=5, padx=3, pady=3)

        add_btn = Button(self.root, text='+', width=5,height=3,command=lambda:self.ins('+')).grid(row=5, column=6, padx=3, pady=3)

    def ins(self,value):
        self.resultwindow.insert(END,value)
        answers.append(value)

    def back(self):
        self.resultwindow.delete(0,'end')

    def rad(self):
        global rad
        rad = True
        self.back()
        self.ins('Radian Mode')
        
    def deg(self):
        global rad
        rad = False
        self.back()
        self.ins('Degree Mode')
        
    def squareroot(self):
        num = float(self.resultwindow.get())
        self.back()
        if num < 0:
            self.ins('ERROR')
        else:
            self.ins(math.sqrt(num))
            
    def ans(self):
        global anwsers
        self.back()
        self.ins(answers[-1])
        
    def naturallog(self):
        try:
            num = float(self.resultwindow.get())
            self.back()
            self.ins(math.log(num))
        except ValueError:
            self.ins('Error')

    def log(self):
        try:
            num = float(self.resultwindow.get())
            self.back()
            self.ins(math.log10(num))
        except ValueError:
            self.ins('Error')

    def factorial(self):
        try:
            num = float(self.resultwindow.get())
            self.back()
            self.ins(math.factorial(num))
        except ValueError:
            self.ins('Error')

    def cos(self):
        try:
            global rad
            num = float(self.resultwindow.get())
            self.back()
            if rad:
                self.ins(math.cos(num))
            else:
                self.ins(math.cos(math.radians(num)))
        except ValueError:
            self.ins('Error')

    def sin(self):
        try:
            global rad
            num = float(self.resultwindow.get())
            self.back()
            if rad:
                self.ins(math.sin(num))
            else:
                self.ins(math.sin(math.radians(num)))
        except ValueError:
            self.ins('Error')
        
    def tan(self):
        try:
            global rad
            num = float(self.resultwindow.get())
            self.back()
            if rad:
                self.ins(math.tan(num))
            else:
                self.ins(math.tan(math.radians(num)))
        except ValueError:
            self.ins('Error')

    def inversetan(self):
        try:
            global rad
            num = float(self.resultwindow.get())
            self.back()
            if rad:
                self.ins(math.atan(num))
            else:
                self.ins(math.atan(math.radians(num)))
        except ValueError:
            self.ins('Error')

    def inversecos(self):
        try:
            global rad
            num = float(self.resultwindow.get())
            self.back()
            if (1 < num or num < -1):
                self.ins('Out of Bounds')
            else:
                if rad:
                    self.ins(math.acos(num))
                else:
                    self.ins(math.acos(math.radians(num)))
        except ValueError:
            self.ins('Error')

    def inversesin(self):
        try:
            global rad
            num = float(self.resultwindow.get())
            self.back()
            if (1 < num or num < -1):
                self.ins('Out of Bounds')
            else:
                if rad:
                    self.ins(math.asin(num))
                else:
                    self.ins(math.asin(math.radians(num)))
        except ValueError:
            self.ins('Error')

    
    def equal(self):
        equation = self.resultwindow.get()
        equa = equation.replace('^','**')
        equa = equa.replace(' mod ','%')
        equa = equa.replace(' E ','*10**')
        if equa == '':
            self.ins('')
        else:
            answer = eval(equa)
            self.resultwindow.delete(0,END)
            self.ins(answer)
        
    
if __name__ == '__main__':
    Calculator()

