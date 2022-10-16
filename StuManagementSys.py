mdq={'name':'mdq','sex':'male','phone':315624}
sparrow={'name':'sparrow','sex':'male','phone':1113}
stulist=[mdq,sparrow]
def add():
    name = input('‍🎓name:')
    sex = input('sex(male🚹/famale🚺):')
    phone= input('phone📞:')
    studict= {'‍🎓name:':name,'sex(male🚹/famale🚺):':sex,'phone📞:':phone}
    stulist.append(studict)
    print('Successfully modified😀!')
def view():#显示所有信息
    if len(stulist)!=0:#判断数据有没有让熊孩子用户删空了
        for dict in stulist:
            print(dict)
        else:print('No information😅')
def search():
    search_name=input('Find by name:')
    for dict in stulist:
        if search_name==dict['name']:
            print('name:%s\nsex:%s\nphone:%s\n'%(dict['name'], dict['sex'], dict['phone']))
            modify(dict)#调用修改/删除函数
            break
    else:print("Not student named %s found"%search_name)
def modify(find_dict):#修改/删除
    o=input('Select option:\nM:modify\nR:remove\nAny other key to back\n\t:')
    if o=='M':#修改信息
        print('Input modify information(Enter不进行修改)')
        find_dict['name']=update(find_dict['name'],'name:')
        find_dict['sex']=update(find_dict['sex'],'sex:')
        find_dict['mp']=update(find_dict['phone'],'phone:')
        print('Modify successfully🥳')
    elif o=='R':#删除学生信息
        stulist.remove(find_dict)
        print('Remove successfully🥳')
    else:pass
def  update(dict_value,tip):#修改
    result_str=input(tip)
    if len(result_str)>0:
        return result_str#如果输入内容返回结果
    else:return dict_value#如果没有输入内容，返回原来的值
while True:
    o=input('''Select option:
     A:Add student information
     V:View student information
     S:Serch student information
         Modify or remove student information
     Enter to exit\n\t''')
    if o=='A':
        add()
    elif o=='S':
        search()
    elif o=='V':
        view()
    else:exit('\tWelcome to the visit 😀')