import json
import sys
import fileinput
import itertools

dbFileName = sys.argv[1]

userClusters = []
f = open(JSONdb+"_userClusters.json","w")
userClusters = json.loads(f.read())
f.close()