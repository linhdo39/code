def draw_hang_loser():
    print(" _________     \n")
    print("|         |    \n")
    print("|         0    \n")
    print("|        /|\   \n")
    print("|        / \   \n")
    print("|              \n")
    print("|              \n")

def draw_hang_head_body_legs_la():
    print(" _________     \n")
    print("|         |    \n")
    print("|         0    \n")
    print("|         |\   \n")
    print("|        / \   \n")
    print("|              \n")
    print("|              \n")

def draw_hang_head_body_legs():
    print(" _________     \n")
    print("|         |    \n")
    print("|         0    \n")
    print("|         |    \n")
    print("|        / \   \n")
    print("|              \n")
    print("|              \n")


def draw_hang_head_body_ll():
    print(" _________     \n")
    print("|         |    \n")
    print("|         0    \n")
    print("|         |    \n")
    print("|          \   \n")
    print("|              \n")
    print("|              \n")   

def draw_hang_head_body():
    print(" _________     \n")
    print("|         |    \n")
    print("|         0    \n")
    print("|         |    \n")
    print("|              \n")
    print("|              \n")
    print("|              \n")

def draw_hang_head():
    print(" _________     \n")
    print("|         |    \n")
    print("|         0    \n")
    print("|              \n")
    print("|              \n")
    print("|              \n")
    print("|              \n")

def draw_hang_scaffold():
    print(" _________     \n")
    print("|         |    \n")
    print("|              \n")
    print("|              \n")
    print("|              \n")
    print("|              \n")
    print("|              \n")

def draw_hangman(state):
  if state == 0:
    draw_hang_scaffold()
  elif state == 1:
    draw_hang_head()
  elif state == 2:
    draw_hang_head_body()
  elif state == 3:
    draw_hang_head_body_ll()
  elif state == 4:
    draw_hang_head_body_legs()
  elif state == 5:
    draw_hang_head_body_legs_la()
  elif state == 6:
    draw_hang_loser()
    
def blanks_gone(s):
  if (s.find('_') == -1):
    return True
  else:
    return False

def replace_all(orig, working, ch):
  done = False
  count = 0
  #loop to replace the blank space with the charater that user entered
  while not done:
    idx = orig.find(ch)
    if idx != -1:
      count = count + 1
      orig = orig[:idx] + "_" + orig[idx+1:]
      working = working[:idx] + ch + working[idx+1:]
    else:
      done = True
  return count != 0, orig, working; #return values 

def main():
  import random; 
  state = 0 
  losing_state = 6
  sentence ="" 
  inputFile = open("word.txt","r")
  word = [] 
  for line in inputFile:
    word.append(line.strip('\n'))
  i = random.randint(0, len(word))
  sentence = word[i]
  sentence = sentence.lower() 
  place = "" 
  for character in range (0,len(sentence),1):
    place += "_"
  winner = False #signal when the program will end
  while(winner == False):
    draw_hangman(state) #call draw_hangman function
    print("There are " + str(len(sentence)) + " places") 
    print (place) 
    user_input = str(input("Enter a character: "))
    success, sentence, place = replace_all(sentence, place, user_input) 
    if (success == 0):
      state +=1
    if (state == losing_state):
      break;
    if(blanks_gone(place) == True):
      winner = True
  
  draw_hangman(state)
  
  if (winner==True):
    print("The word is " + place.strip(" "))
    print("Congrats! You win!")
  else:
    print("The word is " + word[i].lower())
    print("Sorry, you lost :-(")

main() 
