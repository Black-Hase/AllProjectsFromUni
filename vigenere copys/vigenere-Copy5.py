import sys
from collections import Counter



MAX_KEY_LENGTH_GUESS = 20
alphabet = 'abcdefghijklmnopqrstuvwxyz'


english_frequences = [0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015,
              0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749,
              0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758,
              0.00978, 0.02360, 0.00150, 0.01974, 0.00074]


def get_index_c(ciphertext):

    N = float(len(ciphertext))
    frequency_sum = 0.0


    for letter in alphabet:
        frequency_sum+= ciphertext.count(letter) * (ciphertext.count(letter)-1)


    ic = frequency_sum/(N*(N-1))
    return ic


def get_key_length(ciphertext):
    ic_table=[]


    for guess_len in range(MAX_KEY_LENGTH_GUESS):
        ic_sum=0.0
        avg_ic=0.0
        for i in range(guess_len):
            sequence=""
    
            for j in range(0, len(ciphertext[i:]), guess_len):
                sequence += ciphertext[i+j]
                # print("sequence: ", sequence)
            ic_sum+=get_index_c(sequence)

        if not guess_len==0:
            avg_ic=ic_sum/guess_len
        ic_table.append(avg_ic)


    best_guess = ic_table.index(sorted(ic_table, reverse = True)[0])
    second_best_guess = ic_table.index(sorted(ic_table, reverse = True)[1])


    if best_guess % second_best_guess == 0:
        return second_best_guess
    else:
        return best_guess


def freq_analysis(sequence):
    all_chi_squareds = [0] * 26

    for i in range(26):

        chi_squared_sum = 0.0


        sequence_offset = [chr(((ord(sequence[j])-97-i)%26)+97) for j in range(len(sequence))]
        v = [0] * 26

        for l in sequence_offset:
            v[ord(l) - ord('a')] += 1

        for j in range(26):
            v[j] *= (1.0/float(len(sequence)))


        for j in range(26):
            chi_squared_sum+=((v[j] - float(english_frequences[j]))**2)/float(english_frequences[j])


        all_chi_squareds[i] = chi_squared_sum


    shift = all_chi_squareds.index(min(all_chi_squareds))


    return chr(shift+97)

def get_key(ciphertext, key_length):
    key = ''


    for i in range(key_length):
        sequence=""

        for j in range(0,len(ciphertext[i:]), key_length):
            sequence+=ciphertext[i+j]
        print("sequence BOOBS: ", sequence)
        key+=freq_analysis(sequence)

    return key


def decrypt(ciphertext, key):

    cipher_ascii = [ord(letter) for letter in ciphertext]
    key_ascii = [ord(letter) for letter in key]
    plain_ascii = []


    for i in range(len(cipher_ascii)):
        plain_ascii.append(((cipher_ascii[i]-key_ascii[i % len(key)]) % 26) +97)


    plaintext = ''.join(chr(i) for i in plain_ascii)
    return plaintext

def encrypt(plaintext, key):

    plain_ascii = [ord(letter) for letter in plaintext]
    key_ascii = [ord(letter) for letter in key]
    cipher_ascii = []


    for i in range(len(plain_ascii)):

        temp = plain_ascii[i]+key_ascii[i % len(key)]-97
        if temp>122:
   
            cipher_ascii.append(temp-26)
        else:
            cipher_ascii.append(temp)


    ciphertext = ''.join(chr(i) for i in cipher_ascii)
    return ciphertext

def main():

    input_cipher = ""

    for line in sys.stdin:
        input_cipher = input_cipher + line

    input_cipher = input_cipher.replace(" ", "").replace("\n", "").upper()

    # ask = False
    # while ask:
    #     text = input("Enter e to encrypt, or d to decrypt: ")
    #     if text =='e':
    #         plaintext_unfiltered = input("Enter plaintext to encrypt: ")
    #         key_unfiltered = input("Enter key to encrypt with: ")

   
    #         plaintext = ''.join(x.lower() for x in plaintext_unfiltered if x.isalpha())	
    #         key = ''.join(x.lower() for x in key_unfiltered if x.isalpha())	
    #         print(key)

    #         ciphertext = encrypt(plaintext, key)	
    #         print("Ciphertext: {}".format(ciphertext))

    #         ask = False	
    #     elif text == 'd':
    #         # ciphertext_unfiltered = input("Enter ciphertext to decrypt: ")  #ciphertext goes here
    #         ciphertext_unfiltered = input_cipher

   
    #         ciphertext = ''.join(x.lower() for x in ciphertext_unfiltered if x.isalpha())	

    #         askkey = True
    #         while askkey:
    #             torf = input("Do you know the key to decrypt with? Enter y or n: ")
    #             if torf == 'n':

    #                 key_length=get_key_length(ciphertext)
    #                 print("Key length is most likely {}".format(key_length))

    #                 key = get_key(ciphertext, key_length)
    #                 plaintext = decrypt(ciphertext, key)

    #                 print("Key: {}".format(key))
    #                 print("Plaintext: {}".format(plaintext))

    #                 askkey = False
    #             elif torf == 'y':

    #                 key_unfiltered = input("Enter key to decrypt with: ")
    #                 key = ''.join(x.lower() for x in key_unfiltered if x.isalpha())	
    #                 plaintext = decrypt(ciphertext, key)

    #                 print("Plaintext: {}".format(plaintext))

    #                 askkey = False
    #             else:
    #                 print("Not a valid input")

    #         ask = False	
    
##############################################################################################

    ciphertext_unfiltered = input_cipher

   
    ciphertext = ''.join(x.lower() for x in ciphertext_unfiltered if x.isalpha())   

    askkey = True
    while askkey:
        torf = 'n'
        if torf == 'n':

            key_length=get_key_length(ciphertext)
            # print("Key length is most likely {}".format(key_length))

            key = get_key(ciphertext, key_length)
            plaintext = decrypt(ciphertext, key)

            print("Key: {}".format(key))
            # print("Plaintext: {}".format(plaintext))

            askkey = False
        elif torf == 'y':

            key_unfiltered = input("Enter key to decrypt with: ")
            key = ''.join(x.lower() for x in key_unfiltered if x.isalpha()) 
            plaintext = decrypt(ciphertext, key)

            # print("Plaintext: {}".format(plaintext))

            askkey = False
        else:
            print("Not a valid input")
            
##############################################################################################





if __name__ == '__main__':
    main()