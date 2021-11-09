import sys
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
            # breaks the ciphertext into sequences
            for j in range(0, len(ciphertext[i:]), guess_len):
                sequence += ciphertext[i+j]
                #print("sequence: ", sequence)
            ic_sum+=get_index_c(sequence)
        # obviously don't want to divide by zero
        if not guess_len==0:
            avg_ic=ic_sum/guess_len
        ic_table.append(avg_ic)

  
    best_guess = ic_table.index(sorted(ic_table, reverse = True)[0])
    second_best_guess = ic_table.index(sorted(ic_table, reverse = True)[1])
    
    if best_guess % second_best_guess == 0:
        return second_best_guess
    else:
        return best_guess


def main():
    key_length=get_key_length(cipher)
    print("Key length is most likely {}".format(key_length))
    
if __name__ == '__main__':
	cipher = sys.stdin.read().replace("\n", "").replace(" ", "").upper()
	main()