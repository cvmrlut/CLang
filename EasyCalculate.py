import math
class Calculation:
    def breakdown(self,str):
        self.str=str
        for case in self.str:#判定运算方式
            if ('0' <= case <= '9') != True:#从字符串截取运算符号
                index = self.str.find(case)
                n1 = int(self.str[:index])#截取运算符号前的值
                n2 = int(self.str[(index + 1):])#运算符后的值
                switch = {#实现开关语句
                    '+':n1+n2,
                    '-':n1-n2,
                    '*':n1*n2,
                    '/':n1/n2,
                    '^':n1**n2,
                    '%':n1%n2
                }
                print('result:',switch.get(case, 'error!'))#实现开关语句
while True:
    option=input('''Select Option:😄
    C:Only +-*/^%
    A:Advanced calculation
    Enter to exit\n\t''')#要求加的选项🤣
    formula=Calculation()
    if 'C'==option:
        formula.breakdown(input('Please input formula(Example M*Q):'))
    elif 'A'==option:
        print(math.tan(int(input('return input tan:'))))#可后期扩展😁
    else:exit('\texit☺')