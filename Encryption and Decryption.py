def main():
  run = True 
  while(run == True):
    print('')
    message =[] 
    print('Choose from the following menu: ')
    print('1. Encrypt a message')
    print('2. Decrypt a message')
    print('3. Quit')
    opt = int(input("Please enter your choice: "))
    if (opt==1):
      getInput(message)
      encrypt(message)
      wFile(message)
    elif (opt ==2):
      getInput(message)
      decrypt(message)
      wFile(message)
    elif (opt==3): 
      run = False
      break;
    else:
      print('Invalid. Please reenter your choice: ')

def getInput(message):
  try:
    file_name = str(input('Please input a file name: '))
    inputFile = open(file_name, "r")
    for line in inputFile:
      message.append(line.strip('\n'))
  except IOError:
    print ("File " + file_name + " cannot be opened")

def encrypt(message):
  new_message =[] 
  for i in range(0, len(message)):
    line = ""
    for j in range(0, len(message[i])):
      line+=chr(ord(message[i][j]) + 9) 
    if (i == len(message) -1):
      new_message.append(line)
    else:
      new_message.append(line + '\n')
  for i in range(0, len(message)):
    message[i] = new_message[i]
  print(message)

def decrypt(message):
  new_message =[] 
  for i in range(0, len(message)):
    line = ""
    for j in range(0, len(message[i])):
      line+=chr(ord(message[i][j])- 9)
    if (i == len(message)-1):
      new_message.append(line)
    else:
      new_message.append(line + '\n')
  for i in range(0, len(message)):
    message[i] = new_message[i]
  print(message)

def wFile(message):
  print('')
  print ('WARNING: by inputing the same file name, the content within that file will be overwritten with your new message')
  try:
    file_name = str(input('Please input a file name to store your new message: ')) 
    inputFile = open(file_name, "r+")
    for i in range(0, len(message), 1):
      inputFile.write(message[i])
    inputFile.close()
  except IOError:
    print ("File " + file_name + " cannot be opened")

main() 
