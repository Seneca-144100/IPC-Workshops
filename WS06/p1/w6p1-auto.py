import pyautogui as gui
import time

datafile = 'w6p1-inputs.txt'

# pause 3 seconds while you set focus to the terminal/console window:
print('Click on the terminal/console window where the automated keyboard data needs to be entered...')
print('NOTE: You have 5 seconds to do this!')
time.sleep(5)

# auto type test data from text file:
with open(datafile, 'r') as tst:
    time.sleep(1)
    tst = tst.readlines()
    for i in range(0, len(tst), 1):
        print(tst[i])
        gui.typewrite(tst[i])
        # Uncomment next line to address slow terminal response
        #time.sleep(0.5)

print('Auto data input completed.')
