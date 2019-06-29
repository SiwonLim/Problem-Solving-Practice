def solution(record):
    answer = []
    a={}
    for i in range(0,len(record)):
        s = record[i].split()
        if s[0] == "Enter" or s[0] == "Change":
            a[s[1]]=s[2]
    for i in range(0,len(record)):
        s = record[i].split()
        if s[0] == "Enter":
            answer.append(a[s[1]]+"님이 들어왔습니다.")
        elif s[0] == "Leave":
            answer.append(a[s[1]] + "님이 나갔습니다.")
    return answer