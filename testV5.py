# 資料處理 by沛儒

from distutils.command import check


def mutiple_selection(ans, stu):
    # initialization
    option = []
    for a in range(0, 5):
        option.append(1)
    counter = 0

    for i in range(len(ans)):
        temp1 = ans[i:i+1]
        if(60 <= ord(temp1)):
            option[ord(temp1)-65] *= (-1)

    for i in range(len(stu)):
        temp2 = stu[i:i+1]
        if(60 <= ord(temp2)):
            option[ord(temp2)-65] *= (-1)

    for i in range(0, 5):
        if(option[i] != 1):
            counter -= -1

    return counter
    # 回傳錯的選項數


# 單選題數
num_choice = int(input("單選題總題數："))

# 多選題數
num_selection = int(input("多選題總題數："))
print("單選：1～%d  多選：%d～%d " %
      (num_choice, num_choice+1, num_choice+num_selection))

# 總分
total_score = int(input("此試券總分："))

# 單選配分
scr_choice = int(input("單選單題配分："))

# 多選配分
scr_selection = int(input("多選單題配分："))
# compare with row[0]

stu_number = int(input("學生人數："))

# make sample
word = [[]]
print("考卷解答：")
for i in range(0, (num_choice+num_selection)):
    temp = input()
    word[0].append(temp)
print("-----")

for k in range(1, stu_number+1):
    print(k, "號作答：")
    word.append([])
    for i in range(0, (num_choice+num_selection)):
        temp = input()
        word[k].append(temp)

    stu_score = total_score     # 扣分制

    # mutiple chioce
    for i in range(0, num_choice):
        if(word[0][i] != word[k][i]):
            stu_score -= scr_choice

    # mutiple selection
    for i in range(num_choice, num_choice+num_selection):
        solution = mutiple_selection(word[0][i], word[k][i])  # !!!!!!!!!!!!!
        if(solution == 1):
            stu_score -= scr_selection*2.0/5
        elif(solution == 2):
            stu_score -= scr_selection*4.0/5
        elif(solution >= 3):
            stu_score -= scr_selection

    print(k, "號成績：", stu_score)
    print("-----")

"""
答案
A
B
C
D
E
ABC
ADE

A C C D E CD  AE    單選-1, 多選-3/-1格  90.4
B B B E E ABC BC    單選-3, 多選-0/-5格  84
C B D D E AC  CE    單選-2, 多選-1/-3格  86.4
A B C D E ABC ADE   單選-0, 多選-0/-0格  100
D B D D E A   ACE   單選-2, 多選-2/-2格  85.6
E E A A A D   BC    單選-5, 多選-4/-5格  72
"""
