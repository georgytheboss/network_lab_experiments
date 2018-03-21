# import time
# a=time.time()

import smtplib
import csv

fromaddr = 'vigneshhari@ieee.org'			#Enter your from address here


with open('at.csv', 'r') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=',')
    temp = 0
    for row in spamreader:
        if(row[0].strip() == "Timestamp"):continue
        print("yes " + row[1] + " " + str(temp))
        toaddrs  = row[2]		#Enter recepient address here
        name = row[1]
        psswd = row[5]
        msg ="""Subject: Code It Out
        
body
""".format(name,toaddrs,psswd).encode('utf-8').strip()
        print(msg)
        try:
            username = fromaddr
            password = 'vEnter Password'					#Enter your password here
            server = smtplib.SMTP('smtp.gmail.com:587')
            server.starttls()
            server.login(username,password)
            server.sendmail(fromaddr, toaddrs, msg)
            server.quit()
        except():
            print("Error at id " + name)
        # print time.time() - a