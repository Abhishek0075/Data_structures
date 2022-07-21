import shutil
# n_list=list(range(1,1000))
# str_n_list=[str(x) for x in n_list]
# path=(r'C:\Users\abhir\OneDrive\Desktop\2022INDICON\ ')
# for i in str_n_list:
#     newpath=path+i
#     os.mkdir(newpath)

# for i in str_n_list:
#     Npath=path+i+"\Submission"
#     os.mkdir(Npath)

src = r'C:\Users\abhir\OneDrive\Desktop\2022INDICON\1\Submission\my.xlsx'
dst =  r'C:\Users\abhir\OneDrive\Desktop\transfered\1.xlsx'
shutil.copyfile(src, dst)

src = r'C:\Users\abhir\OneDrive\Desktop\2022INDICON\2\Submission\another.pub'
dst =  r'C:\Users\abhir\OneDrive\Desktop\transfered\2.pub'
shutil.copyfile(src, dst)

src = r'C:\Users\abhir\OneDrive\Desktop\2022INDICON\3\Submission\an.txt'
dst =  r'C:\Users\abhir\OneDrive\Desktop\transfered\3.txt'
shutil.copyfile(src, dst)


src = r'C:\Users\abhir\OneDrive\Desktop\2022INDICON\4\Submission\hello.pptx'
dst =  r'C:\Users\abhir\OneDrive\Desktop\transfered\4.pptx'
shutil.copyfile(src, dst)


src = r'C:\Users\abhir\OneDrive\Desktop\2022INDICON\413\Submission\new.docx'
dst =  r'C:\Users\abhir\OneDrive\Desktop\transfered\413.docx'
shutil.copyfile(src, dst)