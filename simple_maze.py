def build_house():
  print("Please enter the house file: ")
  house_file = input()
  housefp = open(house_file, "r")
  myhouse = [] 
  line = housefp.readline()
  while line:
    myhouse.append(list(line))
    line = housefp.readline()
  housefp.close()
  return myhouse

def main():
  unlocked = [False, False, False, False, False]
  house = build_house()
  startrow = 1
  startcol = 3
  trow = startrow
  tcol = startcol
  num_treasures = 0
  for i in range (0, len(house)):
    for j in house[i]: 
      if (j == 't'):
        num_treasures += 1
  t_count = 0
  run = True
  print(" ")
  print_house(house, trow, tcol) 
  while (run == True):
    print("\nChoose with direction you want to go\n") 
    command = input('Enter n, s, w, e or q to quit the program: ')
    if(command == 'q'):
      print("You chose to end the program. Thank you for playing. Goodbye!")
      break;
    elif(command == 'n'):
      if (check_north(house, trow , tcol) == True):
        trow = startrow-1
    elif(command == 's'):
      if (check_south(house, trow , tcol) == True):
        trow= startrow+1
    elif(command == 'w'):
      if (check_west(house, trow , tcol) == True):
        tcol= startcol-1
    elif(command == 'e'):     
      if (check_east(house, trow , tcol) == True):
        tcol= startcol+1
    else:
      print ("Invalid input. Please reenter your choice: ")
  
    if(is_door(house, trow, tcol) == True):
      if (can_unlock(house, unlocked, trow, tcol) == False):
        print("You cannot go through the door... The door is locked and you do not have the key.")
        tcol = startcol
        trow = startrow
      else:
        print("\nYou unlocked the door.")
    elif (get_key(house, unlocked, trow, tcol) == True):
      print("\nYou found a key!")
    elif (get_treasure(house,trow, tcol) == True):
      t_count += 1
      print ("\nYou have found a treasure! You currently have " + str(t_count) + " treasure(s).")
    print(" ")
    print_house(house, trow, tcol) #call print_house function
    startcol = tcol
    startrow = trow
    if (t_count == num_treasures):
      print("\nCongratulation! You found all the treasures")
      run == False
      break;

def check_north(house, row, col):
  if(house[row-1][col] != '*'):
    return True
  elif (house[row-1][col] == '*'):
    print ("\nYou cannot go that way.")
    return False

def check_south(house, row, col):
  if(house[row+1][col] != '*'):
    return True
  elif (house[row+1][col] == '*'):
    print ("\nYou cannot go that way.")

def check_east(house, row, col):
  if(house[row][col+1] != '*'):
    return True
  elif (house[row][col+1] == '*'):
    print ("\nYou cannot go that way.")

def check_west(house, row, col):
  if(house[row][col-1] != '*'):
    return True
  elif (house[row][col-1] == '*'):
    print ("\nYou cannot go that way.")

def is_door(house, row, col):
  if (house[row][col] >= '5' and house[row][col] <= '9'):
    return True
  else:
    return False

def get_key(house, unlocked, row, col):
  if (house[row][col] >= '0' and house[row][col] <= '4'):
    unlocked[int(house[row][col])] = True
    house[row][col] = " "
    return True

def can_unlock(house, unlocked, row, col):
  if(unlocked[(int(house[row][col]) - 5)] == True):
    return True
  else:
    return False

def get_treasure(house, row, col):
  if (house[row][col] == 't'):
    house[row][col] = " "
    return True
  else:
    return False

import copy
def print_house(h,sr,sc):
  th = copy.deepcopy(h)
  th[sr][sc] = "@"
  for i in th:
    print(''.join(str(x) for x in i), end='')

main()

''' maze file input
***************
***       0   ********************************
***                                   6      *
***********   **************************     *
          *   *                         *    *
    ********5***************            *  t *
    *                      *            ******
    *        t         1   *
    ************************

'''
