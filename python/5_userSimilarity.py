import json
import sys
import fileinput
import itertools

def getSimilarity(user1, user2, userSimilarity):
    try :
        n1 = userSimilarity[user1][user2][0]
    except :
        n1 = 0
    try :
        n2 = userSimilarity[user2][user1][0]
    except :
        n2 = 0
    try :
        d1 = userSimilarity[user1][user2][1]
    except :
        d1 = 0
    try :
        d2 = userSimilarity[user2][user1][1]
    except :
        d2 = 0
    return (n1+n2)/(d1+d2)

dbFileName = sys.argv[1]
userID = sys.argv[2]
userSimilarity = {}

userlist = []
print "reading ", dbFileName, "_userSimilarity.json"
f = open(dbFileName+"_userSimilarity.json","r")
userSimilarity = json.loads(f.read())
f.close()

f = open("userlist.txt","r")
for line in f:
	userlist.append(str(line))
f.close()	

userlist.remove(userID)

weights = [getSimilarity(userID,user,userSimilarity) for user in userlist]
fig = plt.figure(figsize = (24, 18))
ax = fig.add_subplot(111)
xPos = np.arange(1,len(userlist)+1)
width = 0.2
rects2 = ax.bar(xPos, weights, width, color='#3333FF')

ax.set_ylabel("Similarity score")
ax.set_title("Similarity of " + userID+ "with other users")
ax.set_xticks(xPos + width)
ax.set_xticklabels(userlist)

autolabel(rects2)
fig.savefig("userSimilarity.png")
break