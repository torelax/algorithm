import base64
f=open('D:\\algorithm\\Algotest\\week2\\sort.png','rb') 
ls_f=base64.b64encode(f.read()) 
print(ls_f)
print("哈喽")

""" import base64    base64
bs='iVBORw0KGgoAAAANSUhEUg....' 
imgdata=base64.b64decode(bs)
file=open('2.jpg','wb')
file.write(imgdata)
file.close() """
