#!/usr/bin/python3

import sys
from collections import Counter

#taken from Wikipedia
letter_freqs = {
    'A': 0.08167,
    'B': 0.01492,
    'C': 0.02782,
    'D': 0.04253,
    'E': 0.12702,
    'F': 0.02228,
    'G': 0.02015,
    'H': 0.06094,
    'I': 0.06966,
    'J': 0.00153,
    'K': 0.00772,
    'L': 0.04025,
    'M': 0.02406,
    'N': 0.06749,
    'O': 0.07507,
    'P': 0.01929,
    'Q': 0.00095,
    'R': 0.05987,
    'S': 0.06327,
    'T': 0.09056,
    'U': 0.02758,
    'V': 0.00978,
    'W': 0.02361,
    'X': 0.00150,
    'Y': 0.01974,
    'Z': 0.00074
}

alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'


def pop_var(s):
    """Calculate the population variance of letter frequencies in given string."""
    freqs = Counter(s)
    mean = sum(float(v)/len(s) for v in freqs.values())/len(freqs)  
    return sum((float(freqs[c])/len(s)-mean)**2 for c in freqs)/len(freqs)





    #################################################################
    # Your code to determine the key and decrypt the ciphertext here

def getKey_length(Array, coincidence,coin_index):
   #gets the key from the message by doing crypAnylis  
    i=0
    print("Length of Array", len(Array))
    while i < len(Array):
        k = 0
        print(k, " K while lopp")
        shift =1
        index_A = shift
        print(len(Array)-shift, "OUTSIDE")
        for j in range(len(Array)-shift):
            print(len(Array)-shift, "INSIDE")
            if Array[index_A] == Array[j]:
                k+=1
                print(k, " K For lopp")
                print(j, "", Array[index_A], "", Array[j])
            index_A+=1
        i+=1
        shift+=1
        coincidence.append(k)
    max_num = coincidence[0]
    for x in coincidence:
        if (coincidence[x] < coincidence[x+1]):
            max_num=coincidence[x+1] #use .max
    for z in coincidence:
        if(max_num*.80 <= coincidence[z]):
            coin_index.append(z) #### Apend the coin index with the index of our sig. fig. line, ex line 7 and 2 
    print(coin_index)
    k_length = coin_index[1]-coin_index[0] ####  
    print(k_length)
    return k_length
    
    
    

#######################################################################333
""""
def decrypt(cipher, key)
    decrypted = ''
    #split the cipher into the length of the key
    split_cipher =[cipher[i:i+len(key)] for i in range(0, len(cipher), len(key))] #where the starts and ends

    convert the cipher into indec and subtract the key with mod 26
    for each_split in split_cipher:
        i=0
        for letter in each split:
            number= (letter_to_indext[letter] + letter_to_index[key[i]]) % len(alphabet)
            decrypted += index_to_letter[number]
            i+=1
     print the decrypted message
    
    return decrypt
"""
    
def main():
    #print(cipher)
    
   
    Array = list(cipher)
    coincidence = []
    coin_index=[]
    getKey_length(Array,coincidence, coin_index)
    return 0
"""
    work= alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    letters=cipher.split()
    for i in len(letters):
        Array.append(i)
"""
   
  #    key= getKey(Array, coincidence, coin_index) ################################### WHAT AM I PASSING THIS 
    #decrpted_message=decrypt(cipher,key)
  
   # print('decrypted message: ' + decrypted_message)
    
    ###############################################################33
    # Starter code
if __name__ == "__main__":
    # Read ciphertext from stdin
    # Ignore line breaks and spaces, convert to all upper case
    cipher = sys.stdin.readline().replace("\n", "").replace(" ", "").upper()
    main()
   
    