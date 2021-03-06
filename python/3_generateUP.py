import itertools
import sys
import json
import fileinput

dbFileName = sys.argv[1]

def readKeyValueNodes(fileName):
    f = open(fileName, "r")
    keyValueNodes = json.loads(f.read())
    f.close()
    return keyValueNodes

def readUserSequence(fileName):
    userSequence = {}
    for line in fileinput.input(fileName):
        jsonUser = json.loads(line)
        userSequence.update(jsonUser)
    return userSequence

def readTypeInfo(fileName):
    f = open(fileName, "r")
    datatype = json.loads(f.read())
    f.close()
    return datatype

def normalizeWeights(userProfiles, keyValueNodes, datatype):
    """
        userProfiles (dictionary) : contains userProfiles each containing 2 keys, alpha and weights
        keyValueNodes 
        Normalize the weights in the weight vector. We'll get the relative importance of each individual attribute is quantified
    """

    attribRange = {}
    for key in keyValueNodes:
        attribRange[key] = len(keyValueNodes[key])

    for profile in userProfiles:
        for attrib in userProfiles[profile]["weights"]:
            for value in userProfiles[profile]["weights"][attrib]:
                if value != "@RAI":
                    userProfiles[profile]["weights"][attrib][value][0] *= len(keyValueNodes[attrib][value])
            userProfiles[profile]["weights"][attrib]["@RAI"] *= attribRange[attrib]

    for profile in userProfiles:
        sumOfAttribWeights = float(sum( [userProfiles[profile]["weights"][attrib]["@RAI"] for attrib in userProfiles[profile]["weights"] ]))
        for attrib in userProfiles[profile]["weights"]:
            userProfiles[profile]["weights"][attrib]["@RAI"] /= sumOfAttribWeights
            sumOfValueWeights = float(sum([ userProfiles[profile]["weights"][attrib][value][0] for value in userProfiles[profile]["weights"][attrib] if value!="@RAI"] ))
            for value in userProfiles[profile]["weights"][attrib]:
                if value!="@RAI" :
                    userProfiles[profile]["weights"][attrib][value][0] /= sumOfValueWeights

def tweakWeights(keyValueNodes, userProfile, itemSequence):
    """
        itemSequence: A list of tuples of the form (item, rating)
    """

    #get the list of items that the user is associated with
    itemRating = dict(itemSequence)
    items = set(itemRating.keys())
    userProfileWeights = {}
    for attrib in keyValueNodes:
        userProfileWeights[attrib] = {}
        userProfileWeights[attrib]["@RAI"] = 0
        for value in keyValueNodes[attrib]:
            intersectionNodes = list(items.intersection(set(keyValueNodes[attrib][value])))
            itemPair = itertools.combinations(intersectionNodes, 2)

            tempValue = 0
            for item1, item2 in itemPair:
                increment = float(itemRating[item1]) + float(itemRating[item2])
                tempValue += increment
                userProfileWeights[attrib]["@RAI"] += increment

            if tempValue:
                userProfileWeights[attrib][value] = [tempValue, [itemRating[node] for node in intersectionNodes]]

        if len(userProfileWeights[attrib].keys()) > 1:
            sumAttrib = 0
            for value in userProfileWeights[attrib]:
                if value != "@RAI":
                    sumAttrib += userProfileWeights[attrib][value][0]

            #sumAttrib = float(sum(userProfileWeights[attrib].values()) - userProfileWeights[attrib]["@RAI"])
            for value in userProfileWeights[attrib]:
                if value != "@RAI":
                    userProfileWeights[attrib][value][0] /= sumAttrib

        #userProfileWeights[attrib]["@RAI"] = sumAttrib

    sumOfWeights = float(sum([userProfileWeights[attrib]["@RAI"] for attrib in userProfileWeights]))
    userProfile["weights"] = userProfileWeights
    for attrib in userProfile["weights"]:
        userProfile["weights"][attrib]["@RAI"] /= sumOfWeights

keyValueNodes = readKeyValueNodes(dbFileName + "_keyValueNodes.json")
userSequence = readUserSequence(dbFileName + "_userData.json") 
datatype = readTypeInfo(dbFileName + "_typeInfo.json")

print "\ncreating userProfiles.."
userProfiles = {}
count = 0
numOfUsers = float(len(userSequence))
threads = []
for sequence in userSequence:
    # initializing alpha, weight vector to each user
    count += 1
    print count
    userProfiles[sequence] = {}
    userProfiles[sequence]["alpha"] = 0.5
    userProfiles[sequence]["weights"] = {}  # Key the the attribute and value is the corresponding weight for that attr
    
    #threads.append(threading.Thread(target=tweakWeights, args=(keyValueNodes, userProfiles[sequence], userSequence[sequence])))
    tweakWeights(keyValueNodes, userProfiles[sequence], userSequence[sequence])

print " normalizing weights.."
normalizeWeights(userProfiles, keyValueNodes, datatype)
print " done normalizing weights.."

f = open(dbFileName + "_normalizedUserProfiles.json", "w")
for user in userProfiles:
    f.write(json.dumps({user: userProfiles[user]}) + "\n")
f.close()
print "done creating userProfiles.."

f = open(dbFileName+"_userlist.json", "w")
for user in userProfiles:
    f.write(user + "\n")
f.close()
